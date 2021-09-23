#define IGNORE_MAIN
#include "040 stack dynamic array.cpp"
#undef IGNORE_MAIN
#include <iostream>
#include <set>


int PostfixEvaluation(const std::string& str) {
    std::set<char> operators = {'+', '-', '*', '/'};

    DynArrayStack<char> stack;

    for (char a : str) {
        if (!operators.count(a)) {
            stack.Push(a);
            continue;
        }

        int b = stack.Pop() - '0';
        int c = stack.Pop() - '0';
        int d = 0;

        if (a == '+')
            d = c + b;
        else if (a == '-')
            d = c - b;
        else if (a == '*')
            d = c * b;
        else if (a == '/')
            d = c / b;
        else
            throw "";

        stack.Push(d + '0');
    }

    return stack.Pop() - '0';
}


int main(int argc, char** argv) {
    std::string str = "123*+5-";
    std::cout << str << " = " << PostfixEvaluation(str) << std::endl;
}