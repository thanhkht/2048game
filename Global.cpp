#include "Global.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

Tile TextureTile0, TextureTile2, TextureTile4, TextureTile8,
     TextureTile16, TextureTile32, TextureTile64,
     TextureTile128, TextureTile256, TextureTile512,
     TextureTile1024, TextureTile2048;

LTexture gBackgroundTexture;
LTexture Button, ButtonDown;
LTexture ScoreTexture, BestTexture;
LTexture Score, Best;
LTexture youwin, youlose;
TTF_Font* gFont = NULL;
Mix_Chunk* gwin = NULL;
Mix_Chunk* glose = NULL;
Mix_Chunk* gmove = NULL;

GameManager* gGame = NULL;

bool buttonIsActive = false;

