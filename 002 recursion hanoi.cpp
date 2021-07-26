#include <iostream>

/**
 * @brief  
 */
void hanoi(int n, char from_peg, char to_peg, char aux_peg) {
    
    /// 仅有一个盘，那么直接将其从from移到to，并结束
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", from_peg, to_peg);
        return;
    }

    /// 将from顶上n-1个盘移到aux
    hanoi(n - 1, from_peg, aux_peg, to_peg);

    /// 将from上剩下的那个盘移到to
    printf("Move disk %d from peg %c to peg %c\n", n, from_peg, to_peg);

    /// 将aux上的n-1个盘移到to
    hanoi(n - 1, aux_peg, to_peg, from_peg);
}

int main(int argc, char** argv) {
    hanoi(3, 'A', 'B', 'C');
}