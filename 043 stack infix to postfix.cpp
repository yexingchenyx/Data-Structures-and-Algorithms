#define IGNORE_MAIN
#include "040 stack dynamic array.cpp"
#undef IGNORE_MAIN
#include <iostream>
#include <string>
#include <set>
#include <map>

/**
 * infix        prefix      postfix
 * A+B          +AB         AB+
 * A+B-C        -+ABC       AB+C-
 * (A+B)*C-D    -*+ABCD     AB+C*D-
 */


std::string InfixToPostfix(const std::string& str) {
    std::set<char> operators = {'+', '-', '*', '/', '(', ')'};
    std::map<char, int> operatorPriority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 3}, {')', 3}};
    std::string rnt;

    DynArrayStack<char> stack;

    for (char a : str) {
        if (!operators.count(a)) {
            rnt.push_back(a);
        } else if (a == ')') {
            char b = stack.Pop();
            while (b != '(')
            {
                rnt.push_back(b);
                b = stack.Pop();
            }
        } else {
            while (true) {
                if (stack.IsEmpty())
                    break;
                
                char b = stack.Pop();

                if (b == '(') {
                    stack.Push(b);
                    break;
                }

                if (operatorPriority[b] < operatorPriority[a]) {
                    stack.Push(b);
                    break;
                }
                
                rnt.push_back(b);
            }
            stack.Push(a);
        } 
    }

    while (!stack.IsEmpty())
    {
        rnt.push_back(stack.Pop());
    }
    
    return rnt;
}


int main(int argc, char** argv) {
    std::string str = "A+B";
    std::cout << str << ": " << InfixToPostfix(str) << std::endl;

    str = "A+B-C";
    std::cout << str << ": " << InfixToPostfix(str) << std::endl;

    str = "(A+B)*C-D";
    std::cout << str << ": " << InfixToPostfix(str) << std::endl;

    str = "A*B-(C+D)+E";
    std::cout << str << ": " << InfixToPostfix(str) << std::endl;
}