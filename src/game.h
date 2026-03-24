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
    void run();       
    void input();     
    void update();    
    void render();   
};