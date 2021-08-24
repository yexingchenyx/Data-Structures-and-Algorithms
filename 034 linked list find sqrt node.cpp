#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

/**
 * find sqrt(n) th element, where n is not known
 */
template <typename T>
Node<T>* SqrtNode(Node<T>** list) {
    Node<T>* sqrtNode = *list;
    Node<T>* current = *list;
    int i = 1;
    int j = 1;
    while(current) {
        if (i == j * j) {
            sqrtNode = sqrtNode->next;
            j++;
        }
        i++;
        current = current->next;
    }

    return sqrtNode;
}


int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};
    for (int i = 0; i < 9; ++i)
        Insert(list, i, i);

    printf("%d\n", SqrtNode(list)->data);
}