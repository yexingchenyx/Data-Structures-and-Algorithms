#include <iostream>

double factorial(int n) {
    if (n == 0)
        return 1.0;
    else
        return n * factorial(n - 1);
}

int main(int argc, char** argv) {
    printf("%d!=%f\n", 3, factorial(3));
}