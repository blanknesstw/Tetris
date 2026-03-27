#pragma once
#include <iostream>

const int ROWS = 20;
const int COLS = 10;

class Board {
public:
    int grid[ROWS][COLS];

    Board();          // 初始化盤面
    void clear();     // 清空盤面
    bool isValid(int row, int col);  // 檢查格子是否可用
    int clearLines(); // 消行，回傳消了幾行
    void print();     // 印出盤面
};