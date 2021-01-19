#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// We have two stacks:
// 1 - an operator that is not bound to operands (+, -, etc.)
// 2 - a Operand stack for all operands (Variable, Constant, Unary/Binary expression)
// test on server

typedef struct TreeNode* TreeNodePtr;

// ********** OPERATOR **************
typedef enum {LeftToRight, RightToLeft} Associativity;
typedef enum {Unary, Binary} Arity;
typedef struct Operator {
    int precedence;     // how important the operator is, EX: '+' is less than '*'
    int arity;          // Binary or Unary
    int associativity;  // whether we evaluate it LTR ('+') or RTL ('='). LTR = 0
    char *string;       // helper for printing it
    char code;          // another helper for printing
} Operator;
Operator U_Positive     =    {.precedence = 15*2, .associativity = RightToLeft, .arity=Unary, .string="UNARY(+)", .code='+'};
Operator U_Negative     =    {.precedence = 15*2, .associativity = RightToLeft, .arity=Unary, .string="UNARY(-)", .code='-'};
Operator B_Plus         =    {.precedence = 12*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(+)", .code='+'};
Operator B_Minus        =    {.precedence = 12*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(-)", .code='-'};
Operator B_Times        =    {.precedence = 13*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(*)", .code='*'};
Operator B_DividedBy    =    {.precedence = 13*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(/)", .code='/'};


#define MAX_OPERATOR_STACK 100
Operator *OperatorStack[MAX_OPERATOR_STACK];
int operator_stack_size = 0;
Operator *LastOperator;
Operator *CurrentOperator;


void print_operator_stack()
{
    printf("Length: %d | OperatorStack: [", operator_stack_size);
    for (int i=0; i < operator_stack_size; i++) {
        printf("%s", OperatorStack[i]->string);
        if (i != (operator_stack_size-1)) printf(", ");
    }
    putchar(']');
}

void push_to_operator_stack(Operator *operator)
{
    // check max length
    if (operator_stack_size == MAX_OPERATOR_STACK) {
        printf("Operand Stack limit reached. Exiting!");
        exit(EXIT_FAILURE);
    }

    // push to stack (index = size) then increment
    OperatorStack[operator_stack_size] = LastOperator = operator;
    operator_stack_size ++;
}

Operator* pop_operator_stack()
{
    // check to make sure there's something on the stack
    if (operator_stack_size == 0) {
        printf("Nothing to pop on the stack\n");
        exit(EXIT_FAILURE);
    }

    // pop stack and decrement
    Operator *operator = OperatorStack[operator_stack_size - 1];
    operator_stack_size --;
    LastOperator = OperatorStack[operator_stack_size - 1];
    return operator;

}


// ********** OPERAND / TREE_NODE **************
typedef enum {VariableType, ConstantType, UnaryExpressionType, BinaryExpressionType} TreeNodeType;

typedef struct Variable {
    char value; 
} Variable;

typedef struct Constant {
    char value; // '1', '2', etc. Will obviously change later 
} Constant;

typedef struct UnaryExpression {
    Operator* type;
    TreeNodePtr child ;
} UnaryExpresion;

typedef struct BinaryExpression {
    Operator* type;
    TreeNodePtr left; // Operand*
    TreeNodePtr right; // Operand*
} BinaryExpression;

typedef struct Operand { // OperandTreeNode
    TreeNodeType type;
    union {
        Variable variable; 
        Constant constant; 
        UnaryExpresion unary;
        BinaryExpression binary;
    };
} Operand;


#define MAX_OPERAND_STACK 100
Operand *TreeNodeOperandStack[MAX_OPERAND_STACK];
int operand_stack_size = 0;

// FUNCTIONS: TODO
// 1. reduce_operand

void _print_operand(Operand* operand)
{
    // this is tricky within a union -- MAKE SURE ERROR CHECKING IS CORRECT!!
    switch (operand->type) {
        case VariableType:
            printf("VARIABLE('%c')", operand->variable.value);
            break;
        case ConstantType:
            printf("CONSTANT(%c)", operand->constant.value);
            break; // commenting this out causes a segfault -- why? ***** HOW TO DEBUG THESE?
        case UnaryExpressionType:
            // UNARY_EXPRESSION(+, VARIABLE('a'))
            printf("UNARY_EXPRESSION(%c, ", operand->unary.type->code);
            _print_operand((Operand*) (operand->unary.child));
            printf(")");
        case BinaryExpressionType:
            // BINARY_EXPRESSION(+, CONSTANT(4), VARIABLE('c'))
            printf("BINARY_EXPRESSION(%c, ", operand->binary.type->code);
            _print_operand((Operand*) (operand->binary.left));
            printf(", ");
            _print_operand((Operand*) (operand->binary.right));
            printf(")");
    }
}

void print_operand_stack() 
{

    printf("Length: %d | OperandStack:  [", operand_stack_size+1);
    for (int i=0; i < operand_stack_size; i++) {
        Operand* operand = TreeNodeOperandStack[i];
        _print_operand(operand);
        if (i != operand_stack_size-1) printf(", ");
    }
    printf("]\n");
};

void push_to_operand_stack(Operand *operand)
{
    
    // make sure we have space
    if (operand_stack_size == MAX_OPERAND_STACK) {
        printf("Operand Stack limit reached. Exiting!");
        exit(EXIT_FAILURE);
    }

    // Add the character/operand to the stack at the next index position
    TreeNodeOperandStack[operand_stack_size] = operand;
    operand_stack_size ++;
    return;

}


void reduce(Operator *CurrentOperator) {
    printf("*** Current Operator: %s ***\n", CurrentOperator->string);
}
void reduce_or_push_to_operator_stack(Operator* CurrentOperator)
{
    // Compare to previous
    // 1. Push Operator to stack if precedence of current operator is higher a+b*...
    // 2. Reduce if precedence of previous hierarchy is higher: a*b+...
    int current_precedence, last_precedence;
    current_precedence  = CurrentOperator->precedence + (CurrentOperator->associativity == RightToLeft? 1 : 0);

    last_precedence = LastOperator ? LastOperator->precedence : 0;
    if (last_precedence && LastOperator->associativity == LeftToRight)
        last_precedence ++;
    printf("\nPrevious Operator: %s (%d)\nCurrent Operator: %s (%d)\n",
                LastOperator ? LastOperator->string: "N/A", last_precedence,
                CurrentOperator->string, current_precedence
    );

    if (!operator_stack_size) {
        printf("CASE 1. Stack is empty -- Pushing to operator stack!\n");
        push_to_operator_stack(CurrentOperator);

    } else if (current_precedence > last_precedence) {
        printf("CASE 2. Current precedence is higher than previous -- Pushing to operator stack!\n");
        push_to_operator_stack(CurrentOperator);

    } else {
        printf("CASE 3. Previous precedence is higher -- Reduce!\n");
        reduce(CurrentOperator);
    }


};


Operand* pop_operand_stack()
{

    // Make sure we have something on the stack to pop
    // We use -1 to mean the stack has nothing there (i.e., the 0-th element is non-existent)
    if (operand_stack_size == 0) {
        printf("Nothing to pop. Exiting!");
        exit(EXIT_FAILURE);
    }

    // Get the character at the current index position and decrement index
    Operand *operand = TreeNodeOperandStack[operand_stack_size-1];
    operand_stack_size --;
    return operand;

}



int main(void) {

    const char *input = "-a+b+-c*+d-e+1";
    char character;
    int position = 0;
    Arity state = Unary;
    printf("Expression: %s\n", input);

    while ((character = input[position]) != 0) {

        // Recognize a Variable [a-z]{1}
        if (isalpha(character)) {
            Operand *variable_node = calloc (1, sizeof(Operator));
            variable_node->type = VariableType;
            variable_node->variable.value = character;
            push_to_operand_stack(variable_node);
            position += 1;
            state = Binary;
            continue;
        };

        // Recognize a Constant [0-9]{1}
        if (isdigit(character)) {
            Operand *constant_node = calloc (1, sizeof(Operator));
            constant_node->type = ConstantType;
            constant_node->constant.value = character;
            push_to_operand_stack(constant_node);
            position += 1;
            state = Binary;
            continue;
        }

        // Recognize the Unary types [+-*/]
        if (state == Unary) {
            // CurrentOperator = calloc(1, sizeof(Operator));
            switch (character) {
                case '+':
                    // *CurrentOperator = U_Positive;
                    reduce_or_push_to_operator_stack(&U_Positive);
                    position += 1;
                    continue;
                case '-':
                    reduce_or_push_to_operator_stack(&U_Negative);
                    // push_to_operator_stack(&U_Negative);
                    position += 1;
                    continue;
            }
        }

        // Recognize the Binary types [+-*/]
        if (state == Binary) {
            switch (character) {
                case '+':
                    reduce_or_push_to_operator_stack(&B_Plus);
                    position += 1;
                    state = Unary;
                    continue;
                case '-':
                    reduce_or_push_to_operator_stack(&B_Minus);
                    position += 1;
                    state = Unary;
                    continue;
                case '*':
                    reduce_or_push_to_operator_stack(&B_Times);
                    position += 1;
                    state = Unary;
                    continue;
                case '/':
                    reduce_or_push_to_operator_stack(&B_DividedBy);
                    position += 1;
                    state = Unary;
                    continue;
            }
        }

        


        position += 1;

    }

    print_operand_stack();
    print_operator_stack();



};
