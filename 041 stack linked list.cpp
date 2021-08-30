#include <iostream>

template <typename T>
class LinkedListStack {
    public:
        LinkedListStack() : top_(NULL) {
        }

        ~LinkedListStack() {
            Node<T>* current = top_;
            while (current)
            {
                Node<T>* temp = current->next;
                free(current);
                current = temp;
            }
        }

        bool IsEmpty() const {
            return top_ == NULL;
        }

        void Push(T data) {
            Node<T>* current = (Node<T>*)malloc(sizeof(Node<T>));
            current->data = data;
            current->next = top_;
            top_ = current;
        }

        T Pop() {
            if (IsEmpty())
                throw "Underflow";

            Node<T>* current = top_;
            top_ = current->next;
            T data = current->data;
            free(current);
            return data;
        }
    private:
        template <typename DT>
        struct Node {
            DT data;
            Node<DT>* next;
        };

        Node<T>* top_;
};

int main(int argc, char** argv) {
    LinkedListStack<int> stack;
    for (int i = 0; i < 20; ++i)
        stack.Push(i);

    while (!stack.IsEmpty())
    {
        int value = stack.Pop();
        printf("%d ", value);
    }
    printf("\n");
}