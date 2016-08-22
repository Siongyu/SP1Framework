#include "drawmap.h"

#define MAP1_WIDTH   48
#define MAP1_HEIGHT  16

int nMap1Array[MAP1_HEIGHT][MAP1_WIDTH];

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

bool checkblock(int charMapX, int charMapY)
{
	SGameChar	g_sBlock1;
	// block initialisation
	g_sBlock1.m_cLocation.X = 25;
	g_sBlock1.m_cLocation.Y = 9;
	g_sBlock1.bPassable = false;
	return g_sBlock1.bPassable;
}