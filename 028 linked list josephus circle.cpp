#include <iostream>
#define IGNORE_MAIN
#include "009 linked list circular.cpp"
#undef IGNORE_MAIN

/**
 * N个人循环，每次排除第M个人，求最后剩下的那个
 */

int GetJosephusPosition(int N, int M) {
    Node<int>* list[1] = {NULL};

    for (int i = 0; i < N; ++i)
        Insert(list, i, i);

    Node<int>* p = *list;
    while (p->next != *list)
    {
        p = p->next;
    }

    for (int count = N; count > 1; --count) {
        for (int i = 0; i < M - 1; ++i) {
            p = p->next;
        }
        p->next = p->next->next;
    }

    return p->data;
}

int main(int argc, char** argv) {
    int N = 10;
    int M = 3;
    printf("N=%d, M=%d: %d\n", N, M, GetJosephusPosition(N, M));
}
