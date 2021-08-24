#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN


template <typename T>
Node<T>* LastModularNodeFromBegin(Node<T>** list, int k) {
    Node<T>* modularNode = *list;
    Node<T>* current = *list;

    int i = 0;
    while(current) {
        if (i % k == 0)
            modularNode = current;
        
        current = current->next;
        i ++;
    }

    return modularNode;
}


int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};
    for (int i = 0; i < 20; ++i)
        Insert(list, i, i);

    int k = 3;
    printf("%d\n", LastModularNodeFromBegin(list, k)->data);
}