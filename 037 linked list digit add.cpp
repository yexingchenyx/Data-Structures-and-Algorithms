#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

/**
 * 十进制加法，每一个Node代表每一位上的数
 * 
 */


void AddListNumbers(Node<int>* list1, Node<int>* list2, int *carry, Node<int>** result) {
    if (!list1)
        return;

    AddListNumbers(list1->next, list2->next, carry, result);

    int sum = list1->data + list2->data + (*carry);
    *carry = sum / 10;
    sum = sum % 10;

    Node<int>* temp = (Node<int>*)malloc(sizeof(Node<int>));
    temp->data = sum;
    temp->next = *result;
    *result = temp;

    return;
}

void AddRemainingNumbers(Node<int>* list1, int* carry, Node<int>** result, int diff) {
    if (!list1 || diff == 0)
        return;

    AddRemainingNumbers(list1->next, carry, result, diff-1);

    int sum = list1->data + (*carry);

    *carry = sum / 10;
    sum = sum % 10;

    Node<int>* temp = (Node<int>*)malloc(sizeof(Node<int>));
    temp->data = sum;
    temp->next = *result;
    *result = temp;
    
    return;
}

Node<int>* AddList(Node<int>* list1, Node<int>* list2) {
    int list1Length = 0;
    int list2Length = 0;
    Node<int>* current = list1;
    while (current) {
        list1Length ++;
        current = current->next;
    }
    current = list2;
    while (current) {
        list2Length ++;
        current = current->next;
    }

    int diff = 0;
    Node<int>* listLong = NULL;
    Node<int>* listShort = NULL;
    if (list1Length > list2Length) {
        listLong = list1;
        listShort = list2;
        diff = list1Length - list2Length;
    } else {
        listLong = list2;
        listShort = list1;
        diff = list2Length - list1Length;
    }

    current = listLong;
    for (int i = 0; i < diff; ++i)
        current = current->next;

    int carry = 0;
    Node<int>* result[1] = {NULL};

    AddListNumbers(current, listShort, &carry, result);
    AddRemainingNumbers(listLong, &carry, result, diff);

    if(carry != 0) {
        Node<int>* temp = (Node<int>*)malloc(sizeof(Node<int>));
        temp->data = carry;
        temp->next = *result;
        *result = temp;
    }

    return *result;
}


int main(int argc, char** argv) {

    Node<int>* list1[1] = {NULL};
    int id = 0;
    Insert(list1, 3, id++);
    Insert(list1, 7, id++);
    Insert(list1, 1, id++);
    Insert(list1, 0, id++);
    Insert(list1, 8, id++);

    Node<int>* list2[1] = {NULL};
    id = 0;
    Insert(list2, 1, id++);
    Insert(list2, 5, id++);
    Insert(list2, 3, id++);

    Node<int>* list = AddList(*list1, *list2);

    Node<int>* current = *list1;
    while (current) {
        printf("%d", current->data);
        current = current->next;
    }
    printf(" + ");
    current = *list2;
    while (current) {
        printf("%d", current->data);
        current = current->next;
    }
    printf(" = ");
    current = list;
    while (current) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
    
}