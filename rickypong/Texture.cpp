#include "classes.h"
#include <SDL_ttf.h>
#include "globals.h"

void Texture::renderFromText(std::string text, SDL_Color color)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid(rFont, text.c_str(), color);
	tTexture = SDL_CreateTextureFromSurface(rRender, textSurface);
	tWidth = textSurface->w;
	tHeight = textSurface->h;
}

void Texture::render(int x, int y)
{
	SDL_Rect renderQuad = { x, y, tWidth, tHeight };
	SDL_RenderCopy(rRender, tTexture, NULL, &renderQuad);
}

int Texture::getWidth()
{
	return tWidth;
}

int Texture::getHeight()
{
	return tHeight;
}