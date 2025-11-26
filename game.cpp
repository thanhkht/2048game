#include <SDL.h>
#include <SDL_image.h>
#include<SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include<vector>
#include <SDL_ttf.h>
#include <sstream>
#include<fstream>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;



void close();



// Giai phóng tai nguyen
void close() {
     
    TextureTile0.free(); TextureTile2.free(); TextureTile4.free(); TextureTile8.free();
    TextureTile16.free(); TextureTile32.free(); TextureTile64.free();
    TextureTile128.free(); TextureTile256.free(); TextureTile512.free();
    TextureTile1024.free();  TextureTile2048.free();

    gBackgroundTexture.free();
    Button.free(); ButtonDown.free();
    Score.free(); Best.free();
    youwin.free(); youlose.free();
    
    Mix_FreeChunk(gwin);
    Mix_FreeChunk(glose);
    Mix_FreeChunk(gmove);
    TTF_CloseFont(gFont);

    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    // Thoát các thu vien 
    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}








void play()
{
	//khoi tao SDL va tao cua so game

	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media

		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;
			//xu ly su kien
			GameManager gameInstance;
			gGame=&gameInstance;

			SDL_Event e;
			gGame->board = new int* [4]; // Khoi tao board
            for (int i = 0; i < 4; i++) gGame->board[i] = new int[4];
            gGame->thepreviousboard = new int* [4]; // Khoi tao previousboard
            for (int i = 0; i < 4; i++) gGame->thepreviousboard[i] = new int[4];
    
            for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) gGame->board[i][j] = 0;
            for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) gGame->thepreviousboard[i][j] = 0;
			randomtile(gGame->board, 1);
			randomtile(gGame->board, 1);
			std::stringstream scoretext, bestscoretext;
		
			while (!quit)
			{
				//xu ly cac su kien tren hang doi
				while (SDL_PollEvent(&e) != 0)
				{
					handleEvent(&e);
					gGame->score += gGame->scorepermove;
					gGame->scorepermove = 0;
					//neu nguoi dung thoat game
					if (e.type == SDL_QUIT)
					{
                    quit = true;
					}
					else if (e.type == SDL_KEYDOWN && gGame->win == false && gGame->lose == false)
					{

						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
						    moveup(gGame->board, gGame->scorepermove);
						    if (checktheresemblance(gGame->board, gGame->thepreviousboard) == false) {
						        randomtile(gGame->board, 0);
						        Mix_PlayChannel(-1, gmove, 0);  
						    }
						    break;

						case SDLK_DOWN:
						    movedown(gGame->board, gGame->scorepermove);
						    if (checktheresemblance(gGame->board, gGame->thepreviousboard) == false) {
						        randomtile(gGame->board, 0);
						        Mix_PlayChannel(-1, gmove, 0);  
						    }
						    break;
						
						case SDLK_LEFT:
						    moveleft(gGame->board, gGame->scorepermove);
						    if (checktheresemblance(gGame->board, gGame->thepreviousboard) == false) {
						        randomtile(gGame->board, 0);
						        Mix_PlayChannel(-1, gmove, 0);  
						    }
						    break;
						
						case SDLK_RIGHT:
						    moveright(gGame->board, gGame->scorepermove);
						    if (checktheresemblance(gGame->board, gGame->thepreviousboard) == false) {
						        randomtile(gGame->board, 0);
						        Mix_PlayChannel(-1, gmove, 0);  
						    }
						    break;
						case SDLK_w:  // Nhan W de tao màn win
						    gGame->board[0][0] = 2048;
						    gGame->board[0][1] = 512;
						    gGame->board[0][2] = 256;
						    gGame->board[0][3] = 128;
						    gGame->board[1][0] = 64;
						    gGame->board[1][1] = 32;
						    gGame->board[1][2] = 16;
						    gGame->board[1][3] = 8;
						    gGame->board[2][0] = 4;
						    gGame->board[2][1] = 2;
						    gGame->board[2][2] = 4;
						    gGame->board[2][3] = 2;
						    gGame->board[3][0] = 0;
						    gGame->board[3][1] = 0;
						    gGame->board[3][2] = 2;
						    gGame->board[3][3] = 4;
						    gGame->score = 28756;
						    gGame->win = true;
						    break;
						case SDLK_l:  // Nhan L de tao màn thua
						    gGame->board[0][0] = 512;
						    gGame->board[0][1] = 256;
						    gGame->board[0][2] = 128;
						    gGame->board[0][3] = 64;
						    gGame->board[1][0] = 256;
						    gGame->board[1][1] = 128;
						    gGame->board[1][2] = 64;
						    gGame->board[1][3] = 32;
						    gGame->board[2][0] = 128;
						    gGame->board[2][1] = 64;
						    gGame->board[2][2] = 32;
						    gGame->board[2][3] = 16;
						    gGame->board[3][0] = 64;
						    gGame->board[3][1] = 32;
						    gGame->board[3][2] = 16;
						    gGame->board[3][3] = 8;
						    gGame->score = 15248;
						    gGame->lose = true;
						    break;
				
						}
						updateboard(gGame->board, gGame->thepreviousboard);
					}
				}
				scoretext.str("");
				scoretext << gGame->score;
				bestscoretext.str("");
				bestscoretext << gGame->best;
				
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);
				ScoreTexture.loadFromRenderedText(scoretext.str().c_str(), textColor);
				BestTexture.loadFromRenderedText(bestscoretext.str().c_str(), textColor);
				gBackgroundTexture.render(0, 0);
				if (buttonIsActive) {
                    ButtonDown.render(415, 119); }// Ve trang thái Hover/Nhan (màu khác)
                else{
                    Button.render(415, 119); // Ve trang thái Mac dinh
					}    
				Best.render(418, 33);
				Score.render(313, 33);
                savebestscorein();
				savebestscoreout() ;
				if (gGame->score > gGame->best) gGame->best = gGame->score;
				if (gGame->score < 10) ScoreTexture.render(358, 55);
				if (gGame->score < 100 && gGame->score>10) ScoreTexture.render(353, 55);
				if (gGame->score < 1000 && gGame->score>100) ScoreTexture.render(346, 55);
				if (gGame->score < 10000 && gGame->score>1000) ScoreTexture.render(340, 55);
				if (gGame->score > 10000) ScoreTexture.render(335, 55);
				if (gGame->best < 10) BestTexture.render(464, 55);
				if (gGame->best < 100 && gGame->best>10) BestTexture.render(459, 55);
				if (gGame->best < 1000 && gGame->best>100) BestTexture.render(452, 55);
				if (gGame->best < 10000 && gGame->best>1000) BestTexture.render(448, 55);
				if (gGame->best > 10000) BestTexture.render(437, 55);
                for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						int value = gGame->board[i][j];
						renderTile(value, i, j);
					}
				}
				checklose(gGame->lose, gGame->board);
				checkwin(gGame->win, gGame->board);
				if (gGame->lose == true)
				{
					youlose.render(120, 120);
					if (gGame->loseSound == false)
					{
						Mix_PlayChannel(-1, glose, 0);
						gGame->loseSound = true;
				}
			}
				if (gGame->win == true)
				{
					youwin.render(120, 120);
					if (gGame->winSound == false)
					{
						Mix_PlayChannel(-1, gwin, 0);
						gGame->winSound = true;
					}
				}

				SDL_RenderPresent(gRenderer);
			}
			for (int i = 0; i < 4; i++)
            {
                delete[] gGame->board[i];
                delete[] gGame->thepreviousboard[i];
            }
            delete[] gGame->board;
            delete[] gGame->thepreviousboard;
		}
	}

	close();

	
}

int main(int argc, char* args[])
{
	srand(time(NULL));
	play();
	return 0;
}
