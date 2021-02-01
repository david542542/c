// operator.h

#ifndef __OPERATOR_H__
#define __OPERATOR_H__
#define MAX_OPERATOR_STACK 100

typedef enum {LeftToRight, RightToLeft} Associativity;
typedef enum {Unary, Binary} Arity;

typedef struct Operator {
    int precedence;     // multiple of two so we can add on the associativity to the last bit
    int arity;
    int associativity;
    char *string;        // helper for printing the operator, for example, "BINARY(-)"
    char code;          // helpful for debugging, for example, '+'
} Operator;


// Shared operators
#ifdef  __OPERATOR_C__
    const Operator U_Positive     =    {.precedence = 15*2, .associativity = RightToLeft, .arity=Unary, .string="UNARY(+)", .code='+'};
    const Operator U_Negative     =    {.precedence = 15*2, .associativity = RightToLeft, .arity=Unary, .string="UNARY(-)", .code='-'};
    const Operator B_Plus         =    {.precedence = 12*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(+)", .code='+'};
    const Operator B_Minus        =    {.precedence = 12*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(-)", .code='-'};
    const Operator B_Times        =    {.precedence = 13*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(*)", .code='*'};
    const Operator B_DividedBy    =    {.precedence = 13*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(/)", .code='/'};
#else
    extern const Operator U_Negative;
    extern const Operator B_Plus;
    extern const Operator B_Minus;
    extern const Operator B_Times;
    extern const Operator B_DividedBy;
#endif


// OperatorStack
typedef struct OperatorStack OperatorStack;
typedef struct OperatorStack {
    bool       is_resizable;
    size_t     size;
    size_t     max;
    const Operator** data;

    //              (*init) done with the `create_operator_stack` function
    void            (*delete)(OperatorStack* stack);

    const Operator* (*top)   (OperatorStack* stack);
    void            (*print) (OperatorStack* stack);
    const Operator* (*pop)   (OperatorStack* stack);                              // return Operator or NULL if nothing to pop
    bool            (*push)  (OperatorStack* stack, const Operator* operator);   // return 1 if successfully pushed. will auto-resize if is_resizable


} OperatorStack;

OperatorStack* create_operator_stack(size_t start_size, bool is_resizable);


#endif /* ifndef __OPERATOR_H__ */
