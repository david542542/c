// 1 - const....
// 2 - array...
// 3 - multi-character token, 'symbol'

   * (~3-4 cycles) "strength reduction" --> doing less-intensive (in terms of cpu cycles) operations
 /  \
i    2
------------> often rewritten to an addition
   + (1 cycle)
 /  \
i    i
-----------> or possibly doing a left-shift 
  <<
 /  \
i    1

// useful on an actual type declaration, but not a param
for(int i=0, a[5]; i<len; i*=2) {
    x = a[i]*2; // 
           
            =                      =
          /   \                  /   \
        x       *              x      <<     (in-)        
              /  \                   /  \
             []    2                []    1
            /  \                   /  \ 
           a   i                  a   i
}
i*=2;


// operand.h
#ifndef __OPERAND_H__
#define __OPERAND_H__
#include "operator.h"

typedef enum {VariableType, ConstantType, UnaryExpressionType, BinaryExpressionType} OperandType;
typedef struct Operand Operand;

// variable      
typedef struct Variable {
    char        value;     // single-value for now
} Variable;

// constant
typedef struct Constant {
    char        value;     // single-value for now
} Constant;

// to edit the AST eventually we don't want to make the Unary/Binary structs const
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

    void (*print)  (Operand*);
    void (*delete) (Operand*);

} Operand;

const Operand* create_operand_from_value      (const OperandType type, const char value);
const Operand* create_operand_from_expression (const Operator* operator, const Operand* first, const Operand* second);


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
