#include "classes.h"
#include <SDL_ttf.h>
#include <SDL.h>
#include "globals.h"
#include <time.h>
void Game::start()
{
	ball.setXPos((SCREEN_WIDTH - BALL_WIDTH) / 2);
	ball.setYPos((SCREEN_HEIGHT - BALL_WIDTH) / 2);
	srand(time(NULL));
	int xrandy = ((rand() % 2) + 1) / 2;
	int yrandy = ((rand() % 2) + 1) / 2;
	if (xrandy == 0)
	{
		ball.setXVel(BALL_VEL * -1);
		game.setHitLeftLast(false);
	}
	else
	{
		ball.setXVel(BALL_VEL);
		game.setHitLeftLast(true);
	}
	if (yrandy == 0)
	{
		ball.setYVel(BALL_VEL * -1);
	}
	else
	{
		ball.setYVel(BALL_VEL);
	}
	
}

void Game::showText()
{
	if (!isRunning)
	{
		gameText.renderFromText("PRESS SPACE TO BEGIN GAME", textColor);
		gameText.render((SCREEN_WIDTH - gameText.getWidth()) / 2, 20);
		controlsText.renderFromText("P1: W - UP; S - DOWN; P2: O - UP; K - DOWN", textColor);
		controlsText.render((SCREEN_WIDTH - controlsText.getWidth()) / 2, 65);
		if (lScore != 0 || rScore != 0)
		{
			score.str("");
			score << lScore << " : " << rScore;
			scoreText.renderFromText(score.str().c_str(), textColor);
			scoreText.render((SCREEN_WIDTH - scoreText.getWidth()) / 2, 100);
		}
	}
	else 
	{
		score.str("");
		score << lScore << " : " << rScore;
		scoreText.renderFromText(score.str().c_str(), textColor);
		scoreText.render((SCREEN_WIDTH - scoreText.getWidth()) / 2, 20);
	}
}

void Game::run()
{
	SDL_SetRenderDrawColor(rRender, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(rRender);
	if (!isRunning)
	{
		currentKeyStates = SDL_GetKeyboardState(NULL);
		if (currentKeyStates[SDL_SCANCODE_SPACE])
		{
			isRunning = true;
			start();
		}
		showText();
		
	}
	else
	{
		left.handleInput('l');
		right.handleInput('r');
		left.move();
		right.move();
		ball.move();
		left.render('l');
		right.render('r');
		ball.render();
		showText();


	}
	SDL_RenderPresent(rRender);
}

void Game::playerScore()
{
	if (ball.getX() < SCREEN_WIDTH / 2)
	{
		rScore++;
	}
	else
	{
		lScore++;
	}
	isRunning = false;
}

void Game::setHitLeftLast(bool y)
{
	hitLeftLast = y;
}

bool Game::getHitLeftLast()
{
	return hitLeftLast;
}

Game::Game()
{
	lScore = 0;
	rScore = 0;
	isRunning = false;
	hitLeftLast = true;

}