#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
Node<T>* MergeSortedList(Node<T>* head1, Node<T>* head2) {
    if (!head1) {
        return head2;
    }   
    if (!head2) {
        return head1;
    }

    Node<T>* head = NULL;

    if (head1->data < head2->data) {
        head = head1;
        head->next = MergeSortedList(head1->next, head2);
    } else {
        head = head2;
        head->next = MergeSortedList(head1, head2->next);
    }

    return head;
}

template <typename T>
Node<T>* MergeSortedListIterative(Node<T>* head1, Node<T>* head2) {
    Node<T>* head = (Node<T>*)malloc(sizeof(Node<T>));
    head->next = NULL;
    Node<T>* tail = head;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }

    if (head1) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    Node<T>* temp = head;
    head = head->next;
    free(head);
    return head;
}

int main(int argc, char** argv) {

    Node<int>* list1[1] = {NULL};
    Node<int>* list2[1] = {NULL};

    for (int i = 0; i < 5; ++i) {
        Insert(list1, i * 2, i);
        Insert(list2, i * 2 + 1, i);
    }

    //Node<int>* head = MergeSortedList(*list1, *list2);
    Node<int>* head = MergeSortedListIterative(*list1, *list2);

    Node<int>* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

