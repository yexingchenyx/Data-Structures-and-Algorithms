#include <iostream>

/**
 * @brief 从k_str中挑选n个字符的所有组合
 * 
 */
void k_string(char temp[], int n, char k_str[], int k) {
    if (n < 1)
        printf("%s\n", temp);
    else
        for (int i = 0; i < k; ++i) {
            temp[n - 1] = k_str[i];
            k_string(temp, n - 1, k_str, k);
        }
}

int main(int argc, char** argv) {
    char temp[3];
    char k_str[5] = {'a', 'b', 'c', 'd', 'e'};
    k_string(temp, 3, k_str, 5);
}