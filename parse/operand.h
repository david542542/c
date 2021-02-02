// operand.h
#ifndef __OPERAND_H__
#define __OPERAND_H__
#include "operator.h"

typedef struct Operand Operand;
typedef enum {VariableType, ConstantType, UnaryExpressionType, BinaryExpressionType} OperandType;

typedef struct Variable {
    char        value; 
} Variable;

typedef struct Constant {
    char        value;     // single-value for now
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
} Operand;


typedef struct OperandStack OperandStack;
typedef struct OperandStack {
    bool            is_resizable;
    size_t          size;
    size_t          max;
    const Operand** data; // data is a list of Operands: should it be Operand data[]? or Operand* data[]?

    //              (*init) done with the `create_operand_stack` function
    void            (*delete)(OperandStack* stack);

    const Operand*  (*top)   (OperandStack* stack);
    void            (*print) (OperandStack* stack);
    const Operand*  (*pop)   (OperandStack* stack);                              
    bool            (*push)  (OperandStack* stack, const Operand* operand);


} OperandStack;

OperandStack* create_operand_stack(size_t start_size, bool is_resizable);


#endif /* ifndef __OPERAND_H__ */