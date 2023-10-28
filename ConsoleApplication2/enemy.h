#include "pch.h"
#pragma once
#ifndef ENEMY_H
#define ENEMY_H

class enemy {
public:
    enemy();
    ~enemy();
    void generate();
    void draw();
    void erase();
    void reset();


    static const int ANCHO_ENEMIGO = 4;
    int enemyY;
    int enemyX;
    bool enemyFlag;
};

#endif


