#include "piece.h"
#include <cstdlib>
#include <ctime>

Piece::Piece() {
    srand(time(0));
    spawn();
}

void Piece::spawn() {   //生成新方塊
    type = rand() % 7;  // 隨機選 0~6
    rotation = 0;
    x = 3;  // 從中間生成
    y = 0;  // 從頂部生成
}

bool Piece::moveLeft(Board& b) {    //左右移動，先移動，如果撞牆就移回來
    x--;
    if (!isValidPosition(b)) { x++; return false; }
    return true;
}

bool Piece::moveRight(Board& b) {   //左右移動，先移動，如果撞牆就移回來
    x++;
    if (!isValidPosition(b)) { x--; return false; }
    return true;
}

bool Piece::moveDown(Board& b) {    //往下移動，移動失敗就移回來，回傳 false 代表碰底了
    y++;
    if (!isValidPosition(b)) { y--; return false; }
    return true;
}

bool Piece::rotate(Board& b) {
    int old = rotation;
    rotation = (rotation + 1) % 4;
    if (!isValidPosition(b)) { rotation = old; return false; }
    return true;
}

void Piece::lock(Board& b) {
    int mask = SHAPES[type][rotation];
    for (int i = 0; i < 16; i++) {
        if (!(mask & (1 << (15 - i)))) continue;
        int row = y + i / 4;
        int col = x + i % 4;
        if (row >= 0) b.grid[row][col] = type + 1;
    }
}

bool Piece::isValidPosition(Board& b) {
    int mask = SHAPES[type][rotation];
    for (int i = 0; i < 16; i++) {
        if (!(mask & (1 << (15 - i)))) continue;
        int row = y + i / 4;
        int col = x + i % 4;
        if (!b.isValid(row, col)) return false;
    }
    return true;
}