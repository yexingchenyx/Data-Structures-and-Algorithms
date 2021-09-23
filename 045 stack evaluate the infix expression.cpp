#define IGNORE_MAIN
#include "040 stack dynamic array.cpp"
#undef IGNORE_MAIN
#include <iostream>
#include <set>

int InfixEvaluation(const std::string& str) {
    DynArrayStack<int> operand_stack;
    DynArrayStack<char> operator_stack;

    for (char a : str) {

        if (a >= '0' && a<= '9') {
            operand_stack.Push(a - '0');
        } else if (a == '*' || a =='/') {
            operator_stack.Push(a);
        } else if (a == '+' || a == '-') {
            if (operator_stack.IsEmpty() ||
             operator_stack.Top() == '+' ||
              operator_stack.Top() == '-') {
                operator_stack.Push(a);
            } else {
                int b = operand_stack.Pop();
                int c = operand_stack.Pop();
                char d = operator_stack.Pop();
                if (d == '*')
                    operand_stack.Push(c * b);
                else if (d == '/')
                    operand_stack.Push(c / b);
                else
                    throw "";
                operator_stack.Push(a);
            }
        }
    }

    while (!operator_stack.IsEmpty())
    {
        int b = operand_stack.Pop();
        int c = operand_stack.Pop();
        char d = operator_stack.Pop();

        if (d == '+') {
            operand_stack.Push(c + b);
        } else if (d == '-') {
            operand_stack.Push(c - b);
        }
    }

    return operand_stack.Pop();
}


int main(int argc, char** argv) {
    std::string str = "2*3+1-5";
    std::cout << str << " = " << InfixEvaluation(str) << std::endl;
}