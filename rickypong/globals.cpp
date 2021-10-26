#include "globals.h"
#include "classes.h"

SDL_Window* rWindow = NULL;
SDL_Renderer* rRender = NULL;
bool quit = false;
Timer fpsTimer;
Timer capTimer;
TTF_Font* rFont = NULL;
Ball ball;
Paddle left;
Paddle right;
SDL_Color textColor = { 0x00, 0x00, 0x00, 0xFF };
const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
Game game;