#include <iostream>


struct Node
{
    Node* next;
};

// 返回 (n - 1) / 2 位置的node
Node* FindMiddle(Node* head) {
    Node* ptr1 = head; // ptr1走的快
    Node* ptr2 = head; // ptr2为中值

    int i = 0;

    while (ptr1->next != NULL)
    {
        if ( i == 0) {
            ptr1 = ptr1->next;
            i = 1;
        } else if (i == 1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            i = 0;
        }
    }
    
    return ptr2;
}


int main(int argc, char** argv) {

    Node* n0 = (Node*)malloc(sizeof(Node));
    Node* n1 = (Node*)malloc(sizeof(Node));
    Node* n2 = (Node*)malloc(sizeof(Node));
    Node* n3 = (Node*)malloc(sizeof(Node));
    Node* n4 = (Node*)malloc(sizeof(Node));
    Node* n5 = (Node*)malloc(sizeof(Node));

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    Node* middle = FindMiddle(n0);

    printf("%d %d\n", n2, middle);

    Node* n6 = (Node*)malloc(sizeof(Node));
    n5->next = n6;
    n6->next = NULL;

    middle = FindMiddle(n0);

    printf("%d %d\n", n3, middle);

    // free all nodes
}