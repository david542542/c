// operand.c
#include "common.h"
#include "operand.h"

// Operand
void    print_operand   (const Operand* operand);
void    delete_operand  (Operand* operand);

void delete_operand(Operand* operand) 
{
    free(operand);
}

void print_operand(const Operand* operand)
{
    switch (operand->type) {
        case VariableType:
            printf("VARIABLE('%c')", operand->variable.value);
            break;
        case ConstantType:
            printf("CONSTANT(%c)", operand->constant.value);
            break;
        case UnaryExpressionType: 
          {
            printf("UNARY_EXPRESSION(%c, ", operand->unary.type->code);
            // what about const here?
            Operand* child = operand->unary.child;
            child->print(child);
            putchar(')');
            break;
          }
        case BinaryExpressionType: 
          {
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

Operand* create_operand_from_value(const OperandType type, char value)
{
    Operand* operand = malloc(sizeof(Operand));
    operand -> type = type;
    if (operand->type == VariableType)
        operand->variable.value = value;
    else
        operand->constant.value = value;

    operand -> delete = delete_operand;
    operand -> print  = print_operand;
    return operand;

};

Operand* create_operand_from_expression(const Operator* operator, Operand* first, Operand* second)
{
    Operand* operand = malloc(sizeof(Operand));
    if (!second) {
        operand->type = UnaryExpressionType;
        operand->unary.type  = operator;
        operand->unary.child = first; // child
    } else {
        operand->type = BinaryExpressionType;
        operand->binary.type  = operator;
        operand->binary.left  = first; // left
        operand->binary.right = second; // right
    }
    operand -> delete = delete_operand;
    operand -> print  = print_operand;
    return operand;
};



// OperandStack
Operand* peek_operand_stack  (const OperandStack* stack);
void     print_operand_stack (const OperandStack* stack);
bool     push_operand_stack  (OperandStack* stack, const Operand* operand);
Operand* pop_operand_stack   (OperandStack* stack);
void     delete_operand_stack(OperandStack* stack);

OperandStack* create_operand_stack(size_t size, bool is_resizable) {

    OperandStack* stack  = malloc(sizeof(OperandStack));
    stack->is_resizable  = is_resizable;
    stack->max           = size;
    stack->size          = 0;

    // functions
    stack->top           = peek_operand_stack;
    stack->print         = print_operand_stack;
    stack->push          = push_operand_stack;
    stack->pop           = pop_operand_stack;
    stack->delete        = delete_operand_stack;

    // data
    stack->data         = malloc(size * sizeof(Operand*));

    return stack;
}

void delete_operand_stack(OperandStack* stack) 
{
    free(stack->data);
    free(stack);
}

Operand* peek_operand_stack(const OperandStack* stack)
{
    if (!stack->size) 
        return NULL;
    else
        return stack->data[stack->size-1];
}

Operand* pop_operand_stack(OperandStack* stack)
{
    if (!stack->size)
        return NULL;
    else
        return stack->data[--stack->size];
}

bool push_operand_stack(OperandStack* stack, const Operand* operand)
{
    // Note: we don't modify Operand and so it can be const
    //       but in our assignment when pushing it to the stack, we need to add it as non-const
    if (stack->size < stack->max) {
        stack->data[++stack->size-1] = (Operand*) operand; 
        return true;
    }
    else if (!stack->is_resizable) {
        return false;
    } else {
        // increase by x2 for now
        size_t new_stack_size = sizeof(Operand*) * stack->size * 2;
        stack->data = realloc(stack->data, new_stack_size);
        if (!stack->data)
            return false;
        stack->data[++stack->size -1] = (Operand*) operand;
        return true;
    }
}

void print_operand_stack(const OperandStack* stack)
{
    printf("Length: %zu | OperandStack:  [", stack->size);
    for (int i=0; i < stack->size; i++) {
        Operand* operand = (Operand*) stack->data[i];
        if (i != 0) printf(", ");
        operand->print(operand);
    }
    putchar(']');
}


