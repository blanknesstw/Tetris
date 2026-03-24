#include "game.h"
#include <conio.h>
#include <iostream>
#include <chrono>
#include <thread>

Game::Game() {
    score = 0;
    running = true;
}

void Game::run() {
    auto lastDrop = std::chrono::steady_clock::now();

    while (running) {
        input();

        auto now = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastDrop).count();
        if (diff > 500) {
            update();
            lastDrop = now;
        }

        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

void Game::input() {
    if (_kbhit()) {
        int ch = _getch();
        if (ch == 'a') current.moveLeft(board);
        if (ch == 'd') current.moveRight(board);
        if (ch == 's') current.moveDown(board);
        if (ch == 'w') current.rotate(board);
        if (ch == 224 || ch == 0) {
            ch = _getch();
            if (ch == 75) current.moveLeft(board);
            if (ch == 77) current.moveRight(board);
            if (ch == 80) current.moveDown(board);
            if (ch == 72) current.rotate(board);
        }
    }
}

void Game::update() {
    if (!current.moveDown(board)) {
        current.lock(board);
        int lines = board.clearLines();
        score += lines * 100;
        current.spawn();

        if (!current.isValidPosition(board)) {
            running = false;
            std::cout << "Game Over! Score: " << score << "\n";
            std::cout << "U ARE GAY" << score << "\n";
            while (_getch() != ' ');  // 等到按下空白鍵
        }
    }
}

void Game::render() {
    std::cout << "\033[H";
    std::cout << "Score: " << score << "\n";
    board.print();
}