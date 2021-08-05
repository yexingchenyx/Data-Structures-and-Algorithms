#include <iostream>

struct Node {
    int data;
    Node* next;
};


Node* InsertInSortedList(Node* head, Node* new_node) {
    Node* current = head;
    Node* temp = NULL;

    while(current && current->data < new_node->data) {
        temp = current;
        current = current->next;
    }

    if (temp) {
        temp->next = new_node;
        new_node->next = current;
        return head;
    } else {
        new_node->next = current;
        return new_node;
    }
}


int main(int argc, char** argv) {

    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;

    Node* current = head;
    for (int i = 0; i < 10; ++i) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data= (i +1) * 2;
        current->next = node;
        node->next = NULL;
        current = node;
    }

    Node* n0 = (Node*)malloc(sizeof(Node));
    n0->data = -1;
    
    Node* n1 = (Node*)malloc(sizeof(Node));
    n1->data = 5;

    Node* n2 = (Node*)malloc(sizeof(Node));
    n2->data = 100;

    head = InsertInSortedList(head, n0);
    head = InsertInSortedList(head, n1);
    head = InsertInSortedList(head, n2);

    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");


    // free memory
}