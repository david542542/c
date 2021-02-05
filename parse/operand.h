// operand.h

#ifndef __OPERAND_H__
#define __OPERAND_H__
#include "operator.h"


// Operand
// - dynamic in case we want to optimize/factor later
typedef enum {VariableType, ConstantType, UnaryExpressionType, BinaryExpressionType} OperandType;
typedef struct Operand Operand;

typedef struct Variable {
    char        value;
} Variable;

typedef struct Constant {
    char        value;
} Constant;

typedef struct UnaryExpression {
    Operator*   type;
    Operand*    child;
} UnaryExpression;

typedef struct BinaryExpression {
    Operator*   type;
    Operand*    left;
    Operand*    right;
} BinaryExpression;

typedef struct Operand {
    OperandType type;
    union {
        Variable         variable; 
        Constant         constant; 
        UnaryExpression  unary;
        BinaryExpression binary;
    };

    void (*print)  (const Operand*);
    void (*delete) (Operand*);

} Operand;

Operand* create_operand_from_value      (OperandType type, char value);
Operand* create_operand_from_expression (const Operator* operator, Operand* first, Operand* second);

// OperandStack
// - will reduce down to an AST
typedef struct OperandStack OperandStack;
typedef struct OperandStack {
    bool            is_resizable;
    size_t          size;
    size_t          max;

    // data -- note: the Operand can change, the Pointer to Operand can change, and the base Pointer can as well.
    //         so everything here will be constant
    Operand** data;

    // non-modifying functions
    Operand* (*top)   (const OperandStack* stack);
    void     (*print) (const OperandStack* stack);

    // modifying functions
    void     (*delete)(OperandStack* stack);
    Operand* (*pop)   (OperandStack* stack);
    bool     (*push)  (OperandStack* stack, const Operand* operator);

} OperandStack;

OperandStack* create_operand_stack(size_t start_size, bool is_resizable);

#endif /* ifndef __OPERAND_H__ */
