// operator.h

#ifndef __OPERATOR_H__
#define __OPERATOR_H__

typedef enum {LeftToRight, RightToLeft} Associativity;
typedef enum {Unary, Binary} Arity;

const typedef struct Operator {
    int precedence;         // multiple of two so we can add on the associativity to the last bit
    int arity;
    int associativity;
    char *string;           // helper for printing the operator, for example, "BINARY(-)"
    char code;
} Operator;

// Shared operators
// These are singletons and const
extern Operator U_Negative;
extern Operator B_Plus;
extern Operator B_Minus;
extern Operator B_Times;
extern Operator B_DividedBy;
#ifdef  __OPERATOR_C__
    Operator U_Positive     =    {.precedence = 15*2, .associativity = RightToLeft, .arity=Unary, .string="UNARY(+)", .code='+'};
    Operator U_Negative     =    {.precedence = 15*2, .associativity = RightToLeft, .arity=Unary, .string="UNARY(-)", .code='-'};
    Operator B_Plus         =    {.precedence = 12*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(+)", .code='+'};
    Operator B_Minus        =    {.precedence = 12*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(-)", .code='-'};
    Operator B_Times        =    {.precedence = 13*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(*)", .code='*'};
    Operator B_DividedBy    =    {.precedence = 13*2, .associativity = LeftToRight, .arity=Binary,.string="BINARY(/)", .code='/'};
#endif

// OperatorStack
typedef struct OperatorStack OperatorStack;
typedef struct OperatorStack {

    // values
    bool       is_resizable;
    size_t     size;
    size_t     max;

    // data
    const Operator** data;      // (const Operator) is the type, declare data as a (mutable) pointer to a (mutable) array of pointers to (const Operator)
                                // why mutable pointer? (1) could re-alloc the pointed-to data if need to increase the size;	
                                //                      (2) could push/pop from the stack so need to point to new (const Operators)	

    // non-modifying functions
    const Operator* (*top)   (const OperatorStack* stack);
    void            (*print) (const OperatorStack* stack);

    // modifying functions
    void            (*delete)(OperatorStack* stack);
    const Operator* (*pop)   (OperatorStack* stack);
    bool            (*push)  (OperatorStack* stack, const Operator* operator);

} OperatorStack;

OperatorStack* create_operator_stack(size_t start_size, bool is_resizable);


#endif /* ifndef __OPERATOR_H__ */
