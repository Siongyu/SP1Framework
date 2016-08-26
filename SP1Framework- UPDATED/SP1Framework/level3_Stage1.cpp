#include "level3_Stage1.h"
#include "Pause.h"
extern bool completedlevel3;

struct TITLE_TYPE3 {

	char nCharacter;	//Ascii character for this tile type
	short nColorCode;	// Color Code for this type
	bool bPassable;
};

//Gobal Array used to define all the tile types used in the game
TITLE_TYPE3 sTileIndex[] = {

	{ '.', 10, true }, // (0) TITLE_FLOOR
	{ '#', 5, false }, // (1) TITLE_WALL

};

SGameBlock3 sBlockIndex3[]{ // 1 2 3 4 5 6 7

	{ { 17, 5 }, false },
	{ { 17, 8 }, false },
	{ { 29, 5 }, false },
	{ { 4, 13 }, false },
	{ { 26, 13 }, false },
	{ { 25, 13 }, false },
	{ { 29, 10 }, false },

};

SGameBlock3 sEndZoneIndex3[]{ //a b c d e f g

	{ { 5, 5 }, false },
	{ { 5, 8 }, false },
	{ { 40, 2 }, false },
	{ { 4, 11 }, false },
	{ { 26, 12 }, false },
	{ { 27, 13 }, false },
	{ { 39, 9 }, false },

};

extern Console g_Console;

void Level3_Stage1() {

	COORD c;
	ifstream myfile("Lvl3_Stage1.txt");

	if (myfile.is_open())
	{
		for (int i = 0; i < MAP3_HEIGHT; i++)
		{
			for (int j = 0; j < MAP3_WIDTH; j++)
			{
				myfile >> nMap3Array[i][j];
			}
		}
		myfile.close();
		//--------this is for viewing distance-------------//
		/*c.Y = g_sChar.m_cLocation.Y - 4;
		for (int y = g_sChar.m_cLocation.Y - 3; y < g_sChar.m_cLocation.Y + 3; y++)
		{
		c.Y += 1;
		c.X = g_sChar.m_cLocation.X - 4;
		for (int x = g_sChar.m_cLocation.X - 3; x < g_sChar.m_cLocation.X + 3; x++)
		{
		c.X += 1;
		int nType = nMap1Array[y][x];
		g_Console.writeToBuffer(c, sTileIndex[nType].nCharacter, sTileIndex[nType].nColorCode);
		}
		}*/
		//---------this is for without viewing distance------------//
		c.Y = -1;
		for (int y = 0; y < MAP3_HEIGHT; y++)
		{
			c.Y += 1;
			c.X = -1;
			for (int x = 0; x < MAP3_WIDTH; x++)
			{
				c.X += 1;
				int nType = nMap3Array[y][x];
				g_Console.writeToBuffer(c, sTileIndex[nType].nCharacter, sTileIndex[nType].nColorCode);
			}
		}

	}
}

bool IsPassable3(int nMapX, int nMapY)
{
	int nTileValue = nMap3Array[nMapY][nMapX];

	// Return true if it's passable
	return sTileIndex[nTileValue].bPassable;
}

bool checkblock3(int charMapX, int charMapY)
{
	int ns = sizeof(sBlockIndex3) / sizeof(sBlockIndex3[0]);

	for (int bi = 0; bi < ns; bi++)
	{
		if (charMapX == sBlockIndex3[bi].m_cLocate.X && charMapY == sBlockIndex3[bi].m_cLocate.Y)
		{
			return sBlockIndex3[bi].bPassable;
			break;
		}
	}
	return true;
}

void characterlevel3()
{
	if (!paused)
	{// Draw the location of the character
		WORD charColor = 0x01;
		g_Console.writeToBuffer(sEndZoneIndex3[0].m_cLocate, 'a', 4);

		g_Console.writeToBuffer(sEndZoneIndex3[1].m_cLocate, 'b', 4);
		g_Console.writeToBuffer(sEndZoneIndex3[2].m_cLocate, 'c', 4);
		g_Console.writeToBuffer(sEndZoneIndex3[3].m_cLocate, 'd', 4);
		g_Console.writeToBuffer(sEndZoneIndex3[4].m_cLocate, 'e', 4);
		g_Console.writeToBuffer(sEndZoneIndex3[5].m_cLocate, 'f', 4);
		g_Console.writeToBuffer(sEndZoneIndex3[6].m_cLocate, 'g', 4);


		g_Console.writeToBuffer(sBlockIndex3[0].m_cLocate, '1', 4);
		g_Console.writeToBuffer(sBlockIndex3[1].m_cLocate, '2', 4);
		g_Console.writeToBuffer(sBlockIndex3[2].m_cLocate, '3', 4);
		g_Console.writeToBuffer(sBlockIndex3[3].m_cLocate, '4', 4);
		g_Console.writeToBuffer(sBlockIndex3[4].m_cLocate, '5', 4);
		g_Console.writeToBuffer(sBlockIndex3[5].m_cLocate, '6', 4);
		g_Console.writeToBuffer(sBlockIndex3[6].m_cLocate, '7', 4);

		g_Console.writeToBuffer(g_sChar3.m_cLocation, (char)1, charColor);
	}
}

void end3()
{
	int ns = sizeof(sBlockIndex3) / sizeof(sBlockIndex3[0]);

	for (int bi = 0; bi < ns; bi++)
	{
		for (int ezi = 0; ezi < ns; ezi++)
		{
			if ((sBlockIndex3[bi].m_cLocate.X == sEndZoneIndex3[ezi].m_cLocate.X) && (sBlockIndex3[bi].m_cLocate.Y == sEndZoneIndex3[ezi].m_cLocate.Y))
			{
				sEndZoneIndex3[ezi].bPassable = true;
				break;
			}
			if (sEndZoneIndex3[0].bPassable/* && sEndZoneIndex3[1].bPassable && sEndZoneIndex3[2].bPassable && sEndZoneIndex3[3].bPassable && sEndZoneIndex3[4].bPassable && sEndZoneIndex3[5].bPassable && sEndZoneIndex3[6].bPassable*/)
			{
				if (g_abKeyPressed[K_RIGHT] && (g_sChar3.m_cLocation.X == 47 && g_sChar3.m_cLocation.Y == 5) || (g_sChar3.m_cLocation.X == 47 && g_sChar3.m_cLocation.Y == 6))
				{
					completedlevel3 = true;
					highScore(to_string(GameTime), to_string(playersteps));
					g_eGameState = S_GAME2_S2;
				}

			}
		}
	}
}