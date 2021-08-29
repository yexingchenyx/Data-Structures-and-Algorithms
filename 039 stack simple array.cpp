#include <iostream>

template <typename T>
class ArrayStack {
    public:
        ArrayStack(int capacity) : 
            capacity_(capacity),
            array_(new T[capacity]),
            top_(-1) {}

        ~ArrayStack() {
            delete[] array_;
        }

        bool IsEmpty() const {
            return top_ == -1;
        }

        bool IsFull() const {
            return (top_ == capacity_ - 1);
        }

        void Push(T data) {
            if (IsFull())
                throw "Overflow";
            
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

        int Capacity() const {
            return capacity_;
        }
    
    private:
        int capacity_;
        T* array_;
        int top_;
};

int main(int argc, char** argv) {
    ArrayStack<int> stack(10);
    for (int i = 0; i < 10; ++i)
        stack.Push(i);

    while (!stack.IsEmpty())
    {
        int value = stack.Pop();
        printf("%d ", value);
    }
    printf("\n");
}