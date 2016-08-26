#include "level3_Stage2.h"
#include "Pause.h"
extern bool completedlevel3_S2;

struct TILE_TYPE3_S2
{
	char    nCharacter; // ASCII character for this tile type
	short   nColorCode; // Color code for this tile type
	bool	bPassable;
};

TILE_TYPE3_S2  sTileIndex[] = {
	{ ' ', 10, true },     // (0) TILE_FLOOR
	{ '²', 5, false },     // (1) TILE_WALL
};

SGameBlock3_Stage2  sBlockIndex3_S2[] = {

	{ { 29, 13 }, '1', 1, false },
	{ { 19, 3 }, '2', 2, false },
	{ { 37, 9 }, '3', 3, false },
	{ { 22, 13 }, '4', 4, false },
	{ { 32, 13 }, '5', 5, false },

};

SGameBlock3_Stage2 sEndZoneIndex3_S2[] = {

	{ { 38, 4 }, 'a', 1, false },
	{ { 12, 5 }, 'b', 2, false },
	{ { 4, 8 }, 'c', 3, false },
	{ { 15, 11 }, 'd', 4, false },
	{ { 4, 13 }, 'e', 5 , false },

};

extern Console g_Console;

void Level3_Stage2()
{
	COORD c;
	ifstream myfile("Lvl3_Stage2.txt");

	if (myfile.is_open())
	{
		for (int i = 0; i < MAP3_Stage2_HEIGHT; i++)
		{
			for (int j = 0; j < MAP3_Stage2_WIDTH; j++)
			{
				myfile >> nMap3_Stage2Array[i][j];
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
		for (int y = 0; y < MAP3_Stage2_HEIGHT; y++)
		{
			c.Y += 1;
			c.X = -1;
			for (int x = 0; x < MAP3_Stage2_WIDTH; x++)
			{
				c.X += 1;
				int nType = nMap3_Stage2Array[y][x];
				g_Console.writeToBuffer(c, sTileIndex[nType].nCharacter, sTileIndex[nType].nColorCode);
			}
		}

	}
}

void characterlevel3_S2()
{
	if (!paused)
	{// Draw the location of the character
		WORD charColor = 0x01;
		int ns = sizeof(sBlockIndex3_S2) / sizeof(sBlockIndex3_S2[0]);
		for (int ezi = 0; ezi < ns; ezi++)
		{
			g_Console.writeToBuffer(sEndZoneIndex3_S2[ezi].m_cLocate, sEndZoneIndex3_S2[ezi].nCharacter, sEndZoneIndex3_S2[ezi].nColorCode);
		}

		for (int bi = 0; bi < ns; bi++)
		{
			g_Console.writeToBuffer(sBlockIndex3_S2[bi].m_cLocate, sBlockIndex3_S2[bi].nCharacter, sBlockIndex3_S2[bi].nColorCode);
		}
		g_Console.writeToBuffer(g_sChar3_Stage2.m_cLocation, (char)1, charColor);
	}
}

void end3_S2()
{
	int ns = sizeof(sBlockIndex3_S2) / sizeof(sBlockIndex3_S2[0]);

	for (int bi = 0; bi < ns; bi++)
	{
		for (int ezi = 0; ezi < ns; ezi++)
		{
			if ((sBlockIndex3_S2[bi].m_cLocate.X == sEndZoneIndex3_S2[ezi].m_cLocate.X) && (sBlockIndex3_S2[bi].m_cLocate.Y == sEndZoneIndex3_S2[ezi].m_cLocate.Y))
			{
				sEndZoneIndex3_S2[ezi].bPassable = true;
				break;
			}
		}
	}


	if (sEndZoneIndex3_S2[0].bPassable/* && sEndZoneIndex3_S2[1].bPassable && sEndZoneIndex3_S2[2].bPassable && sEndZoneIndex3_S2[3].bPassable && sEndZoneIndex3_S2[4].bPassable && sEndZoneIndex3_S2[5].bPassable*/)
	{
		completedlevel3_S2 = true;
		highScore(to_string(GameTime), to_string(playersteps));
		g_bQuitGame = true;
	}
}

bool IsPassable3_S2(int nMapX, int nMapY)
{
	int nTileValue = nMap3_Stage2Array[nMapY][nMapX];

	// Return true if it's passable
	return sTileIndex[nTileValue].bPassable;
}

bool checkblock3_S2(int charMapX, int charMapY)
{
	int ns = sizeof(sBlockIndex3_S2) / sizeof(sBlockIndex3_S2[0]);

	for (int bi = 0; bi < ns; bi++)
	{
		if (charMapX == sBlockIndex3_S2[bi].m_cLocate.X && charMapY == sBlockIndex3_S2[bi].m_cLocate.Y)
		{
			return sBlockIndex3_S2[bi].bPassable;
			break;
		}
	}
	return true;
}