#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T>* ptrdiff; // prev ^ next, 前节点地址与后节点地址的异或
};

/**
 *  
 * 异或，相同为0， 不同为1
 * 异或1反转，异或0不变
 * 
 * 1 ^ 1 = 0
 * 0 ^ 1 = 1
 * 1 ^ 0 = 1
 * 0 ^ 0 = 0
 * 
 * X ^ X = 0
 * X ^ 0 = X
 * X ^ Y = Y ^ X
 * (X ^ Y) ^ Z = X ^ (Y ^ Z)
 * 
 * (X ^ Y) ^ Y = X ^ (Y ^ Y) = X ^ 0 = X
 * 
 */

int main(int argc, char** argv) {

}


