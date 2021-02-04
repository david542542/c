#include "common.h"
#include "operator.h"
/* #include "operand.h" */


void parse(const char* const input_str) 
{

    printf("Parsing expression: |%s|\n", input_str);

    // 1. test OperatorStack
    size_t opt_stack_size = 10;
    bool is_resizable = true;
    OperatorStack  *self = create_operator_stack(opt_stack_size, is_resizable);
    self->push(self, &U_Negative);
    self->pop(self);
    self->push(self, &B_Times);
    self->push(self, &B_Plus);
    self->print(self);
    self->delete(self);

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
