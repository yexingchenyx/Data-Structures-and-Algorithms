#include <iostream>

/**
 * @brief 生成长度为n的所有01的组合
 */
void binary(char temp[], int n) {
    if (n < 1)
        printf("%s\n", temp);
    else {
        temp[n - 1] = '0';
        binary(temp, n - 1);
        temp[n - 1] = '1';
        binary(temp, n - 1);
    }
}

int main(int argc, char** argv) {
    char temp[3];

    binary(temp, 3);
}

