#include "pch.h"
#include <windows.h>

#pragma once
#ifndef CAR_H
#define CAR_H

class carro {
public:
    carro(int initialPos);
    ~carro();
    void draw();
    void erase();
    void moveLeft();
    void moveRight();


    static const int ANCHO_CARRO = 4;
    int carPos;
    char car[4][4];
};

#endif


