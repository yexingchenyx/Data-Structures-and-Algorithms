
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template<typename T>
int Length(Node<T>** list) {
    Node<T>* head = *list;
    if (!head) {
        return 0;
    }

    int count = 0;
    Node<T>* current = head;
    do {
        count ++;
        current = current->next;
    } while (current != head);

    return count;
}

template<typename T>
void Insert(Node<T>** list, T data, int id) {
    Node<T>* new_node = (Node<T>*)malloc(sizeof(Node<T>));
    new_node->data = data;

    Node<T>* head = *list;

    if (id == 0) {
        if (!head) {
            *list = new_node;
            new_node->next = new_node;
        } else {
            Node<T>* current = head;
            Node<T>* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            *list = new_node;
            new_node->next = current;
            tail->next = new_node;
        }
    } else {
        Node<T>* prev = head;
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
    Node<T>* head = *list;

    if (id == 0) {
        Node<T>* current = head;
        Node<T>* next = current->next;
        if (next == head) {
            *list = NULL;
            free(current);
        } else {
            Node<T>* tail = head;
            while(tail->next != head) {
                tail = tail->next;
            }
            *list = next;
            tail->next = next;
            free(current);
        }
    } else {
        Node<T>* prev = head;
        for (int i = 0; i < id - 1; ++i) {
            prev = prev->next;
        }
        Node<T>* current = prev->next;
        Node<T>* next = current->next;
        prev->next = next;
        free(current);
    }
}

int main(int argc, char** argv) {
    Node<int>* list[1] = {NULL};
    Insert(list, 1, 0);
    Insert(list, 3, 1);
    Insert(list, 0, 0);
    Insert(list, 2, 2);

    Delete(list, 0);
    Delete(list, 2);

    printf("length: %d\n", Length(list));

    Node<int>* head = *list;
    Node<int>* current = head;
    if (head) {
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }
    printf("\n");
}