#include <iostream>
#define IGNORE_MAIN
#include "009 linked list circular.cpp"
#undef IGNORE_MAIN



int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};

    for (int i = 0;i < 10; ++i) {
        Insert(list, i, i);
    }

    Node<int>* head = *list;
    Node<int>* current = *list;
    if (head) {
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }
    printf("\n");
}
