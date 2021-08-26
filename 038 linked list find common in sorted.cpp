#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
Node<T>* FindCommonInTwoSortedLists(Node<T>* list1, Node<T>* list2) {
    Node<T>* temp = (Node<T>*)malloc(sizeof(Node<T>));
    temp->next = NULL;
    Node<T>* cur1 = list1;
    Node<T>* cur2 = list2;
    Node<T>* cur = temp;
    
    while (cur1 && cur2)
    {
        if (cur1->data == cur2->data) {
            Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
            newNode->data = cur1->data;
            newNode->next = NULL;
            cur->next = newNode;
            cur = newNode;
            cur1 = cur1->next;
            cur2 = cur2->next;
        } else if (cur1->data < cur2->data) {
            cur1 = cur1->next;
        } else {
            cur2 = cur2->next;
        }
    }

    cur = temp->next;
    free(temp);
    return cur;
}


int main(int argc, char** argv) {

    Node<int>* list1[1] = {NULL};
    int id = 0;
    Insert(list1, 1, id++);
    Insert(list1, 7, id++);
    Insert(list1, 19, id++);
    Insert(list1, 36, id++);
    Insert(list1, 88, id++);

    Node<int>* list2[1] = {NULL};
    id = 0;
    Insert(list2, 16, id++);
    Insert(list2, 36, id++);
    Insert(list2, 37, id++);
    Insert(list2, 88, id++);
    Insert(list2, 98, id++);
    Insert(list2, 100, id++);

    Node<int>* current = *list1;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    current = *list2;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    
    current = FindCommonInTwoSortedLists(*list1, *list2);
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}