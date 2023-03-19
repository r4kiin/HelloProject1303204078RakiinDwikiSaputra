#ifndef INFIXEVALUATOR_H_INCLUDED
#define INFIXEVALUATOR_H_INCLUDED

#include "stackHeader.h"
using namespace std;

int precedence(char op);
bool isOperator(char ch);
int applyOp(int leftOperand, int rightOperand, char op);
string infix(stack &operandStack, string infixExpression);
void postfix(stack &operandStack, string postfixExpression);

#endif // INFIXEVALUATOR_H_INCLUDED
