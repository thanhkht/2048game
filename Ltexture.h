#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <cstdio>

class LTexture
{
public:
	LTexture();
	~LTexture();
	bool loadFromFile(std::string path);
	void free();
	void render(int x, int y);
	int getWidth();
	int getHeight();
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
};

#endif

