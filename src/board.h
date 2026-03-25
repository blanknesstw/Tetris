#pragma once
#include <iostream>

const int ROWS = 20;
const int COLS = 10;

class Piece;  // 前向宣告，告訴編譯器 Piece 存在

class Board {
public:
    int grid[ROWS][COLS];

    Board();
    void clear();
    bool isValid(int row, int col);
    int clearLines();
    void print(Piece& p);  // 用參考
};