#include <iostream>
#define IGNORE_MAIN
#include "007 linked list singly.cpp"
#undef IGNORE_MAIN

template <typename T>
Node<T>* RecursiveReverse(Node<T>* head) {
    if (!head) {
        return NULL;
    }

    if (!head->next) {
        return head;
    }

    Node<T>* second = head->next;
    
    Node<T>* reverse_head = RecursiveReverse(second);

    second->next = head;
    head->next = NULL;

    return reverse_head;
}

template <typename T>
bool IsPalindrome(Node<T>** list) {

    Node<T>* slow = *list;
    Node<T>* fast = *list;
    if (!fast->next) {
        return false;
    }
    fast = fast->next;

    while (fast->next)
    {
        if (!fast->next->next) {
            return false;
        }

        fast = fast->next->next;
        slow = slow->next;
    }
    
    Node<T>* h1 = *list;
    Node<T>* h2 = slow->next;
    slow->next = NULL;

    h2 = RecursiveReverse(h2);

    Node<T>* c1 = h1;
    Node<T>* c2 = h2;
    bool isPalindrome = true;
    while (c1) {
        if (c1->data != c2->data) {
            isPalindrome = false;
            break;
        }
        c1 = c1->next;
        c2 = c2->next;
    }

    h2 = RecursiveReverse(h2);
    slow->next = h2;

    return isPalindrome;
}

int main(int argc, char** argv) {
    Node<int>* list[1] = {NULL};

    for (int i = 0; i < 5; ++i) {
        Insert(list, i, 0);
        Insert(list, i, i * 2 + 1);
    }

    bool isPalindrome = IsPalindrome(list);   

    Node<int>* current = *list;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\nIs palindrome: %d\n", isPalindrome);

}