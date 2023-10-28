#pragma once
#ifndef GAME_H
#define GAME_H

#include "carro.h"
#include "enemy.h"
#include <windows.h>


class game {
public:
    game();
    ~game();
    void start();

private:
    static const int SCREEN_WIDTH = 90; // Define el ancho de la pantalla
    static const int SCREEN_HEIGHT = 26; // Define la altura de la pantalla
    static const int WIN_WIDTH = 70; // Define la anchura de la ventana de juego
    carro* playerCar;
    enemy* enemies[3];
    int score;

    void setCursorPosition(int x, int y);
    void setCursorVisibility(bool visible, DWORD size);
    void drawBorder();
    void updateScore();
    bool collision();
    void gameover();
};

#endif


