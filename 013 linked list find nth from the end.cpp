#include <iostream>
#include <map>
#define IGNORE_MAIN
#include "./007 linked list singly.cpp"
#undef IGNORE_MAIN

// 找到倒数第n个节点

template<typename T>
Node<T>* BruteForce(Node<T>** list, int n) {
    Node<T>* current = *list;
    while (current) {
        int nn = -1;
        Node<T>* temp = current;
        while (temp) {
            temp = temp->next;
            nn += 1;
        }
        if (nn == n) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

template<typename T>
Node<T>* HashTable(Node<T>** list, int n) {
    Node<T>* current = *list;
    int id = 0;

    std::map<int, Node<T>*> lut;   

    while (current) {
        lut[id] = current;

        current = current->next;
        id ++;
    }

    int length = id;

    return lut[length - n - 1];
}

template <typename T>
Node<T>* ScanTwice(Node<T>** list, int n) {
    Node<T>* current = *list;
    int length = 0;

    while (current) {
        current = current->next;
        length ++;
    }

    current = *list;
    for (int i = 0; i < length - n - 1; ++i) {
        current = current->next;
    }

    return current;
}

template <typename T>
Node<T>* DoublePtr(Node<T>** list, int n) {
    Node<T>* current = *list;
    Node<T>* tail = *list;

    for (int i = 0; i < n + 1; ++i) {
        tail = tail->next;
    }

    while (tail) {
        current = current->next;
        tail = tail->next;
    }

    return current;
}

int main(int argc, char** argv) {

    int size = 10;

    Node<int>* list[1] = {NULL};
    for (int i = 0; i < size; ++i) {
        Insert(list, i, i);
    }

    printf("Brute force:\n");
    for (int n = 0; n < size; ++n) {
        Node<int>* node = BruteForce(list, n);
        printf("%d: %d \n", n, node->data);
    }

    printf("Using hash table:\n");
    for (int n = 0; n < size; ++n) {
        Node<int>* node = HashTable(list, n);
        printf("%d: %d \n", n, node->data);
    }

    printf("Scan twice:\n");
    for (int n = 0; n < size; ++n) {
        Node<int>* node = ScanTwice(list, n);
        printf("%d: %d \n", n, node->data);
    }

    printf("Double ptr:\n");
    for (int n = 0; n < size; ++n) {
        Node<int>* node = DoublePtr(list, n);
        printf("%d: %d \n", n, node->data);
    }

    return 0;
}