#include "pch.h"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "game.h"

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    game game;
    game.start();
    return 0;
}
