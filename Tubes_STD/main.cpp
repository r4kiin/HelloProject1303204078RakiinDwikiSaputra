#include "stackheader.h"
#include "infixEvaluator.h"
#include <iostream>
using namespace std;

int main() {
    stack operandStack;
    createStack(operandStack);
    // Menerima inputan string infix
    string infixExpression, postfixExpression;
    cout << "Enter infix expression: ";
    getline(cin, infixExpression);

    // Menyimpan hasil konversi infix -> postfix ke dalam variabel
    postfixExpression = infix(operandStack, infixExpression);
    cout << "Postfix expression: " << postfixExpression << '\n';

    // Melakukan perhitungan
    postfix(operandStack, postfixExpression);
    cout << "Result: " << int(info(top(operandStack)).ekspresi) << '\n';
    return 0;
}
