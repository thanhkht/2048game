#include "Media.h"
#include "Global.h" 

extern Tile TextureTile0, TextureTile2, TextureTile4, TextureTile8,
            TextureTile16, TextureTile32, TextureTile64, TextureTile128,
            TextureTile256, TextureTile512, TextureTile1024, TextureTile2048;

extern LTexture gBackgroundTexture;
extern LTexture Button, ButtonDown;
extern LTexture Score, Best;
extern LTexture youwin, youlose;
extern TTF_Font* gFont;
extern Mix_Chunk* gwin;
extern Mix_Chunk* glose;
extern Mix_Chunk* gmove;
 
bool loadMedia() {

    TextureTile0.loadFromFile("res/0.png");
    TextureTile2.loadFromFile("res/2.png");
    TextureTile4.loadFromFile("res/4.png");
    TextureTile8.loadFromFile("res/8.png");
    TextureTile16.loadFromFile("res/16.png");
    TextureTile32.loadFromFile("res/32.png");
    TextureTile64.loadFromFile("res/64.png");
    TextureTile128.loadFromFile("res/128.png");
    TextureTile256.loadFromFile("res/256.png");
    TextureTile512.loadFromFile("res/512.png");
    TextureTile1024.loadFromFile("res/1024.png");
     TextureTile2048.loadFromFile("res/2048.png");

    gBackgroundTexture.loadFromFile("res/background.png");
    youwin.loadFromFile("res/youwin.png");
    youlose.loadFromFile("res/youlose.png");
    Button.loadFromFile("res/button.png");
    ButtonDown.loadFromFile("res/buttondown.png");
    Score.loadFromFile("res/scorebutton.png");
    Best.loadFromFile("res/bestbutton.png");

    gFont = TTF_OpenFont("res/arial.ttf", 20);
    
    gwin   = Mix_LoadWAV("res/win music.wav");
    glose  = Mix_LoadWAV("res/lose music.wav");
    gmove  = Mix_LoadWAV("res/move.wav");
    return true;
}

