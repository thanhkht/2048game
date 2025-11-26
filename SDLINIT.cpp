#include "SDLINIT.h"
#include "Global.h"
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("Loi SDL: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Loi tao cua so: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Loi tao renderer: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
                {
                    printf("Loi SDL_image: %s\n", IMG_GetError());
                    success = false;
                }
                if (TTF_Init() == -1)
                {
                    printf("Loi SDL_ttf: %s\n", TTF_GetError());
                    success = false;
                }
                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
                {
                    printf("Loi SDL_mixer: %s\n", Mix_GetError());
                    success = false;
                }
            }
        }
    }
    return success;
}
