#pragma once
#include <SDL.h>
#include <stdio.h>
#include "constants.h"
#include <string>
#include <sstream>

class Ball
{
public:
	Ball();
	void move();
	int getX();
	int getY();
	void render();
	void setXPos(int x);
	void setYPos(int y);
	void setXVel(int x);
	void setYVel(int y);
private:
	int bPosX, bPosY;
	int bVelX, bVelY;
	SDL_Rect ball;
};

class Paddle
{
public:
	Paddle();
	void handleInput(char a);
	void move();
	void render(char a);
	int getX();
	int getY();
	int getVel();
private:
	int pPosX;
	int pPosY, pVelY;
	SDL_Rect paddle;
};

class Timer
{
public:
	void start();
	Uint32 getTicks();
private:
	Uint32 startTime;
};


class Texture
{
public:
	void renderFromText(std::string text, SDL_Color color);
	void render(int x, int y);
	int getWidth();
	int getHeight();
private:
	int tWidth;
	int tHeight;
	SDL_Texture* tTexture;
};


class Game
{
public:
	void start();
	void showText();
	void run();
	void playerScore();
	void setHitLeftLast(bool y);
	bool getHitLeftLast();
	Game();
private:
	int lScore;
	int rScore;
	bool isRunning;
	bool hitLeftLast;
	Texture gameText;
	Texture scoreText;
	Texture controlsText;
	std::stringstream score;
};
