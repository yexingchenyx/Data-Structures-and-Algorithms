#include <iostream>

struct Node {
    Node* next;
};


int FindLengthofLoop(Node* head) {
    Node* slow_ptr = head;
    Node* fast_ptr = head;

    bool loop_exists = false;
    while (slow_ptr && fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr) {
            loop_exists = true;
            break;
        }
    }

    if (!loop_exists) {
        return 0;
    }
    
    int count = 0;
    fast_ptr = fast_ptr->next;
    while (slow_ptr != fast_ptr) {
        fast_ptr = fast_ptr->next;
        count ++;
    }

    return count;
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

    int len = FindLengthofLoop(n0);
    printf("%d \n", len == 5);

    free(n0);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);

}



