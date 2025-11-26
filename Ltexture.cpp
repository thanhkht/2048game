#include "Ltexture.h"
extern SDL_Renderer* gRenderer;
extern TTF_Font* gFont;
LTexture::LTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile(std::string path)
{
	free();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Không the tai anh %s! Loi SDL_image: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
	
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface); // Tao texture tu surface
		if (newTexture == NULL)
		{
			printf("Không the tao texture tu anh %s! Loi SDL: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(int x, int y)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
}
int LTexture::getWidth()
{
	return mWidth;
}
int LTexture::getHeight()
{
	return mHeight;
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	free();
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface != NULL)
	{
		
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL)
		{
			printf("Không the tao texture tu van ban. Loi SDL: %s\n", SDL_GetError());
		}
		else
		{
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}
		
		SDL_FreeSurface(textSurface);
	}
	else
	{
		printf("Không the tao surface tu chu. Loi SDL_ttf: %s\n", TTF_GetError());
	}
	return mTexture != NULL;
}
