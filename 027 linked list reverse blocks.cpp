#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

/**
 * Input: 1 2 3 4 5 6 7 8 9 10
 * For K=2: 2 1 4 3 6 5 8 7 10 9
 * For K=3: 3 2 1 6 5 4 9 8 7 10
 * For K=4: 4 3 2 1 8 7 6 5 9 10
 * 
 */

template <typename T>
void ReverseBlockOfK(Node<T>** list, int K) {

}

int main(int argc, char** argv) {

    Node<int>* list[3] = {NULL, NULL, NULL};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 3; ++j) {
            Insert(list + j, i + 1, i);
        }
    }

    Node<int>** l1 = list;
    Node<int>** l2 = list + 1;
    Node<int>** l3 = list + 2;

    Node<int>* current = *l3;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    ReverseBlockOfK(l1, 2);
    ReverseBlockOfK(l2, 3);
    ReverseBlockOfK(l3, 4);

    for (int j = 0; j < 3; ++j) {
        Node<int>* cur = *(list + j);
        while (cur)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
}