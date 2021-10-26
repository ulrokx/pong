#include "classes.h"
#include <SDL.h>
#include "globals.h"

void Paddle::handleInput(char a) {
	currentKeyStates = SDL_GetKeyboardState(NULL);
	pVelY = 0;
	if (a == 'r') {
		if (currentKeyStates[SDL_SCANCODE_O] && !currentKeyStates[SDL_SCANCODE_K])
		{
			pVelY = PADDLE_VEL * -1;
		}
		else if (currentKeyStates[SDL_SCANCODE_K] && !currentKeyStates[SDL_SCANCODE_O])
		{
			pVelY = PADDLE_VEL;
		}
	}
	else
	{
		if (currentKeyStates[SDL_SCANCODE_W] && !currentKeyStates[SDL_SCANCODE_S])
		{
			pVelY = PADDLE_VEL * -1;
		}
		else if (currentKeyStates[SDL_SCANCODE_S] && !currentKeyStates[SDL_SCANCODE_W])
		{
			pVelY = PADDLE_VEL;
		}
	}
}

void Paddle::move()
{
	pPosY += pVelY;
	if ((pPosY < 0) || (pPosY + PADDLE_HEIGHT > SCREEN_HEIGHT))
	{
		pPosY -= pVelY;
	}
}

void Paddle::render(char a)
{
	int paddleX;
	if (a == 'l')
	{
		paddleX = LPADDLEX;
	}
	else
	{
		paddleX = RPADDLEX;
	}
	paddle = { paddleX, pPosY, PADDLE_WIDTH, PADDLE_HEIGHT };
	SDL_SetRenderDrawColor(rRender, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(rRender, &paddle);
}

int Paddle::getX()
{
	return pPosX;
}

int Paddle::getY()
{
	return pPosY;
}

Paddle::Paddle()
{
	pPosY = (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2;
}

int Paddle::getVel()
{
	return pVelY;
}