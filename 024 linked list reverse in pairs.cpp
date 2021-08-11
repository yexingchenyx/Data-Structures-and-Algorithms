#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
Node<T>* ReversePairRecursive(Node<T>* head) {
    if (!head || !head->next) {
        return head;
    } else {
        Node<T>* current = head;
        Node<T>* next = head->next;
        Node<T>* next_next = head->next->next;

        head = next;
        head->next = current;
        head->next->next = ReversePairRecursive(next_next);

        return head;
    }
}

template <typename T>
Node<T>* ReversePairIterative(Node<T>* head) {
    Node<T>* new_head = NULL;
    Node<T>* prev = NULL;
    Node<T>* current = head;
    while (current && current->next)
    {
        Node<T>* next = current->next;
        Node<T>* next_next = current->next->next;

        if (prev) {
            prev->next = next;
        }

        if (!new_head) {
            new_head = next;
        }

        next->next = current;

        current->next = next_next;

        prev = current;

        current = next_next;
    }

    return new_head;
}

int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};

    for (int i = 0; i < 6; ++i) {
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

    head = ReversePairIterative(head);
    
    current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}