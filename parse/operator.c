// operator.c
#include "common.h"
#define __OPERATOR_C__
#include "operator.h"


void            delete_operator_stack(OperatorStack* stack);
const Operator* peek_operator_stack  (OperatorStack* stack);
void            print_operator_stack (OperatorStack* stack);
const Operator* pop_operator_stack   (OperatorStack* stack);
bool            push_operator_stack  (OperatorStack* stack, const Operator* operator);

// could also have these function pointers passed into the `create` function
static const OperatorStack_VTable vtable = {
    .delete = delete_operator_stack,

    .pop    = pop_operator_stack,
    .push   = push_operator_stack,
    .top    = peek_operator_stack,
    .print  = print_operator_stack,
};

OperatorStack* create_operator_stack(size_t size, bool is_resizable) {

    // boilerplate to set up the struct and its handlers
    OperatorStack* stack = malloc(sizeof(OperatorStack));
    stack->is_resizable  = is_resizable;
    stack->max           = size;
    stack->size          = 0;
    stack->vtable        = &vtable;

    /* // now create the actual stack with the specified size */
    stack->data         = malloc(size * sizeof(Operator*));


    return stack;
}

void delete_operator_stack(OperatorStack* stack) 
{
    free(stack->data);
    free(stack);
}

const Operator* peek_operator_stack(OperatorStack* stack)
{
    if (!stack->size) 
        return NULL;
    else
        return stack->data[stack->size-1];
}

const Operator* pop_operator_stack(OperatorStack* stack)
{
    if (!stack->size)
        return NULL;
    else
        stack->size--;
        return stack->data[stack->size -1];
}

bool push_operator_stack(OperatorStack* stack, const Operator* operator)
{

    //push if there's space
    if (stack->size < stack->max) {
        stack->data[++stack->size-1] = operator;
        return true;
    }
    else if (!stack->is_resizable) {
        return false;
    } else {
        // increase by x2 for now (note: we increase the size of the stack variable, not the OperatorStack itself
        size_t new_stack_size = sizeof(Operator*) * stack->size * 2;
        stack->data = realloc(stack->data, new_stack_size);
        if (!stack->data)
            return false;
        stack->data[++stack->size -1] = operator;
        return true;
    }
}

void print_operator_stack(OperatorStack* stack)
{
    printf("Length: %zu | OperatorStack: [", stack->size);
    for (int i=0; i < stack->size; i++) {
        printf("%s", stack->data[i]->string); // note that each operator has a string method 
        if (i != (stack->size-1)) printf(", ");
    }
    putchar(']');
}




/* void reduce_operator_stack(OperandStack* stack) */
/* { */
    /* // TODO */
/* } */

