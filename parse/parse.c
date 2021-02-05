#include "common.h"
#include "operator.h"
#include "operand.h"


bool reduce(Operator *current_operator, OperatorStack *opt_stack, OperandStack *opd_stack)
{
    if (!opt_stack->size) return false;

    bool was_reduced = false;
    Operator* previous_operator = opt_stack->top(opt_stack);

    // Adjusted precedences based on associativity
    // If current operator is NULL, we can treat it as end of expression / right precedence = 0
    int left_precedence=-1, right_precedence = current_operator? current_operator->precedence : 0;
    if (current_operator->associativity == RightToLeft) right_precedence ++;
    printf("Left precedence: %d | Right precedence: %d\n", left_precedence, right_precedence);
    printf("Current Operator: %s | Previous Operator: %s\n", current_operator->string, previous_operator->string);

    do {

        left_precedence = (previous_operator->associativity == LeftToRight) ? previous_operator->precedence + 1 : previous_operator->precedence;
        if (right_precedence > left_precedence) break;

        // do the actual pop + push
        const Operator *opt = opt_stack->pop(opt_stack);
        if (previous_operator->arity == Unary) {
            Operand *child = opd_stack->pop(opd_stack);
            Operand *opd = create_operand_from_expression(opt, child, NULL);
            opd_stack->push(opd_stack, opd);
        } else  {   // Binary (for now)
            // order of pops is important for Left/Right children
            Operand *right = opd_stack->pop(opd_stack);
            Operand *left  = opd_stack->pop(opd_stack);
            Operand *opd = create_operand_from_expression(opt, left, right);
            opd_stack->push(opd_stack, opd);
        }

    } while (previous_operator = opt_stack->top(opt_stack));

    return was_reduced;
}

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

  {
    // 3. test reduce
    OperatorStack  *opt_stack = create_operator_stack(stack_size, is_resizable);
    OperandStack   *opd_stack = create_operand_stack(stack_size, is_resizable);
    opt_stack->push(opt_stack, &U_Negative);
    opd_stack->push(opd_stack, create_operand_from_value(VariableType, 'a'));
    Operator *current_operator = &B_Plus;
    reduce(current_operator, opt_stack, opd_stack);
    opt_stack->print(opt_stack);
    printf("\n*****\n");
    opd_stack->print(opd_stack);
    putchar('\n');
  }

}
