
#include <iostream>
#define IGNORE_MAIN
#include "009 linked list circular.cpp"
#undef IGNORE_MAIN

/**
 * 
 * 4-->15-->7-->40
 * |            |
 * <------------
 * 
 * after split:
 * 
 * 4-->15     7-->40
 * |   |      |   |
 * <----      <----
 * 
 */

template <typename T>
void SplitList(Node<T>** list, Node<T>** l1, Node<T>** l2) {
    Node<T>* head = *list;

    if (!head) {
        *l1 = NULL;
        *l2 = NULL;
        return;
    }

    Node<T>* slow_ptr = head;
    Node<T>* fast_ptr = head;

    while (fast_ptr->next != head && fast_ptr->next->next != head) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    if (fast_ptr->next->next == head) {
        fast_ptr = fast_ptr->next;
    }

    *l1 = head;

    if (head->next != head) {
        *l2 = slow_ptr->next;
    } else {
        *l1 = NULL;
    }

    fast_ptr->next = slow_ptr->next;
    slow_ptr->next = head;
}

int main(int argc, char** argv) {
    Node<int>* list[1] = {NULL};
    Insert(list, 4, 0);
    Insert(list, 15, 1);
    Insert(list, 7, 2);
    Insert(list, 40, 3);

    printf("List:\n");
    Node<int>* current = *list;
    if (*list) {
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != *list);
    }

    Node<int>* l1[1] = {NULL};
    Node<int>* l2[2] = {NULL};

    SplitList(list, l1, l2);

    printf("\nL1:\n");
    current = *l1;
    if (*l1) {
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != *l1);
    }
    printf("\nL2:\n");
    current = *l2;
    if (*l1) {
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != *l2);
    }
    printf("\n");
}