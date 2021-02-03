// operand.c
#include "common.h"
#include "operand.h"

void           delete_operand_stack(OperandStack* stack);
const Operand* peek_operand_stack  (OperandStack* stack);
bool           push_operand_stack  (OperandStack* stack, const Operand* operand);
const Operand* pop_operand_stack   (OperandStack* stack);
void           print_operand_stack (OperandStack* stack);

void           print_operand       (Operand* operand);
void           delete_operand      (Operand* operand);

const Operand* create_operand_from_expression(const Operator* operator, const Operand* first, const Operand* second)
{
    Operand* operand = malloc(sizeof(Operand));
    if (!second) {
        operand->type = UnaryExpressionType;
        operand->unary.type  = (Operator*) operator;
        operand->unary.child = (Operand*) first;
    } else {
        operand->type = BinaryExpressionType;
        operand->binary.type  = (Operator*) operator;
        operand->binary.left  = (Operand*) first;
        operand->binary.right = (Operand*) second;
    }
    operand -> delete = delete_operand;
    operand -> print  = print_operand;
    return operand;
};

const Operand* create_operand_from_value(const OperandType type, const char value)
{
    Operand* operand = malloc(sizeof(Operand));
    operand -> type = type;
    // note, currently they take the same storage location in the union
    // so could do with a single assignment for both, but will change in the future
    // and also simpler to read and understand
    if (operand->type == VariableType)
        operand->variable.value = value;
    else
        operand->constant.value = value;

    operand -> delete = delete_operand;
    operand -> print  = print_operand;
    return operand;

};

void delete_operand(Operand* operand) 
{
    free(operand);
}

OperandStack* create_operand_stack(size_t size, bool is_resizable) {

    // boilerplate to set up the struct and its handlers
    OperandStack* stack  = malloc(sizeof(OperandStack));
    stack->is_resizable  = is_resizable;
    stack->max           = size;
    stack->size          = 0;

    stack->delete        = delete_operand_stack;
    stack->top           = peek_operand_stack;
    stack->print         = print_operand_stack;

    stack->push          = push_operand_stack;
    stack->pop           = pop_operand_stack;

    /* // now create the actual stack with the specified size */
    stack->data         = malloc(size * sizeof(Operand*));

    return stack;
}


void delete_operand_stack(OperandStack* stack) 
{
    free(stack->data);
    free(stack);
}

const Operand* peek_operand_stack(OperandStack* stack)
{
    if (!stack->size) 
        return NULL;
    else
        return stack->data[stack->size-1];
}

const Operand* pop_operand_stack(OperandStack* stack)
{
    if (!stack->size)
        return NULL;
    else
        stack->size--;
        return stack->data[stack->size -1];
}

bool push_operand_stack(OperandStack* stack, const Operand* operand)
{
    //push if there's space
    if (stack->size < stack->max) {
        stack->data[++stack->size-1] = operand;
        return true;
    }
    else if (!stack->is_resizable) {
        return false;
    } else {
        // increase by x2 for now (note: we increase the size of the data member, not the OperandStack itself
        size_t new_stack_size = sizeof(Operand*) * stack->size * 2;
        stack->data = realloc(stack->data, new_stack_size);
        if (!stack->data)
            return false;
        stack->data[++stack->size -1] = operand;
        return true;
    }

}

void print_operand(Operand* operand)
{
    switch (operand->type) {
        case VariableType:
            printf("VARIABLE('%c')", operand->variable.value);
            break;
        case ConstantType:
            printf("CONSTANT(%c)", operand->constant.value);
            break;
        case UnaryExpressionType: {
            printf("UNARY_EXPRESSION(%c, ", operand->unary.type->code);
            Operand* child = operand->unary.child;
            child->print(child);
            putchar(')');
            break;
        }
        case BinaryExpressionType: {
            Operand *left, *right;
            left = operand->binary.left;
            right = operand->binary.right;
            printf("BINARY_EXPRESSION(%c, ", operand->binary.type->code);
            left->print(left);
            putchar(','); putchar(' ');
            right->print(right);
            putchar(')');
            break;
        }
        default:
            printf("Invalid OperandType found: %d\n", operand->type);
            exit(EXIT_FAILURE);
    }

}
void print_operand_stack(OperandStack* stack)
{
    printf("Length: %zu | OperandStack:  [", stack->size);
    for (int i=0; i < stack->size; i++) {
        Operand* operand = (Operand*) stack->data[i];
        if (i != 0) printf(", ");
        operand->print(operand);
    }
    putchar(']');
}


