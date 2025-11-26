#include<vector> 
#include "GameManager.h"
#include "Tile.h"
#include "Global.h" 
#include "Logic.h" 
extern Tile TextureTile0, TextureTile2, TextureTile4, TextureTile8,
            TextureTile16, TextureTile32, TextureTile64, TextureTile128,
            TextureTile256, TextureTile512, TextureTile1024, TextureTile2048;
void randomtile(int** board, int check) {
    int count = 0;
    int value = (check == 0) ? ((rand() % 4 == 3) ? 4 : 2) : 2;
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 0) count++;
    
    int res = rand() % count;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 0 && res-- == 0) 
                board[i][j] = value;
}


void push(std::vector<int>& notmain, int& scorepermove) {
   
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if ((notmain[i] == notmain[j]) && (notmain[i] != 0)) {
                notmain[i] *= 2;
                scorepermove += notmain[i];
                notmain[j] = 0;
                break;
            } else if (notmain[j] != 0) break;
    
    
    int writePos = 0;
    for (int i = 0; i < 4; i++)
        if (notmain[i] != 0)
            notmain[writePos++] = notmain[i];
    while (writePos < 4)
        notmain[writePos++] = 0;
}

void moveright(int** board, int& scorepermove) {
    for (int i = 0; i < 4; i++) {
        std::vector<int> notmain;
        for (int j = 3; j >= 0; j--) 
            notmain.push_back(board[i][j]);
        push(notmain, scorepermove);
        for (int j = 3; j >= 0; j--) 
            board[i][j] = notmain[3 - j];
    }
}

void moveleft(int** board, int& scorepermove) {
    for (int i = 0; i < 4; i++) {
        std::vector<int> notmain;
        for (int j = 0; j < 4; j++) 
            notmain.push_back(board[i][j]);
        push(notmain, scorepermove);
        for (int j = 0; j < 4; j++) 
            board[i][j] = notmain[j];
    }
}

void moveup(int** board, int& scorepermove) {
    for (int j = 0; j < 4; j++) {
        std::vector<int> notmain;
        for (int i = 0; i < 4; i++) 
            notmain.push_back(board[i][j]);
        push(notmain, scorepermove);
        for (int i = 0; i < 4; i++) 
            board[i][j] = notmain[i];
    }
}

void movedown(int** board, int& scorepermove) {
    for (int j = 0; j < 4; j++) {
        std::vector<int> notmain;
        for (int i = 3; i >= 0; i--) 
            notmain.push_back(board[i][j]);
        push(notmain, scorepermove);
        for (int i = 3; i >= 0; i--) 
            board[i][j] = notmain[3 - i];
    }
}

void updateboard(int** board, int** thepreviousboard)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			thepreviousboard[i][j] = board[i][j];
		}
	}
}

bool checktheresemblance(int** board, int** thepreviousboard)
{
	bool check = true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != thepreviousboard[i][j]) check = false;
		}
	}
	return check;
}

bool fulltile(int** a)
{
	bool check = true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (a[i][j] == 0)
				check = false;
	}
	return check;
}

void checklose(bool& lose, int** a) {
    bool check = false;
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            if (a[i][j] == a[i][j+1] || a[j][i] == a[j+1][i]) 
                check = true;
    if (!check && fulltile(a)) gGame->lose = true;
}

void checkwin(bool& win, int** a) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (a[i][j] == 2048) gGame->win = true;
}
