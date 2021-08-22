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
Node<T>* GetKPlusOneThNode(int K, Node<T>* head) {
    if (!head)
        return head;

    Node<T>* Kth = head;
    for (int i = 0; i < K; ++i) {
        if (!Kth)
            return head->next;
        Kth = Kth->next;
    }

    return Kth;
}

template <typename T>
bool HasKNodes(Node<T>* head, int K) {
    int i = 0;
    for (i = 0; head && (i < K); i++, head = head->next);
    return i == K;
}

template <typename T>
void ReverseBlockOfK(Node<T>** list, int K) {
    if (K == 0 || K == 1)
        return;

    Node<T>* head = *list;
    Node<T>* current = head;
    Node<T>* newHead = NULL;

    if (HasKNodes(current, K))
        newHead = GetKPlusOneThNode(K - 1, current);
    else
        newHead = head;

    Node<T>* prev_block_first = NULL;
    Node<T>* block_first = NULL;
    Node<T>* block_last = NULL;
    Node<T>* temp = NULL;
    Node<T>* next = NULL;
    while (current && HasKNodes(current, K))
    {
        block_first = current;
        block_last = GetKPlusOneThNode(K - 1, current);

        temp = GetKPlusOneThNode(K, current);
        for (int i = 0; i < K; ++i) {
            next = current->next;
            current->next = temp;
            temp = current;
            current = next;
        }
        if (prev_block_first)
            prev_block_first->next = block_last;
        prev_block_first = block_first;
    }
    
    *list = newHead;
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