#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
int Length(Node<T>** list) {
    int count = 0;
    Node<T>* current = *list;
    while(current) {
        count ++;
        current = current->next;
    }
    return count;
}

/**
 * @param list 用来存放列表头节点的指针
 */
template <typename T>
void Insert(Node<T>** list, T data, int id) { 
    Node<T>* new_node = (Node<T>*)malloc(sizeof(Node<T>));
    new_node->data = data;

    if (id == 0) {
        Node<T>* current = *list;
        *list = new_node;
        new_node->next = current;
    } else {
        Node<T>* prev = *list;
        for (int i = 0; i < id - 1; ++i) {
            prev = prev->next;
        }
        Node<T>* current = prev->next;
        prev->next = new_node;
        new_node->next = current;
    }
}

template<typename T>
void Delete(Node<T>** list, int id) {
    if (id == 0) {
        Node<T>* current = *list;
        Node<T>* next = current->next;
        *list = next;
        free(current);
    } else {
        Node<T>* prev = *list;
        for (int i = 0; i < id - 1; ++i) {
            prev = prev->next;
        }
        Node<T>* current = prev->next;
        Node<T>* next = current->next;
        prev->next = next;
        free(current);
    }
}

template<typename T>
void Free(Node<T>** list) {
    Node<T>* current = *list;
    while (current) {
        Node<T>* temp = current;
        current = current->next;
        free(temp);
    }
    *list = NULL;
}

#ifndef IGNORE_MAIN
int main(int argc, char** argv) {

    Node<int>* list[1] = {NULL};
    Insert(list, 0, 0);
    Insert(list, 1, 1);
    Insert(list, 2, 2);

    //Delete(list, 1);
    //Free(list);

    printf("length: %d\n", Length(list));

    Node<int>* current = *list;
    while(current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
#endif