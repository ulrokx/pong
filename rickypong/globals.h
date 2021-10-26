#pragma once
#include <SDL.h>
#include "classes.h"
#include <SDL_ttf.h>

extern SDL_Window* rWindow;
extern SDL_Renderer* rRender;
extern TTF_Font* rFont;
extern bool quit;
extern Paddle left;
extern Paddle right;
extern Ball ball;
extern SDL_Event e;
extern Timer fpsTimer;
extern Timer capTimer;
extern SDL_Color textColor;
extern const Uint8* currentKeyStates;
extern Game game;
