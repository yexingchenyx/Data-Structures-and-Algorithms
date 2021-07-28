#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;
};

template<typename T>
int Length(Node<T>** list) {
    int count = 0;
    Node<T>* current = *list;
    while(current) {
        count ++;
        current = current->next;
    }
    return count;
}

template<typename T>
void Insert(Node<T>** list, T data, int id) {
    Node<T>* new_node = (Node<T>*)malloc(sizeof(Node<T>));
    new_node->data = data;

    if (id == 0) {
        Node<T>* current = *list;
        *list = new_node;
        new_node->prev = NULL;
        new_node->next = current;
        if (current) {
            current->prev = new_node;
        }
    } else {
        Node<T>* prev = *list;
        for (int i = 0; i < id - 1; ++i) {
            prev = prev->next;
        }

        Node<T>* current = prev->next;
        prev->next = new_node;
        new_node->prev = prev;
        new_node->next = current;
        if (current) {
            current->prev = new_node;
        }
    }
}

template<typename T>
void Delete(Node<T>** list, int id) {
    if (id == 0) {
        Node<T>* current = *list;
        Node<T>* next = current->next;
        *list = next;
        if (next) {
            next->prev = NULL;
        }
        free(current);
    } else {
        Node<T>* prev = *list;
        for (int i = 0; i < id - 1; ++i) {
            prev = prev->next;
        }
        Node<T>* current = prev->next;
        Node<T>* next = current->next;
        prev->next = next;
        if (next) {
            next->prev = prev;
        }
        free(current);
    }
}

int main(int argc, char** argv) {
    Node<int>* list[1] = {NULL};
    Insert(list, 0, 0);
    Insert(list, 1, 1);
    Insert(list, 2, 2);

    Delete(list, 1);
    Delete(list, 1);

    printf("length: %d\n", Length(list));

    Node<int>* current = *list;
    while(current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}