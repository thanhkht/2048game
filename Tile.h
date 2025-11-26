#ifndef TILE_H
#define TILE_H

#include "LTexture.h"  

class Tile : public LTexture
{
public:
	Tile() : LTexture() {} 
};

void renderTile(int value, int i, int j);

#endif
