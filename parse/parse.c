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
    self->push(self, &B_Times);

    // const test
    self->data[1] = (Operator*) 1234;   // ok, can change the pointer address of the Data array --> good because will be pushing/popping
    self->data = (Operator**) 1234;     // ok, can change the address of the pointer itself     --> good because want to be able to resize it
    self->data[0]->arity=5;                // don't allow because we want the Operators to be static/singletons so 

    /* self->pop(self); */
    /* self->push(self, &B_Times); */
    /* self->push(self, &B_Plus); */
    /* self->print(self); */
    /* self->delete(self); */

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
