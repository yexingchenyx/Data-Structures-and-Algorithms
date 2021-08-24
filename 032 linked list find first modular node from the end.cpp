#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN


template <typename T>
Node<T>* FirstModularNodeFromEnd(Node<T>** list, int k) {
    Node<T>* modularNode = *list;
    Node<T>* current = *list;

    for (int i = 0; i < k; ++i) {
        if (current)
            current = current->next;
        else
            return NULL;
    }

    while (current->next)
    {
        modularNode = modularNode->next;
        current = current->next;
    }

    return modularNode;
}


int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};
    for (int i = 0; i < 20; ++i)
        Insert(list, i, i);

    int k = 3;
    printf("%d\n", FirstModularNodeFromEnd(list, k)->data);
}