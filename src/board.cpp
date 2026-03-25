#include "board.h"
#include "piece.h"

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

void Board::print(Piece& p) {
    int mask = SHAPES[p.type][p.rotation];
    for (int r = 0; r < ROWS; r++) {
        std::cout << "|";
        for (int c = 0; c < COLS; c++) {
            int i = (r - p.y) * 4 + (c - p.x);
            bool isPiece = (r >= p.y && r < p.y + 4 && c >= p.x && c < p.x + 4)
                && (i >= 0 && i < 16)
                && (mask & (1 << (15 - i)));
            if (isPiece)
                std::cout << "#";
            else
                std::cout << (grid[r][c] ? "#" : " ");
        }
        std::cout << "|\n";
    }
    std::cout << "+----------+\n";
}