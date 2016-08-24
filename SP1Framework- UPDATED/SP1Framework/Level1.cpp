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

SGameBlock  sBlockIndex[] = {
	{ { 19, 5 }, false },     // (0) Block 1
	{ { 24, 7 }, false },     // (1) Block 2
	{ { 24, 8 }, false },     // (2) Block 3
	{ { 24, 12 }, false },     // (3) Block 4
	{ { 22, 12 }, false },     // (4) Block 5
	{ { 4, 12 }, false },     // (5) Block 6
};
SGameBlock sEndZoneIndex[] =
{
	{ { 4, 5 }, false }, // (0)endzone 1
	{ { 26, 7 }, false },// (1)endzone 2
	{ { 24, 11 }, false },// (2)endzone 3
	{ { 26, 12 }, false },// (3)endzone 4
	{ { 24, 13 }, false }, // (4)endzone 5
	{ { 4, 8 }, false } // (5)endzone 6
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

bool checkblock(int charMapX, int charMapY)
{
	int ns = sizeof(sBlockIndex) / sizeof(sBlockIndex[0]);

	for (int bi = 0; bi < ns; bi++)
	{
		if (charMapX == sBlockIndex[bi].m_cLocate.X && charMapY == sBlockIndex[bi].m_cLocate.Y)
		{
			return sBlockIndex[bi].bPassable;
			break;
		}
	}
	return true;
}

void end()
{
	int ns = sizeof(sBlockIndex) / sizeof(sBlockIndex[0]);

	for (int bi = 0; bi < ns; bi++)
	{
		for (int ezi = 0; ezi < ns; ezi++)
		{
			if ((sBlockIndex[bi].m_cLocate.X == sEndZoneIndex[ezi].m_cLocate.X) && (sBlockIndex[bi].m_cLocate.Y == sEndZoneIndex[ezi].m_cLocate.Y))
			{
				sEndZoneIndex[ezi].bPassable = true;
				break;
			}
		}
	}


	if (sEndZoneIndex[0].bPassable && sEndZoneIndex[1].bPassable && sEndZoneIndex[2].bPassable && sEndZoneIndex[3].bPassable && sEndZoneIndex[4].bPassable && sEndZoneIndex[5].bPassable)
	{

		highScore(to_string(GameTime), to_string(playersteps));
		g_bQuitGame = true;
	}


	// shorten it bu having array index for blocks

}