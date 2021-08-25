#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
Node<T>* ExchangeEvenOddList(Node<T>** list) {
    Node<T>* odd = NULL;
    Node<T>* even = NULL;

    Node<T>* oddEnd = NULL;
    Node<T>* evenEnd = NULL;

    Node<T>* cur = *list;

    while (cur)
    {
        if (cur->data % 2 == 0) {
            if (!even) {
                even = cur;
                evenEnd = cur;
            } else {
                evenEnd->next = cur;
                evenEnd = cur;
            }
        } else {
            if (!odd) {
                odd = cur;
                oddEnd = cur;
            } else {
                oddEnd->next = cur;
                oddEnd = cur;
            }
        }
        cur = cur->next;
    }
    
    if (even) {
        evenEnd->next = odd;
        return even;
    } else {
        return odd;
    }
}

int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};
    for (int i = 0; i < 10; ++i) {
        Insert(list, i, i);
    }

    Node<int>* current = *list;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    Node<int>* newHead = ExchangeEvenOddList(list);

    current = newHead;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}