#include "classes.h"
 
Uint32 Timer::getTicks()
{
	return SDL_GetTicks() - startTime;
}

void Timer::start()
{
	startTime = SDL_GetTicks();
}