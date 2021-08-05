#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
Node<T>* IterativeReverse(Node<T>* head) {
    Node<T>* current = head;
    Node<T>* current_next = NULL;
    Node<T>* current_reverse_next = NULL;

    while (current) {
        current_next = current->next;
        current->next = current_reverse_next;

        current_reverse_next = current;
        current = current_next;
    }

    return current_reverse_next;
}

template <typename T>
Node<T>* RecursiveReverse(Node<T>* head) {
    if (!head) {
        return NULL;
    }

    if (!head->next) {
        return head;
    }

    Node<T>* second = head->next;
    
    Node<T>* reverse_head = RecursiveReverse(second);

    second->next = head;
    head->next = NULL;

    return reverse_head;
}

int main(int argc, char** argv) {
    Node<int>* list[1] = {NULL};
    for (int i = 0; i < 10; ++i) {
        Insert(list, i, i);
    }

    Node<int>* head = *list;

    Node<int>* current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    head = IterativeReverse(head);

    printf("Iterative:\n");
    current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    head = RecursiveReverse(head);

    printf("Recursive:\n");
    current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

}