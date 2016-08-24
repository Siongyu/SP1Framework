#include "level1.h"

struct TILE_TYPE
{
	char    nCharacter; // ASCII character for this tile type
	short   nColorCode; // Color code for this tile type
	bool	bPassable;
};
// Global array used to define all tile types used in the game
TILE_TYPE  sTileIndex[] = {
	{ '.', 10, true },     // (0) TILE_FLOOR
	{ '#', 5, false },     // (1) TILE_WALL
};

extern Console g_Console;

void Level1()
{
	COORD c;
	ifstream myfile("LEVEL1.txt");

	if (myfile.is_open())
	{
		for (int i = 0; i < MAP1_HEIGHT; i++)
		{
			for (int j = 0; j < MAP1_WIDTH; j++)
			{
				myfile >> nMap1Array[i][j];
			}
		}
		myfile.close();
		c.Y = -1;
		for (int y = 0; y < MAP1_HEIGHT; y++)
		{
			c.Y += 1;
			c.X = -1;
			for (int x = 0; x < MAP1_WIDTH; x++)
			{
				c.X += 1;
				int nType = nMap1Array[y][x];
				g_Console.writeToBuffer(c, sTileIndex[nType].nCharacter, sTileIndex[nType].nColorCode);
			}
		}

	}
}

bool IsPassable(int nMapX, int nMapY)
{
	int nTileValue = nMap1Array[nMapY][nMapX];

	// Return true if it's passable
	return sTileIndex[nTileValue].bPassable;
}