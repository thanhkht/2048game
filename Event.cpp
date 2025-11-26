#include "Event.h"
#include "Global.h"
#include "Logic.h"
#include "Gamemanager.h"  
#include <fstream>

extern GameManager* gGame;

void handleEvent(SDL_Event* e)
{
	//neu su kien chuot xay ra
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
	
		bool inside = true;
		if (x < 415)
		{
			inside = false;
		}
		else if (x > 415 + 106)
		{
            inside = false;
		}
		else if (y < 119)
		{
			inside = false;
		}
		else if (y > 119 + 34)
		{
			inside = false;
		}

		//chuot ngoai nut
		if (!inside)
		{
			buttonIsActive = false;
		}
		else
		{
			//cac hoat dong trong nut cua chuot
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				buttonIsActive = true;
				break;

			case SDL_MOUSEBUTTONDOWN:
				buttonIsActive = true;
				for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) gGame->board[i][j] = 0;
				gGame->score = 0;
				randomtile(gGame->board, 1);
				randomtile(gGame->board, 1);
				gGame->win = false;
				gGame->lose = false;
				gGame->winSound = false;
                gGame->loseSound = false;
				break;

			case SDL_MOUSEBUTTONUP:
				buttonIsActive = false;
				break;
			}
		}
	}
}

//doc diem tu file de co diem cao nhat
void savebestscorein()
{
	std::ifstream file;
	file.open("bestscore.txt");
	int temp;
	file >> temp;
	if (temp > gGame->best) gGame->best = temp;
	file.close();
}
//luu diem cao nhat vao file
void savebestscoreout()
{
	std::ifstream file;
	file.open("bestscore.txt");
	int temp;
	file >> temp;
	if (temp < gGame->best)
	{
		file.close();
		std::ofstream file;
		file.open("bestscore.txt");
		file << gGame->best;
	}
}
