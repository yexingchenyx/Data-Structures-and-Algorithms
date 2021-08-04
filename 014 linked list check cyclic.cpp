#include <iostream>
#include <set>

struct Node {
    Node* next;
};

// 需要知道node总数
bool BruteForce(Node* head, int size) {
    Node* current = head;
    for (int i = 0; i < size; ++i) {
        Node* temp = current;
        for (int j = 0; j < size - i; ++j) {
            if (temp->next == current) {
                return true;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return false;
}

bool HashTable(Node* head) {
    std::set<Node*> lut;
    Node* current = head;
    while (current) {
        if (lut.count(current)) {
            return true;
        } else {
            lut.insert(current);
            current = current->next;
        }
    }
    return false;
}

// two pointer 一快一慢两指针相遇则有循环
bool FloydCycleFinding(Node* head) {
    Node* slow_ptr = head;
    Node* fast_ptr = head;

    while (slow_ptr && fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr) {
            return true;
        }
    }

    return false;
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

    printf("Brute force: %d \n", BruteForce(n0, 8));
    printf("Hash table: %d \n", HashTable(n0));
    printf("Floyd cycle finding: %d \n", FloydCycleFinding(n0));

    free(n0);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);

}



