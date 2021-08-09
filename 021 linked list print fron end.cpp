#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
void PrintFromEnd(Node<T>* head) {
    if (!head) {
        return;
    }

    PrintFromEnd(head->next);

    std::cout << head->data << std::endl;
}

int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};

    for (int i = 0; i < 5; ++i) {
        Insert(list, i, i);
    }

    PrintFromEnd(*list);

}