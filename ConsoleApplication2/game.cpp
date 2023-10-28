#include "pch.h"
#include "game.h"
#include "carro.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "utilidades.h"

game::game() : score(0) {
    playerCar = new carro(WIN_WIDTH / 2);
    for (int i = 0; i < 3; i++) {
        enemies[i] = new enemy();
    }
}

game::~game() {
    delete playerCar;
    for (int i = 0; i < 3; i++) {
        delete enemies[i];
    }
}

void game::setCursorPosition(int x, int y) {
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void game::setCursorVisibility(bool visible, DWORD size) {
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &lpCursor);
}

void game::drawBorder() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < 17; j++) {
            setCursorPosition(0 + j, i);
            std::cout << "||";
            setCursorPosition(WIN_WIDTH - j, i);
            std::cout << "||";
        }
    }
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        setCursorPosition(SCREEN_WIDTH, i);
        std::cout << "||";
    }
}

void game::updateScore() {
    setCursorPosition(WIN_WIDTH + 7, 5);
    std::cout << "Score: " << score << std::endl;
}

bool game::collision() {
    for (int i = 0; i < 3; i++) {
        if (enemies[i]->enemyY + 4 >= 23) {
            if (enemies[i]->enemyX + 4 - playerCar->carPos >= 0 && enemies[i]->enemyX + 4 - playerCar->carPos < 9) {
                return true;
            }
        }
    }
    return false;
}

void game::gameover() {
    system("cls");
    std::cout << std::endl;
    std::cout << "\t\t--------------------------" << std::endl;
    std::cout << "\t\t-------- Game Over -------" << std::endl;
    std::cout << "\t\t--------------------------" << std::endl << std::endl;
    std::cout << "\t\tPress any key to go back to the menu.";
    _getch();
}

void game::start() {
    score = 0;
    enemies[0]->enemyFlag = true;

    system("cls");
    drawBorder();
    updateScore();

    for (int i = 0; i < 3; i++) {
        enemies[i]->generate();
    }

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a' || ch == 'A') {
                playerCar->moveLeft();
            }
            if (ch == 'd' || ch == 'D') {
                playerCar->moveRight();
            }
            if (ch == 27) {
                break;
            }
        }

        playerCar->draw();
        for (int i = 0; i < 3; i++) {
            enemies[i]->draw();
        }

        if (collision()) {
            gameover();
            return;
        }
        Sleep(200);  // Aumenta este valor para hacer el juego más lento
        playerCar->erase();
        for (int i = 0; i < 3; i++) {
            enemies[i]->erase();
        }

        for (int i = 0; i < 3; i++) {
            if (enemies[i]->enemyY == 10 && !enemies[(i + 1) % 3]->enemyFlag) {
                enemies[(i + 1) % 3]->enemyFlag = true;
            }
            if (enemies[i]->enemyFlag) {
                enemies[i]->enemyY += 1;
            }
            if (enemies[i]->enemyY > SCREEN_HEIGHT - 4) {
                enemies[i]->reset();
                score++;
                updateScore();
            }
        }
    }
}

