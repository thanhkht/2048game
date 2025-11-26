#ifndef LOGIC_H
#define LOGIC_H

#include <vector>

void randomtile(int** board, int check);
void push(std::vector<int>& notmain, int& scorepermove);
void moveright(int** board, int& scorepermove);
void moveleft(int** board, int& scorepermove);
void moveup(int** board, int& scorepermove);
void movedown(int** board, int& scorepermove);

void updateboard(int** board, int** thepreviousboard);
bool checktheresemblance(int** board, int** thepreviousboard);

bool fulltile(int** a);
void checklose(bool& lose, int** a);
void checkwin(bool& win, int** a);

#endif

