#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
Node<T>* ReversePairRecursive(Node<T>* head) {
    return NULL;
}

template <typename T>
Node<T>* ReversePairIterative(Node<T>* head) {
    return NULL;
}

int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};

    for (int i = 0; i < 5; ++i) {
        Insert(list, i, i);
    }

    Node<int>* head = ReversePairRecursive(*list);

    Node<int>* current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}