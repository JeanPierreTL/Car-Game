#include "pch.h"
#include "enemy.h"
#include <iostream>
#include <windows.h>
#include "utilidades.h"
enemy::enemy() : enemyY(1), enemyX(0), enemyFlag(false) {
}

enemy::~enemy() {
    // Destructor
}

void enemy::generate() {
    enemyX = 17 + rand() % (33);
}

void enemy::draw() {
    if (enemyFlag) {
        setCursorPosition(enemyX, enemyY);
        std::cout << "****";
        setCursorPosition(enemyX, enemyY + 1);
        std::cout << " ** ";
        setCursorPosition(enemyX, enemyY + 2);
        std::cout << "****";
        setCursorPosition(enemyX, enemyY + 3);
        std::cout << " ** ";
    }
}

void enemy::erase() {
    if (enemyFlag) {
        setCursorPosition(enemyX, enemyY);
        std::cout << "    ";
        setCursorPosition(enemyX, enemyY + 1);
        std::cout << "    ";
        setCursorPosition(enemyX, enemyY + 2);
        std::cout << "    ";
        setCursorPosition(enemyX, enemyY + 3);
        std::cout << "    ";
    }
}

void enemy::reset() {
    erase();
    enemyY = 1;
    generate();
}

