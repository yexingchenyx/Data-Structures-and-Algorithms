#define IGNORE_MAIN
#include "040 stack dynamic array.cpp"
#undef IGNORE_MAIN
#include <iostream>

int PostfixEvaluation(const std::string& str) {
    return 0;
}


int main(int argc, char** argv) {
    std::string str = "A+B";
    std::cout << str << " = " << PostfixEvaluation(str) << std::endl;
}