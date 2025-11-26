#ifndef GLOBAL_H
#define GLOBAL_H

#include "Gamemanager.h"
#include "Tile.h"
#include "LTexture.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

extern Tile TextureTile0, TextureTile2, TextureTile4, TextureTile8,
            TextureTile16, TextureTile32, TextureTile64,
            TextureTile128, TextureTile256, TextureTile512,
            TextureTile1024, TextureTile2048;

extern LTexture gBackgroundTexture;
extern LTexture Button, ButtonDown;
extern LTexture ScoreTexture, BestTexture;
extern LTexture Score, Best;
extern LTexture youwin, youlose;
extern TTF_Font* gFont;
extern Mix_Chunk* gwin;
extern Mix_Chunk* glose;
extern Mix_Chunk* gmove;

extern GameManager* gGame;

extern bool buttonIsActive;

#endif

