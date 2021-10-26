#include "functions.h"
#include <SDL.h>
#include "constants.h"
#include "globals.h"
#include "classes.h"
#include <SDL_ttf.h>

bool checkCollision(int x, int y)
{
	if (game.getHitLeftLast())
	{
		if ((x >= (RPADDLEX - BALL_WIDTH)) && (y <= right.getY() + PADDLE_HEIGHT) && (y >= right.getY() - BALL_HEIGHT))
		{
			game.setHitLeftLast(false);
			return true;
		}
		return false;
	}
	else
	{
		if ((x - (LPADDLEX + PADDLE_WIDTH) <= 0) && (y <= left.getY() + PADDLE_HEIGHT) && (y >= left.getY() - BALL_HEIGHT))
		{
			game.setHitLeftLast(true);
			return true;
		}
		return false;
	}
}
bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		printf("failed to init everything");
		return false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("failed to set hint");
			return false;
		}
		rWindow = SDL_CreateWindow("Pong by Ricky", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (rWindow == NULL)
		{
			printf("failed to create window");
			return false;
		}
		else
		{
			rRender = SDL_CreateRenderer(rWindow, -1, SDL_RENDERER_ACCELERATED);
			if (rRender == NULL)
			{
				printf("failed to create renderer");
				return false;
			}
			else
			{
				SDL_SetRenderDrawColor(rRender, 0xFF, 0xFF, 0xFF, 0xFF);
			}
			if (TTF_Init() == -1)
			{
				printf("not working");
			}
		}

	}
	printf("im here!");
	return true;
}

void close()
{
	SDL_DestroyWindow(rWindow);
	rWindow = NULL;
	SDL_DestroyRenderer(rRender);
	rRender = NULL;
}

bool loadFiles()
{
	rFont = TTF_OpenFont("./pongfont.ttf", 35);
	if (rFont == NULL)
	{
		printf("cant load pongfont%s", TTF_GetError());
		return false;

	}
	return true;
}