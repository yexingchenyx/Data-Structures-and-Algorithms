#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

/**
 * find n/k th element, where n is not known
 */
template <typename T>
Node<T>* FractionalNode(Node<T>** list, int k) {
    Node<T>* fractionalNode = *list;
    Node<T>* current = *list;
    int i = 0;
    while(current) {
        if (i % k == 0)
            fractionalNode = fractionalNode->next;
        current = current->next;
        i++;
    }

    return fractionalNode;
}


int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};
    for (int i = 0; i < 20; ++i)
        Insert(list, i, i);

    int k = 5;
    printf("%d\n", FractionalNode(list, k)->data);
}