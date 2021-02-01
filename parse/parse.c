#include "common.h"
#include "operator.h"


// RETURN: AST --> Single Operand ?
void parse(const char* const input_str) 
{

    printf("Parsing expression: |%s|\n", input_str);
    size_t opt_stack_size = 10;
    bool is_resizable = true;
    OperatorStack *opt_stack, *self;
    opt_stack = self = create_operator_stack(opt_stack_size, is_resizable);
    opt_stack->push(self, &U_Negative);
    opt_stack->pop(self);
    opt_stack->push(self, &B_Times);
    opt_stack->push(self, &B_Plus);
    opt_stack->print(self);
    /* printf("The '+' can be either %s or %s\n", U_Positive.string, B_Plus.string); */

}
