#include "board.h"

Board::Board() {
    clear();
}

void Board::clear() {
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            grid[r][c] = 0;
}

bool Board::isValid(int row, int col) {
    if (col < 0 || col >= COLS) return false;  // 左右邊界
    if (row >= ROWS) return false;             // 下邊界
    if (row >= 0 && grid[row][col]) return false; // 已有方塊
    return true;
}

int Board::clearLines() {
    int count = 0;
    for (int r = ROWS - 1; r >= 0; r--) {
        bool full = true;
        for (int c = 0; c < COLS; c++)
            if (!grid[r][c]) { full = false; break; }

        if (full) {
            // 把上面的行往下移
            for (int rr = r; rr > 0; rr--)
                for (int c = 0; c < COLS; c++)
                    grid[rr][c] = grid[rr - 1][c];
            // 最頂行清空
            for (int c = 0; c < COLS; c++)
                grid[0][c] = 0;
            count++;
            r++; // 重新檢查同一行
        }
    }
    return count;
}

void Board::print() {
    for (int r = 0; r < ROWS; r++) {
        std::cout << "|";
        for (int c = 0; c < COLS; c++)
            std::cout << (grid[r][c] ? "#" : " ");
        std::cout << "|\n";
    }
    std::cout << "+----------+\n";
}