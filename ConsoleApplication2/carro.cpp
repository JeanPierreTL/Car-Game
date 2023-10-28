#include "pch.h"
#include "carro.h"
#include <iostream>
#include <windows.h>
#include "utilidades.h"

carro::carro(int initialPos) : carPos(initialPos) {
    car[0][0] = ' ';
    car[0][1] = 'X';
    car[0][2] = 'X';
    car[0][3] = ' ';
    car[1][0] = 'X';
    car[1][1] = 'X';
    car[1][2] = 'X';
    car[1][3] = 'X';
    car[2][0] = ' ';
    car[2][1] = 'X';
    car[2][2] = 'X';
    car[2][3] = ' ';
    car[3][0] = 'X';
    car[3][1] = 'X';
    car[3][2] = 'X';
    car[3][3] = 'X';
}

carro::~carro() {
    // Destructor
}

void carro::draw() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            setCursorPosition(j + carPos, i + 22);
            std::cout << car[i][j];
        }
    }
}

void carro::erase() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            setCursorPosition(j + carPos, i + 22);
            std::cout << " ";
        }
    }
}

void carro::moveLeft() {
    if (carPos > 18)
        carPos -= 4;
}

void carro::moveRight() {
    if (carPos < 50)
        carPos += 4;
}
