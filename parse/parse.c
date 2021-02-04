#include "common.h"
#include "operator.h"
/* #include "operand.h" */


// RETURN: AST --> Single Operand ?
void parse(const char* const input_str) 
{

    printf("Parsing expression: |%s|\n", input_str);

    // 1. test OperatorStack
    size_t opt_stack_size = 10;
    bool is_resizable = true;
    OperatorStack *opt_stack, *self;
    opt_stack = self = create_operator_stack(opt_stack_size, is_resizable);
    /* const OperatorStackVTable *self_v = self->vtable; */
    /* self_v->push(self_v, &U_Negative); */
    /* opt_stack->pop(self); */
    /* opt_stack->push(self, &B_Times); */
    /* opt_stack->push(self, &B_Plus); */
    /* opt_stack->print(self); */
    /* opt_stack->delete(self); */

    /* // 2. test OperandStack -- ugh, cannot use `self` again since already declared with different type... */
    /* putchar('\n'); */
    /* OperandStack *opd_stack, *_self; */
    /* opd_stack = _self = create_operand_stack(8,^ true); */
    /* Operand *opd = (Operand*) create_operand_from_expression( */
        /* &B_Times, */
        /* create_operand_from_value(VariableType, 'a'), */
        /* create_operand_from_value(ConstantType, '1') */
    /* ); */

    /* _self->push(_self, opd); */
    /* _self->push(_self, create_operand_from_value(VariableType, 'b')); */
    /* _self->print(_self); */
    /* _self->pop(_self); */
    /* _self->delete(_self); */
    putchar('\n');

}
