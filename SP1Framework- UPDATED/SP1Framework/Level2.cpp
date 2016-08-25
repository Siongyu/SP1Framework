#include "level2.h"
#include "Pause.h"
extern bool completedlevel2;

struct TILE_TYPE2
{
	char    nCharacter; // ASCII character for this tile type
	short   nColorCode; // Color code for this tile type
	bool	bPassable;
};
// Global array used to define all tile types used in the game
TILE_TYPE2  sTileIndex[] = {
	{ '.', 10, true },     // (0) TILE_FLOOR
	{ '#', 5, false },     // (1) TILE_WALL
};


SGameBlock2  sBlockIndex2[] = {
	{ { 19, 4 }, '1', 1, false },     // (0) Block 1
	{ { 19, 7 }, '2', 2, false },     // (1) Block 2
	{ { 24, 8 }, '3', 3, false },     // (2) Block 3
	{ { 24, 9 }, '4', 4, false },     // (3) Block 4
	{ { 28, 9 }, '5', 5, false },     // (4) Block 5
	{ { 34, 13 }, '6', 6, false },     // (5) Block 6
	{ { 24, 13 }, '7', 7, false },     // (6) Block 7
	{ { 22, 13 }, '8', 8, false },     // (7) Block 8
	{ { 4, 13 }, '9', 9, false }    // (8) Block 9

};
SGameBlock2 sEndZoneIndex2[] =
{
	{ { 4, 4 }, 'a', 1, false }, // (0)endzone 1
	{ { 4, 7 }, 'b', 2, false },// (1)endzone 2
	{ { 26, 8 }, 'c', 3, false },// (2)endzone 3
	{ { 24, 12 }, 'd', 4, false },// (3)endzone 4
	{ { 34, 9 }, 'e', 5, false }, // (4)endzone 5
	{ { 37, 14 }, 'f', 6, false }, // (5)endzone 6
	{ { 26, 13 }, 'g', 7, false }, // (6)endzone 7
	{ { 24, 14 }, 'h', 8,false }, // (7)endzone 8
	{ { 4, 10 }, 'i', 9,false } // (8) endzone 9

};


extern Console g_Console;

void Level2()
{
	COORD c;
	ifstream myfile("LEVEL2.txt");

	if (myfile.is_open())
	{
		for (int i = 0; i < MAP2_HEIGHT; i++)
		{
			for (int j = 0; j < MAP2_WIDTH; j++)
			{
				myfile >> nMap2Array[i][j];
			}
		}
		myfile.close();
		//-----this is for with viewing distance--------//
		/*c.Y = g_sChar2.m_cLocation.Y - 4;
		for (int y = g_sChar2.m_cLocation.Y - 3; y < g_sChar2.m_cLocation.Y + 3; y++)
		{
			c.Y += 1;
			c.X = g_sChar2.m_cLocation.X - 4;
			for (int x = g_sChar2.m_cLocation.X - 3; x < g_sChar2.m_cLocation.X + 3; x++)
			{
				c.X += 1;
				int nType = nMap2Array[y][x];
				g_Console.writeToBuffer(c, sTileIndex[nType].nCharacter, sTileIndex[nType].nColorCode);
			}
		}*/
		//----this is for without viewing distance------//
		c.Y = -1;
		for (int y = 0; y < MAP2_HEIGHT; y++)
		{
			c.Y += 1;
			c.X = -1;
			for (int x = 0; x < MAP2_WIDTH; x++)
			{
				c.X += 1;
				int nType = nMap2Array[y][x];
				g_Console.writeToBuffer(c, sTileIndex[nType].nCharacter, sTileIndex[nType].nColorCode);
			}
		}

	}
}


void characterlevel2()
{
	if (!paused)
	{// Draw the location of the character
		WORD charColor = 0x01;
		int ns = sizeof(sBlockIndex2) / sizeof(sBlockIndex2[0]);
		for (int ezi = 0; ezi < ns; ezi++)
		{
			g_Console.writeToBuffer(sEndZoneIndex2[ezi].m_cLocate, sEndZoneIndex2[ezi].nCharacter, sEndZoneIndex2[ezi].nColorCode);
		}

		for (int bi = 0; bi < ns; bi++)
		{
			g_Console.writeToBuffer(sBlockIndex2[bi].m_cLocate, sBlockIndex2[bi].nCharacter, sBlockIndex2[bi].nColorCode);
		}
		g_Console.writeToBuffer(g_sChar2.m_cLocation, (char)1, charColor);
	}
}

void end2()
{
	int ns = sizeof(sBlockIndex2) / sizeof(sBlockIndex2[0]);

	for (int bi = 0; bi < ns; bi++)
	{
		for (int ezi = 0; ezi < ns; ezi++)
		{
			if ((sBlockIndex2[bi].m_cLocate.X == sEndZoneIndex2[ezi].m_cLocate.X) && (sBlockIndex2[bi].m_cLocate.Y == sEndZoneIndex2[ezi].m_cLocate.Y))
			{
				sEndZoneIndex2[ezi].bPassable = true;
				break;
			}
		}
	}


	if (sEndZoneIndex2[0].bPassable && sEndZoneIndex2[1].bPassable && sEndZoneIndex2[2].bPassable && sEndZoneIndex2[3].bPassable && sEndZoneIndex2[4].bPassable && sEndZoneIndex2[5].bPassable && sEndZoneIndex2[6].bPassable && sEndZoneIndex2[7].bPassable && sEndZoneIndex2[8].bPassable)
	{
		completedlevel2 = true;
		highScore(to_string(GameTime), to_string(playersteps));
		g_bQuitGame = true;
	}


	// shorten it bu having array index for blocks

}


bool IsPassable2(int nMapX, int nMapY)
{
	int nTileValue = nMap2Array[nMapY][nMapX];

	// Return true if it's passable
	return sTileIndex[nTileValue].bPassable;
}

bool checkblock2(int charMapX, int charMapY)
{
	int ns = sizeof(sBlockIndex2) / sizeof(sBlockIndex2[0]);

	for (int bi = 0; bi < ns; bi++)
	{
		if (charMapX == sBlockIndex2[bi].m_cLocate.X && charMapY == sBlockIndex2[bi].m_cLocate.Y)
		{
			return sBlockIndex2[bi].bPassable;
			break;
		}
	}
	return true;
}