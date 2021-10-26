#include "functions.h"
#include "globals.h"
#include "classes.h"
#include "constants.h"
#include <stdio.h>
int main(int argc, char* args[])
{
	if (!init())
	{
		printf("failed to init");
	}
	else
	{
		if (!loadFiles())
		{
			printf("didnt load files");
		}
		else {
			{
				SDL_Event e;
				while (!quit)
				{
					capTimer.start();
					while (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_QUIT)
						{
							quit = true;
						}
					}
					game.run();
					int frameTicks = capTimer.getTicks();
					if (frameTicks < SCREEN_TICKS_PER_FRAME)
					{
						SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
					}
				}
			}
			return 0;
		}
	}
}