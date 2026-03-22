#pragma once
#include "board.h"

// 7 種方塊用 4x4 bitmask 表示
const int SHAPES[7][4] = {
    {0x0F00, 0x2222, 0x00F0, 0x4444}, // I
    {0x8E00, 0x6440, 0x0E20, 0x44C0}, // J
    {0x2E00, 0x4460, 0x0E80, 0xC440}, // L
    {0x6600, 0x6600, 0x6600, 0x6600}, // O
    {0x6C00, 0x4620, 0x06C0, 0x8C40}, // S
    {0x0E40, 0x4C40, 0x4E00, 0x4640}, // T
    {0xC600, 0x2640, 0x0C60, 0x4C80}, // Z
};

class Piece {
public:
    int type;     // 方塊種類 0~6
    int rotation; // 旋轉狀態 0~3
    int x, y;     // 在盤面上的位置

    Piece();
    void spawn();             // 隨機生成新方塊
    bool moveLeft(Board& b);  // 向左移
    bool moveRight(Board& b); // 向右移
    bool moveDown(Board& b);  // 向下移
    bool rotate(Board& b);    // 旋轉
    void lock(Board& b);      // 固定到盤面
    void print(Board& b);     // 印出目前方塊位置
    bool isValidPosition(Board& b);  // 加在 public 裡面
};
