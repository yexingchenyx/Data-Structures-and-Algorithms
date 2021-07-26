#include <iostream>

bool is_array_sorted(int a[], int n) {
    if (n == 1)
        return true;
    else
        return a[n - 1] < a[n - 2] ? false : is_array_sorted(a, n - 1);
}

int main(int argc, char** argv) {
    int a[] = {1, 2, 3};
    printf("%d\n", is_array_sorted(a, 3));
}