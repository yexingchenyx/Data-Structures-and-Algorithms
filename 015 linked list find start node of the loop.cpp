#include <iostream>

struct Node {
    Node* next;
};


Node* FindBeginofLoop(Node* head) {
    bool loop_exists = false;

    Node* slow_ptr = head;
    Node* fast_ptr = head;

    while (slow_ptr && fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr) {
            loop_exists = true;
            break;
        }
    }

    if (!loop_exists) {
        return NULL;
    }

    slow_ptr = head;
    while (slow_ptr != fast_ptr) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }

    return slow_ptr;
}


int main(int argc, char** argv) {

    Node* n0 = (Node*)malloc(sizeof(Node));
    Node* n1 = (Node*)malloc(sizeof(Node));
    Node* n2 = (Node*)malloc(sizeof(Node));
    Node* n3 = (Node*)malloc(sizeof(Node));
    Node* n4 = (Node*)malloc(sizeof(Node));
    Node* n5 = (Node*)malloc(sizeof(Node));
    Node* n6 = (Node*)malloc(sizeof(Node));
    Node* n7 = (Node*)malloc(sizeof(Node));

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n2;

    Node* n22 = FindBeginofLoop(n0);
    printf("%d \n", n2 == n22);

    free(n0);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);

}



