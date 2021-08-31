#define IGNORE_MAIN
#include "040 stack dynamic array.cpp"
#undef IGNORE_MAIN
#include <iostream>
#include <string>


/**
 * infix        prefix      postfix
 * A+B          +AB         AB+
 * A+B-C        -+ABC       AB+C-
 * (A+B)*C-D    -*+ABCD     AB+C*D-
 */


std::string InfixToPostfix(const std::string& str) {
    return str;
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