#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
bool IsPalindrome(Node<T>** list) {

    return false;
}

int main(int argc, char** argv) {
    Node<int>* list[1] = {NULL};

    for (int i = 0; i < 5; ++i) {
        Insert(list, i, 0);
        Insert(list, i, i * 2 + 1);
    }

    Node<int>* current = *list;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n Is palindrome: %d\n", IsPalindrome(list));

}