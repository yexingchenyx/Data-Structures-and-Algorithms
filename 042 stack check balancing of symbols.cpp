#define IGNORE_MAIN
#include "040 stack dynamic array.cpp"
#undef IGNORE_MAIN
#include <iostream>
#include <string>
#include <set>
#include <map>


bool IsBalance(const std::string& str) {
    std::set<char> allSymbols = {'(', ')', '[', ']', '{', '}'};
    std::set<char> openingSymbols = {'(', '[', '{'};
    std::set<char> closingSymbols = {')', ']', '}'};
    std::map<char, char> pairSymbols = {{')', '('}, {']', '['}, {'}', '{'}};

    DynArrayStack<char> stack;
    
    for (char a : str) {
        if (!allSymbols.count(a)) {
            continue;
        } else if(openingSymbols.count(a)) {
            stack.Push(a);
        } else if (closingSymbols.count(a)) {
            if (stack.IsEmpty()) {
                return false;
            } else {
                if (pairSymbols[a] != stack.Pop()) {
                    return false;
                }
            }
        }
    }

    return stack.IsEmpty();
}


int main(int argc, char** argv) {
    std::string str = "(A+B)+(C-D)";
    std::cout << str << ": " << IsBalance(str) << std::endl; 

    str = "((A+B)+(C-D)";
    std::cout << str << ": " << IsBalance(str) << std::endl; 

    str = "((A+B)+[C-D])";
    std::cout << str << ": " << IsBalance(str) << std::endl; 

    str = "((A+B)+[C-D]}";
    std::cout << str << ": " << IsBalance(str) << std::endl; 
}