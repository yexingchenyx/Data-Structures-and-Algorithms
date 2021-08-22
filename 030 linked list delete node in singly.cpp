#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
void DeleteNodeInSingly(Node<T>* node) {
    Node<T>* next = node->next;
    node->data = next->data;
    node->next = next->next;
    free(next);
}


int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};

    for (int i = 0; i < 10; ++i)
        Insert(list, i, i);

    Node<int>* current = *list;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    Node<int>* aNode = (*list)->next->next->next->next->next;
    DeleteNodeInSingly(aNode);

    current = *list;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}