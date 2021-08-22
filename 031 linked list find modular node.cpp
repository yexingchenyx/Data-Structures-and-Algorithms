#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN


template <typename T>
Node<T>* ModularNodeFromBegin(Node<T>** list, int k) {

    return *list;
}


int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};
    for (int i = 0; i < 20; ++i)
        Insert(list, i, i);

    int k = 3;
    printf("%d\n", ModularNodeFromBegin(list, k)->data);
}