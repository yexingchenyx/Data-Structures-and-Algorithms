#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
Node<T>* AlternateMerge(Node<T>** l1, Node<T>** l2) {
    Node<T>* c1 = *l1;
    Node<T>* c2 = *l2;

    Node<T>* head = (Node<T>*)malloc(sizeof(Node<T>));
    head->next = NULL;
    Node<T>* cur = head;

    while (c1 && c2)
    {
        cur->next = c1;
        cur = cur->next;
        c1 = c1->next;
        cur->next = c2;
        cur = cur->next;
        c2 = c2->next;
    }

    if (c1)
        cur->next = c1;
    else
        cur->next = c2;

    cur = head->next;
    free(head);

    return cur;
}


int main(int argc, char** argv) {

    Node<int>* l1[1] = {NULL};
    for (int i = 0; i < 5; ++i) {
        Insert(l1, i, i);
    }

    Node<int>* l2[1] = {NULL};
    for (int i = 0; i < 8; ++i) {
        Insert(l2, 10 + i, i);
    }

    Node<int>* current = *l1;
    printf("A:\n");
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    
    current = *l2;
    printf("\nB:\n");
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    Node<int>* newHead = AlternateMerge(l1, l2);
    current = newHead;
    printf("\nA+B:\n");
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}