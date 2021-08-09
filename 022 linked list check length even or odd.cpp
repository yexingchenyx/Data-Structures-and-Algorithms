#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
bool IsLengthEven(Node<T>* head) {
    Node<T>* temp = head;
    while (temp && temp->next)
    {
        temp = temp->next->next;
    }

    if (temp) {
        return false;
    } else {
        return true;
    }
}

int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};

    for (int i = 0; i < 5; ++i) {
        Insert(list, i, i);
    }

    bool isEven = IsLengthEven(*list);

    printf("Is list length even: %d\n", isEven);

    Insert(list, 5, 5);

    isEven = IsLengthEven(*list);

    printf("Is list length even: %d\n", isEven);

}