#include <iostream>

template <typename T>
class DynArrayStack {
    public:
        DynArrayStack() {}

        ~DynArrayStack() {
        }

        bool IsEmpty() const {
            return true;
        }

        bool IsFull() const {
            return true;
        }

        void Push(T data) {
        }

        T Pop() {
            return T();
        }

        int Size() const {
            return 0;
        }
    private:
};

int main(int argc, char** argv) {
    DynArrayStack<int> stack;
    for (int i = 0; i < 10; ++i)
        stack.Push(i);

    while (!stack.IsEmpty())
    {
        int value = stack.Pop();
        printf("%d ", value);
    }
    printf("\n");
}