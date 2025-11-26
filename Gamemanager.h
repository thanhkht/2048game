#include <cstdlib>
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager 
{
public:
    int score;
    int scorepermove;
    int best;
    int** board;
    int** thepreviousboard;
    bool win;
    bool lose;
    bool winSound;
    bool loseSound;

    GameManager()
    {
        score = 0;
        scorepermove = 0;
        best = 0;
        board = NULL;
        thepreviousboard = NULL;
        win = false;
        lose = false;
        winSound = false;
        loseSound = false;
    }
};

extern GameManager* gGame;

#endif

