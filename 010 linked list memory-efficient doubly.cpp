#include <iostream>

template<typename T>
struct Node {
    T data;
    unsigned long ptrdiff; // prev ^ next, 前节点地址与后节点地址的异或
};

/**
 *  
 * 异或，相同为0， 不同为1
 * 异或1反转，异或0不变
 * 
 * 1 ^ 1 = 0
 * 0 ^ 1 = 1
 * 1 ^ 0 = 1
 * 0 ^ 0 = 0
 * 
 * X ^ X = 0
 * X ^ 0 = X
 * X ^ Y = Y ^ X
 * (X ^ Y) ^ Z = X ^ (Y ^ Z)
 * 
 * (X ^ Y) ^ Y = X ^ (Y ^ Y) = X ^ 0 = X
 * 
 */

template <typename T>
int Length(Node<T>** list) {
    Node<T>* prev = NULL;
    Node<T>* current = *list;
    
    int count = 0;
    while (current) {
        count ++;
        Node<T>* temp = current;
        current = (Node<T>*)(current->ptrdiff ^ (unsigned long)prev);
        prev = temp;
    }

    return count;
}

template <typename T>
void Insert(Node<T>** list, T data, int id) {
    Node<T>* new_node = (Node<T>*)malloc(sizeof(Node<T>));
    new_node->data = data;

    if (id == 0) {
        Node<T>* current = *list;
        *list = new_node;
        new_node->ptrdiff = (unsigned long)NULL ^ (unsigned long)current;
        if (current) {
            Node<T>* next = (Node<T>*)(current->ptrdiff ^ (unsigned long)NULL);
            current->ptrdiff = (unsigned long)new_node ^ (unsigned long)next;
        }
    } else {
        Node<T>* prev_prev = NULL;
        Node<T>* prev = *list;
        for (int i = 0; i < id - 1; ++i) {
            Node<T>* temp = prev;
            prev = (Node<T>*)(prev->ptrdiff ^ (unsigned long)prev_prev);
            prev_prev = temp;
        }
        Node<T>* current = (Node<T>*)(prev->ptrdiff ^ (unsigned long)prev_prev);
        prev->ptrdiff = (unsigned long)prev_prev ^ (unsigned long)new_node;
        new_node->ptrdiff = (unsigned long)prev ^ (unsigned long)current;
        if (current) {
            Node<T>* next = (Node<T>*)(current->ptrdiff ^ (unsigned long)prev);
            current->ptrdiff = (unsigned long)new_node ^ (unsigned long)next;
        }
    }
}

template<typename T>
void Delete(Node<T>** list, int id) {
    if (id == 0) {
        Node<T>* current = *list;
        Node<T>* next = (Node<T>*)(current->ptrdiff ^ (unsigned long)NULL);
        *list = next;
        if (next) {
            Node<T>* next_next = (Node<T>*)(next->ptrdiff ^ (unsigned long)current);
            next->ptrdiff = (unsigned long)NULL ^ (unsigned long)next_next;
        }
        free(current);
    } else {
        Node<T>* prev_prev = NULL;
        Node<T>* prev = *list;
        for (int i = 0; i < id - 1; ++i) {
            Node<T>* temp = prev;
            prev = (Node<T>*)(prev->ptrdiff ^ (unsigned long)prev_prev);
            prev_prev = temp;
        }
        Node<T>* current = (Node<T>*)(prev->ptrdiff ^ (unsigned long)prev_prev);
        Node<T>* next = (Node<T>*)(current->ptrdiff ^ (unsigned long)prev);
        prev->ptrdiff = (unsigned long)prev_prev ^ (unsigned long)next;
        if (next) {
            Node<T>* next_next = (Node<T>*)(next->ptrdiff ^ (unsigned long)current);
            next->ptrdiff = (unsigned long)prev ^ (unsigned long)next_next;
        }
        free(current);
    }
}

int main(int argc, char** argv) {
    Node<int>* list[1] = {NULL};

    Insert(list, 1, 0);
    Insert(list, 3, 1);
    Insert(list, 0, 0);
    Insert(list, 2, 2);

    Delete(list, 1);
    Delete(list, 2);
    //Delete(list, 0);
    //Delete(list, 0);   

    printf("length: %d\n", Length(list));

    Node<int>* prev = NULL;
    Node<int>* current = *list;
    while (current) {
        printf("%d ", current->data);
        Node<int>* temp = current;
        current = (Node<int>*)(current->ptrdiff ^ (unsigned long)prev);
        prev = temp;
    }
    printf("\n");
}


