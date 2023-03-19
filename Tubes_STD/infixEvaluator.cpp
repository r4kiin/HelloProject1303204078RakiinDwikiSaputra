#include "infixEvaluator.h"


// Fungsi ini untuk menentukan prioritas urutan operator
int precedence(char op) {
  if (op == '+' || op == '-') {
    return 1;
  } else if (op == '*' || op == '/') {
    return 2;
  } else {
    return 0;
  }
}
// Fungsi untuk mengenali bahwa masukan char itu berupa operator atau bukan
bool isOperator(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}


// Fungsi ini untuk menerapkan operator yang sesuai kepada dua operand
int applyOp(int leftOperand, int rightOperand, char op) {
  switch (op) {
    case '+':
      return leftOperand + rightOperand;
    case '-':
      return leftOperand - rightOperand;
    case '*':
      return leftOperand * rightOperand;
    case '/':
      return leftOperand / rightOperand;
    default:
      return 0;
  }
}

// Fungsi ini akan mengembalikan string hasil konversi dari infix ke postfix
string infix(stack &operandStack, string infixExpression){
    string postfixExpression;
    for (char ch : infixExpression) {
    if (ch >= '0' && ch <= '9') {
      postfixExpression += ch;
    } else if (ch == '(') {
      adr P = new elm;
      info(P).ekspresi = ch;
      pushStack(operandStack, P);
    } else if (ch == ')') {
      while (!emptyStack(operandStack) && info(top(operandStack)).ekspresi != '(') {
        postfixExpression += info(top(operandStack)).ekspresi;
        popStack(operandStack);
      }
      if (emptyStack(operandStack) || info(top(operandStack)).ekspresi != '(') {
        cout << "Error: Invalid expression\n";
        return "1";
      }
      popStack(operandStack);
    } else if (isOperator(ch)) {
      while (!emptyStack(operandStack) && precedence(ch) <= precedence(info(top(operandStack)).ekspresi)) {
        postfixExpression += info(top(operandStack)).ekspresi;
        popStack(operandStack);
      }
      adr P = new elm;
      info(P).ekspresi = ch;
      pushStack(operandStack, P);
    }
  }

    while (!emptyStack(operandStack)) {
        if (info(top(operandStack)).ekspresi == '(' || info(top(operandStack)).ekspresi == ')') {
          cout << "Error: Invalid expression\n";
          return "1";
        }
    postfixExpression += info(top(operandStack)).ekspresi;
    popStack(operandStack);
  }
  return postfixExpression;
}


// Fungsi ini akan melakukan perhitungan sesuai urutan postfix
void postfix(stack &operandStack, string postfixExpression){
    for (char ch : postfixExpression) {
        if (ch >= '0' && ch <= '9') {
          adr P = createItem(ch - '0');
          pushStack(operandStack, P);
        } else if (isOperator(ch)) {
          int rightOperand = info(top(operandStack)).ekspresi;
          popStack(operandStack);
          int leftOperand = info(top(operandStack)).ekspresi;
          popStack(operandStack);
          adr P = createItem(applyOp(leftOperand, rightOperand, ch));
          pushStack(operandStack, P);
        }
    }
}
