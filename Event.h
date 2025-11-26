#ifndef EVENT_H
#define EVENT_H
#include <fstream>
#include <SDL.h>
#include "Global.h" 

void handleEvent(SDL_Event* e);
void savebestscorein();
void savebestscoreout();

#endif 
