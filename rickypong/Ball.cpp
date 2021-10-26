#include "classes.h"
#include "constants.h"
#include "functions.h"
#include "globals.h"

Ball::Ball()
{
	bPosX = (SCREEN_WIDTH - BALL_WIDTH) / 2;
	bPosY = (SCREEN_HEIGHT - BALL_HEIGHT) / 2;
	bVelX = 0;
	bVelY = 0;
}

void Ball::move() {
	bPosY += bVelY;
	if (bPosY < 0 || bPosY > SCREEN_HEIGHT - BALL_HEIGHT)
	{
		bPosY -= bVelY;
		bVelY *= -1;
	}
	bPosX += bVelX;
	if (bPosX <= LPADDLEX || bPosX >= SCREEN_WIDTH - LPADDLEX)
	{
		game.playerScore();
	}
	if (checkCollision(bPosX, bPosY))
	{
		bPosX -= bVelX;
		bVelX *= -1;
	}

}

int Ball::getX()
{
	return bPosX;
}

int Ball::getY()
{
	return bPosY;
}

void Ball::render()
{
	ball = { bPosX, bPosY, BALL_WIDTH, BALL_HEIGHT };
	SDL_SetRenderDrawColor(rRender, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(rRender, &ball);
}

void Ball::setXPos(int x)
{
	bPosX = x;
}

void Ball::setYPos(int y)
{
	bPosY = y;
}

void Ball::setXVel(int x)
{
	bVelX = x;
}

void Ball::setYVel(int y)
{
	bVelY = y;
}