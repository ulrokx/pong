#pragma once
#include <SDL.h>
bool checkCollision(int x, int y);
bool init();
bool loadFiles();
void close();
void handleCollision();