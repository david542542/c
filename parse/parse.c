#include "common.h"
#include "operator.h"
#include "operand.h"


void parse(const char* const input_str) 
{

    printf("Parsing expression: |%s|\n", input_str);

    size_t stack_size = 10;
    bool is_resizable = true;

    // enclose in braces so can re-use variable names such as `self` for testing
  {
    // 1. test OperatorStack
    OperatorStack  *self = create_operator_stack(stack_size, is_resizable);
    self->push(self, &U_Negative);
    self->pop(self);
    self->push(self, &B_Times);
    self->push(self, &B_Plus);
    self->print(self);
    self->delete(self);
    printf("\n*****\n");
  }

  {
    // 2. test OperandStack
    OperandStack *self = create_operand_stack(stack_size, is_resizable);
    Operand* op = create_operand_from_value(VariableType, 'a');
    self->push(self, op);
    Operand *op2 = create_operand_from_expression(
        &B_Times,
        create_operand_from_value(VariableType, 'a'),
        create_operand_from_value(ConstantType, '1')
    );
    self->push(self, op2);
    self->print(self);
    self->pop(self);
    self->delete(self);
    printf("\n*****\n");
  }

}
