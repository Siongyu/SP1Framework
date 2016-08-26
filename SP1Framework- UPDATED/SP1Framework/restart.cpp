#include "restart.h"

void Restart()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;
	if (g_abKeyPressed[K_RESTART])
	{
		if (!completedlevel1)
		{
			GameTime = 0.0;
			playersteps = 0;
			// character initialisation
			g_sChar.m_cLocation.X = 12;
			g_sChar.m_cLocation.Y = 5;
			g_sChar.bPassable = false;
			// block initialisation

			sBlockIndex[0].m_cLocate.X = 19;
			sBlockIndex[0].m_cLocate.Y = 5;

			sBlockIndex[1].m_cLocate.X = 24;
			sBlockIndex[1].m_cLocate.Y = 7;

			sBlockIndex[2].m_cLocate.X = 24;
			sBlockIndex[2].m_cLocate.Y = 8;

			sBlockIndex[3].m_cLocate.X = 24;
			sBlockIndex[3].m_cLocate.Y = 12;

			sBlockIndex[4].m_cLocate.X = 22;
			sBlockIndex[4].m_cLocate.Y = 12;

			sBlockIndex[5].m_cLocate.X = 4;
			sBlockIndex[5].m_cLocate.Y = 12;

			sEndZoneIndex[0].m_cLocate.X = 4;
			sEndZoneIndex[0].m_cLocate.Y = 5;

			sEndZoneIndex[1].m_cLocate.X = 26;
			sEndZoneIndex[1].m_cLocate.Y = 7;

			sEndZoneIndex[2].m_cLocate.X = 24;
			sEndZoneIndex[2].m_cLocate.Y = 11;

			sEndZoneIndex[3].m_cLocate.X = 26;
			sEndZoneIndex[3].m_cLocate.Y = 12;

			sEndZoneIndex[4].m_cLocate.X = 24;
			sEndZoneIndex[4].m_cLocate.Y = 13;

			sEndZoneIndex[5].m_cLocate.X = 4;
			sEndZoneIndex[5].m_cLocate.Y = 8;






			(bSomethingHappened) = true;
			if (bSomethingHappened)
			{
				// set the bounce time to some time in the future to prevent accidental triggers
				g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
			}
		}
		else if (!completedlevel2)
		{
			GameTime = 0.0;
			playersteps = 0;
			// character initialisation
			g_sChar2.m_cLocation.X = 12;
			g_sChar2.m_cLocation.Y = 4;
			g_sChar2.bPassable = false;
			// block initialisation

			sBlockIndex2[0].m_cLocate.X = 19;
			sBlockIndex2[0].m_cLocate.Y = 4;

			sBlockIndex2[1].m_cLocate.X = 19;
			sBlockIndex2[1].m_cLocate.Y = 7;

			sBlockIndex2[2].m_cLocate.X = 24;
			sBlockIndex2[2].m_cLocate.Y = 8;

			sBlockIndex2[3].m_cLocate.X = 24;
			sBlockIndex2[3].m_cLocate.Y = 9;

			sBlockIndex2[4].m_cLocate.X = 28;
			sBlockIndex2[4].m_cLocate.Y = 9;

			sBlockIndex2[5].m_cLocate.X = 34;
			sBlockIndex2[5].m_cLocate.Y = 13;

			sBlockIndex2[6].m_cLocate.X = 24;
			sBlockIndex2[6].m_cLocate.Y = 13;

			sBlockIndex2[7].m_cLocate.X = 22;
			sBlockIndex2[7].m_cLocate.Y = 13;

			sBlockIndex2[8].m_cLocate.X = 4;
			sBlockIndex2[8].m_cLocate.Y = 13;

			sEndZoneIndex2[0].m_cLocate.X = 4;
			sEndZoneIndex2[0].m_cLocate.Y = 4;

			sEndZoneIndex2[1].m_cLocate.X = 4;
			sEndZoneIndex2[1].m_cLocate.Y = 7;

			sEndZoneIndex2[2].m_cLocate.X = 26;
			sEndZoneIndex2[2].m_cLocate.Y = 8;

			sEndZoneIndex2[3].m_cLocate.X = 24;
			sEndZoneIndex2[3].m_cLocate.Y = 12;

			sEndZoneIndex2[4].m_cLocate.X = 34;
			sEndZoneIndex2[4].m_cLocate.Y = 9;

			sEndZoneIndex2[5].m_cLocate.X = 37;
			sEndZoneIndex2[5].m_cLocate.Y = 14;

			sEndZoneIndex2[6].m_cLocate.X = 26;
			sEndZoneIndex2[6].m_cLocate.Y = 13;

			sEndZoneIndex2[7].m_cLocate.X = 24;
			sEndZoneIndex2[7].m_cLocate.Y = 14;

			sEndZoneIndex2[8].m_cLocate.X = 4;
			sEndZoneIndex2[8].m_cLocate.Y = 10;

			(bSomethingHappened) = true;
			if (bSomethingHappened)
			{
				// set the bounce time to some time in the future to prevent accidental triggers
				g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
			}
		}
		else if (!completedlevel3)
		{
			GameTime = 0.0;
			playersteps = 0;
			// character initialisation
			g_sChar3.m_cLocation.X = 12;
			g_sChar3.m_cLocation.Y = 5;
			g_sChar3.bPassable = false;
			// block initialisation

			sBlockIndex3[0].m_cLocate.X = 17;
			sBlockIndex3[0].m_cLocate.Y = 5;

			sBlockIndex3[1].m_cLocate.X = 17;
			sBlockIndex3[1].m_cLocate.Y = 8;

			sBlockIndex3[2].m_cLocate.X = 29;
			sBlockIndex3[2].m_cLocate.Y = 5;

			sBlockIndex3[3].m_cLocate.X = 4;
			sBlockIndex3[3].m_cLocate.Y = 13;

			sBlockIndex3[4].m_cLocate.X = 26;
			sBlockIndex3[4].m_cLocate.Y = 13;

			sBlockIndex3[5].m_cLocate.X = 25;
			sBlockIndex3[5].m_cLocate.Y = 13;

			sBlockIndex3[6].m_cLocate.X = 29;
			sBlockIndex3[6].m_cLocate.Y = 10;

			sEndZoneIndex3[0].m_cLocate.X = 5;
			sEndZoneIndex3[0].m_cLocate.Y = 5;

			sEndZoneIndex3[1].m_cLocate.X = 5;
			sEndZoneIndex3[1].m_cLocate.Y = 8;

			sEndZoneIndex3[2].m_cLocate.X = 40;
			sEndZoneIndex3[2].m_cLocate.Y = 2;

			sEndZoneIndex3[3].m_cLocate.X = 4;
			sEndZoneIndex3[3].m_cLocate.Y = 11;

			sEndZoneIndex3[4].m_cLocate.X = 26;
			sEndZoneIndex3[4].m_cLocate.Y = 12;

			sEndZoneIndex3[5].m_cLocate.X = 27;
			sEndZoneIndex3[5].m_cLocate.Y = 13;

			sEndZoneIndex3[6].m_cLocate.X = 39;
			sEndZoneIndex3[6].m_cLocate.Y = 9;

			(bSomethingHappened) = true;
			if (bSomethingHappened)
			{
				// set the bounce time to some time in the future to prevent accidental triggers
				g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
			}
		}
		else if (!completedlevel3_S2)
		{
			GameTime = 0.0;
			playersteps = 0;
			// character initialisation
			g_sChar3_Stage2.m_cLocation.X = 2;
			g_sChar3_Stage2.m_cLocation.Y = 5;
			g_sChar3_Stage2.bPassable = false;
			// block initialisation

			sBlockIndex3_S2[0].m_cLocate.X = 29;
			sBlockIndex3_S2[0].m_cLocate.Y = 13;

			sBlockIndex3_S2[1].m_cLocate.X = 19;
			sBlockIndex3_S2[1].m_cLocate.Y = 3;

			sBlockIndex3_S2[2].m_cLocate.X = 37;
			sBlockIndex3_S2[2].m_cLocate.Y = 9;

			sBlockIndex3_S2[3].m_cLocate.X = 22;
			sBlockIndex3_S2[3].m_cLocate.Y = 13;

			sBlockIndex3_S2[4].m_cLocate.X = 32;
			sBlockIndex3_S2[4].m_cLocate.Y = 13;

			sEndZoneIndex3_S2[0].m_cLocate.X = 38;
			sEndZoneIndex3_S2[0].m_cLocate.Y = 4;

			sEndZoneIndex3_S2[1].m_cLocate.X = 12;
			sEndZoneIndex3_S2[1].m_cLocate.Y = 5;

			sEndZoneIndex3_S2[2].m_cLocate.X = 4;
			sEndZoneIndex3_S2[2].m_cLocate.Y = 8;

			sEndZoneIndex3_S2[3].m_cLocate.X = 15;
			sEndZoneIndex3_S2[3].m_cLocate.Y = 11;

			sEndZoneIndex3_S2[4].m_cLocate.X = 4;
			sEndZoneIndex3_S2[4].m_cLocate.Y = 13;


			(bSomethingHappened) = true;
			if (bSomethingHappened)
			{
				// set the bounce time to some time in the future to prevent accidental triggers
				g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
			}
		}
	}
}
