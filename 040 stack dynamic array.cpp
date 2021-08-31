#include <iostream>

template <typename T>
class DynArrayStack {
    public:
        DynArrayStack() : 
        capacity_(1),
        array_((T*)malloc(sizeof(T))),
        top_(-1) {}

        ~DynArrayStack() {
            free(array_);
        }

        bool IsEmpty() const {
            return top_ == -1;
        }

        bool IsFull() const {
            return top_ == capacity_ - 1;
        }

        void Push(T data) {
            if (IsFull()) {
                capacity_ *= 2;
                array_ = (T*)realloc(array_, capacity_ * sizeof(T));
            }

            array_[++top_] = data;
        }

        T Pop() {
            if (IsEmpty())
                throw "Underflow";

            return array_[top_--];
        }

        int Size() const {
            return top_ + 1;
        }
    private:
        int capacity_;
        T* array_;
        int top_;
};

#ifndef IGNORE_MAIN
int main(int argc, char** argv) {
    DynArrayStack<int> stack;
    for (int i = 0; i < 20; ++i)
        stack.Push(i);

    while (!stack.IsEmpty())
    {
        int value = stack.Pop();
        printf("%d ", value);
    }
    printf("\n");
}
#endif