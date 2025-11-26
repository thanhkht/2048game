#include "Tile.h"
#include "Global.h" 

extern Tile TextureTile0, TextureTile2, TextureTile4, TextureTile8,
            TextureTile16, TextureTile32, TextureTile64, TextureTile128,
            TextureTile256, TextureTile512, TextureTile1024, TextureTile2048;
void renderTile(int value, int i, int j)
{ 
    int x = 131 + 97 * j;  
    int y = 198 + 97 * i;  
    
    switch (value)
    {
    case 0: TextureTile0.render(x, y); break;
    case 2: TextureTile2.render(x, y); break;
    case 4: TextureTile4.render(x, y); break;
    case 8: TextureTile8.render(x, y); break;
    case 16: TextureTile16.render(x, y); break;
    case 32: TextureTile32.render(x, y); break;
    case 64: TextureTile64.render(x, y); break;
    case 128: TextureTile128.render(x, y); break;
    case 256: TextureTile256.render(x, y); break;
    case 512: TextureTile512.render(x, y); break;
    case 1024: TextureTile1024.render(x, y); break;
    case 2048: TextureTile2048.render(x, y); break;
    }
}
