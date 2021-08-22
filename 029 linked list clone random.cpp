#include <iostream>
#include <map>


template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* random;
};


template <typename T>
Node<T>* Clone(Node<T>* head) {
    std::map<Node<T>*, Node<T>*> ht;
    
    Node<T>* x = head;
    while (x)
    {
        Node<T>* y = (Node<T>*)malloc(sizeof(Node<T>));
        y->data = x->data;
        y->next = NULL;
        y->random = NULL;
        ht[x] = y;
        x = x->next;
    }

    x = head;
    while (x)
    {
        Node<T>* y = ht[x];
        y->next = ht[x->next];
        y->random = ht[x->random];
        x = x->next;
    }
    
    return ht[head];
}

template <typename T>
Node<T>* Clone2(Node<T>* head) {

    Node<T>* x = head;
    while (x)
    {
        Node<T>* y = (Node<T>*)malloc(sizeof(Node<T>));
        y->data = x->data;
        y->next = x->random; // 把x->random暂存在y->next中
        y->random = NULL;
        x->random = y; // 把y暂存在x->random中
        x = x->next;
    }

    x = head;
    while (x)
    {
        Node<T>* y = x->random;
        y->random = y->next->random; // y->next是原来的x->copy，它的random即使副本
        x = x->next;
    }

    x = head;
    Node<T>* newHead = x->random;
    while (x)
    {
        Node<T>* y = x->random;
        x->random = y->next;
        if (x->next)
            y->next = x->next->random;
        else
            y->next = NULL;
        x = x->next;
    }

    return newHead;
}


int main(int argc, char** argv) {
    Node<int>* n0 = (Node<int>*)malloc(sizeof(Node<int>));
    Node<int>* n1 = (Node<int>*)malloc(sizeof(Node<int>));
    Node<int>* n2 = (Node<int>*)malloc(sizeof(Node<int>));
    Node<int>* n3 = (Node<int>*)malloc(sizeof(Node<int>));
    Node<int>* n4 = (Node<int>*)malloc(sizeof(Node<int>));

    n0->data = 0;
    n0->next = n1;
    n0->random = n3;

    n1->data = 1;
    n1->next = n2;
    n1->random = n0;

    n2->data = 2;
    n2->next = n3;
    n2->random = n1;

    n3->data = 3;
    n3->next = n4;
    n3->random = n4;

    n4->data = 4;
    n4->next = NULL;
    n4->random = n3;

    Node<int>* head = n0;

    Node<int>* current = head;
    while (current)
    {
        printf("[%d %d] ", current->data, current->random->data);
        current = current->next;
    }
    printf("\n");

    current = Clone(head);
    while (current)
    {
        printf("[%d %d] ", current->data, current->random->data);
        current = current->next;
    }
    printf("\n");
    
    current = Clone2(head);
    while (current)
    {
        printf("[%d %d] ", current->data, current->random->data);
        current = current->next;
    }
    printf("\n");
}