#include <iostream>

int get_val(int* m, int rows, int cols, int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        return 0;
    else
        return m[row * cols + col];
}

/**
 * @brief 在m的row, col位置的最大长度
 * @param done 用于标记位置是否已经访问过
 * @param m 输入的矩阵m
 * @param rows m的行数
 * @param cols m的列数
 * @param row
 * @param col
 * @param size 输出的长度
 */
void find_max_length_at_cell(int* done, int* m, int rows, int cols, int row, int col, int& size) {
    if (get_val(m, rows, cols, row, col) == 0 || 
    done[row * cols + col] == 1)
        return;

    size ++;
    done[row * cols + col] = 1;

    /// 周围的8个方向
    int direction[8][2] = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, -1}
    };

    for (int i = 0; i < 8; ++i) {
        int new_row = row + direction[i][0];
        int new_col = col + direction[i][1];
        if (get_val(m, rows, cols, new_row, new_col) != 0 && 
        done[new_row * cols + new_col] == 0) {
            find_max_length_at_cell(done, m, rows, cols, new_row, new_col, size);
         }
    }
}


int main(int args, char** argv) {
    
    int m[] = {
        1, 1, 0, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 0, 1, 1
    };

    int done[] = {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    };

    int row = -1;
    int col = -1;
    int size = 0;

    for(int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int size_ij = 0;
            find_max_length_at_cell(done, m, 5, 5, i, j, size_ij);
            if (size_ij > size) {
                row = i;
                col = j;
                size = size_ij;
            }
        }
    }

    printf("row: %d; col: %d; size: %d\n", row, col, size);

}