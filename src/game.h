#pragma once
#include "board.h"
#include "piece.h"

class Game {
public:
    Board board;
    Piece current;
    int score;
    bool running;

    Game();
    void run();       // 主迴圈
    void input();     // 處理鍵盤輸入
    void update();    // 更新遊戲狀態
    void render();    // 渲染畫面
};