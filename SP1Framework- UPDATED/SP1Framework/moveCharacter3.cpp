#include "moveCharacter.h"

void moveCharacter3()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	// Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
	if (g_abKeyPressed[K_UP])
	{
		if (!IsPassable3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 2))
		{
			if (IsPassable3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 1))
			{
				if (checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 1))
				{
					g_sChar3.m_cLocation.Y--;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[0].m_cLocate.X) && ((g_sChar3.m_cLocation.Y - 1) == sBlockIndex3[0].m_cLocate.Y))
			{
				sBlockIndex3[0].m_cLocate.Y--;
				g_sChar3.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[1].m_cLocate.X) && ((g_sChar3.m_cLocation.Y - 1) == sBlockIndex3[1].m_cLocate.Y))
			{
				sBlockIndex3[1].m_cLocate.Y--;
				g_sChar3.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[2].m_cLocate.X) && ((g_sChar3.m_cLocation.Y - 1) == sBlockIndex3[2].m_cLocate.Y))
			{
				sBlockIndex3[2].m_cLocate.Y--;
				g_sChar3.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[3].m_cLocate.X) && ((g_sChar3.m_cLocation.Y - 1) == sBlockIndex3[3].m_cLocate.Y))
			{
				sBlockIndex3[3].m_cLocate.Y--;
				g_sChar3.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[4].m_cLocate.X) && ((g_sChar3.m_cLocation.Y - 1) == sBlockIndex3[4].m_cLocate.Y))
			{
				sBlockIndex3[4].m_cLocate.Y--;
				g_sChar3.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[5].m_cLocate.X) && ((g_sChar3.m_cLocation.Y - 1) == sBlockIndex3[5].m_cLocate.Y))
			{
				sBlockIndex3[5].m_cLocate.Y--;
				g_sChar3.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[6].m_cLocate.X) && ((g_sChar3.m_cLocation.Y - 1) == sBlockIndex3[6].m_cLocate.Y))
			{
				sBlockIndex3[6].m_cLocate.Y--;
				g_sChar3.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[7].m_cLocate.X) && ((g_sChar3.m_cLocation.Y - 1) == sBlockIndex3[7].m_cLocate.Y))
			{
				sBlockIndex3[7].m_cLocate.Y--;
				g_sChar3.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y - 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[8].m_cLocate.X) && ((g_sChar3.m_cLocation.Y - 1) == sBlockIndex3[8].m_cLocate.Y))
			{
				sBlockIndex3[8].m_cLocate.Y--;
				g_sChar3.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar3.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
		}
	}


	if (g_abKeyPressed[K_LEFT])
	{

		if (!IsPassable3(g_sChar3.m_cLocation.X - 2, g_sChar3.m_cLocation.Y))
		{
			if (IsPassable3(g_sChar3.m_cLocation.X - 1, g_sChar3.m_cLocation.Y))
			{
				if (checkblock3(g_sChar3.m_cLocation.X - 1, g_sChar3.m_cLocation.Y))
				{
					g_sChar3.m_cLocation.X--;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock3(g_sChar3.m_cLocation.X - 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X - 1) == sBlockIndex3[0].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[0].m_cLocate.Y))
			{
				sBlockIndex3[0].m_cLocate.X--;
				g_sChar3.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X - 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X - 1) == sBlockIndex3[1].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[1].m_cLocate.Y))
			{
				sBlockIndex3[1].m_cLocate.X--;
				g_sChar3.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X - 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X - 1) == sBlockIndex3[2].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[2].m_cLocate.Y))
			{
				sBlockIndex3[2].m_cLocate.X--;
				g_sChar3.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X - 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X - 1) == sBlockIndex3[3].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[3].m_cLocate.Y))
			{
				sBlockIndex3[3].m_cLocate.X--;
				g_sChar3.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X - 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X - 1) == sBlockIndex3[4].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[4].m_cLocate.Y))
			{
				sBlockIndex3[4].m_cLocate.X--;
				g_sChar3.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X - 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X - 1) == sBlockIndex3[5].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[5].m_cLocate.Y))
			{
				sBlockIndex3[5].m_cLocate.X--;
				g_sChar3.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X - 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X - 1) == sBlockIndex3[6].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[6].m_cLocate.Y))
			{
				sBlockIndex3[6].m_cLocate.X--;
				g_sChar3.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X - 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X - 1) == sBlockIndex3[7].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[7].m_cLocate.Y))
			{
				sBlockIndex3[7].m_cLocate.X--;
				g_sChar3.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X - 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X - 1) == sBlockIndex3[8].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[8].m_cLocate.Y))
			{
				sBlockIndex3[8].m_cLocate.X--;
				g_sChar3.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar3.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}

		}
	}


	if (g_abKeyPressed[K_RIGHT])
	{
		if (!IsPassable3(g_sChar3.m_cLocation.X + 2, g_sChar3.m_cLocation.Y))
		{
			if (IsPassable3(g_sChar3.m_cLocation.X + 1, g_sChar3.m_cLocation.Y))
			{
				if (checkblock3(g_sChar3.m_cLocation.X + 1, g_sChar3.m_cLocation.Y))
				{
					g_sChar3.m_cLocation.X++;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock3(g_sChar3.m_cLocation.X + 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X + 1) == sBlockIndex3[0].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[0].m_cLocate.Y))
			{
				sBlockIndex3[0].m_cLocate.X++;
				g_sChar3.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X + 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X + 1) == sBlockIndex3[1].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[1].m_cLocate.Y))
			{
				sBlockIndex3[1].m_cLocate.X++;
				g_sChar3.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X + 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X + 1) == sBlockIndex3[2].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[2].m_cLocate.Y))
			{
				sBlockIndex3[2].m_cLocate.X++;
				g_sChar3.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X + 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X + 1) == sBlockIndex3[3].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[3].m_cLocate.Y))
			{
				sBlockIndex3[3].m_cLocate.X++;
				g_sChar3.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X + 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X + 1) == sBlockIndex3[4].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[4].m_cLocate.Y))
			{
				sBlockIndex3[4].m_cLocate.X++;
				g_sChar3.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X + 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X + 1) == sBlockIndex3[5].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[5].m_cLocate.Y))
			{
				sBlockIndex3[5].m_cLocate.X++;
				g_sChar3.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X + 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X + 1) == sBlockIndex3[6].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[6].m_cLocate.Y))
			{
				sBlockIndex3[6].m_cLocate.X++;
				g_sChar3.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X + 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X + 1) == sBlockIndex3[7].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[7].m_cLocate.Y))
			{
				sBlockIndex3[7].m_cLocate.X++;
				g_sChar3.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X + 1, g_sChar3.m_cLocation.Y)) && ((g_sChar3.m_cLocation.X + 1) == sBlockIndex3[8].m_cLocate.X) && (g_sChar3.m_cLocation.Y == sBlockIndex3[8].m_cLocate.Y))
			{
				sBlockIndex3[8].m_cLocate.X++;
				g_sChar3.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar3.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}

		}
	}


	if (g_abKeyPressed[K_DOWN])
	{

		if (!IsPassable3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 2))
		{
			if (IsPassable3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 1))
			{
				if (checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 1))
				{
					g_sChar3.m_cLocation.Y++;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[0].m_cLocate.X) && (g_sChar3.m_cLocation.Y + 1 == sBlockIndex3[0].m_cLocate.Y))
			{
				sBlockIndex3[0].m_cLocate.Y++;
				g_sChar3.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[1].m_cLocate.X) && (g_sChar3.m_cLocation.Y + 1 == sBlockIndex3[1].m_cLocate.Y))
			{
				sBlockIndex3[1].m_cLocate.Y++;
				g_sChar3.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3
			(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[2].m_cLocate.X) && (g_sChar3.m_cLocation.Y + 1 == sBlockIndex3[2].m_cLocate.Y))
			{
				sBlockIndex3[2].m_cLocate.Y++;
				g_sChar3.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[3].m_cLocate.X) && (g_sChar3.m_cLocation.Y + 1 == sBlockIndex3[3].m_cLocate.Y))
			{
				sBlockIndex3[3].m_cLocate.Y++;
				g_sChar3.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[4].m_cLocate.X) && (g_sChar3.m_cLocation.Y + 1 == sBlockIndex3[4].m_cLocate.Y))
			{
				sBlockIndex3[4].m_cLocate.Y++;
				g_sChar3.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[5].m_cLocate.X) && (g_sChar3.m_cLocation.Y + 1 == sBlockIndex3[5].m_cLocate.Y))
			{
				sBlockIndex3[5].m_cLocate.Y++;
				g_sChar3.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[6].m_cLocate.X) && (g_sChar3.m_cLocation.Y + 1 == sBlockIndex3[6].m_cLocate.Y))
			{
				sBlockIndex3[6].m_cLocate.Y++;
				g_sChar3.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[7].m_cLocate.X) && (g_sChar3.m_cLocation.Y + 1 == sBlockIndex3[7].m_cLocate.Y))
			{
				sBlockIndex3[7].m_cLocate.Y++;
				g_sChar3.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3(g_sChar3.m_cLocation.X, g_sChar3.m_cLocation.Y + 1)) && (g_sChar3.m_cLocation.X == sBlockIndex3[8].m_cLocate.X) && (g_sChar3.m_cLocation.Y + 1 == sBlockIndex3[8].m_cLocate.Y))
			{
				sBlockIndex3[8].m_cLocate.Y++;
				g_sChar3.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar3.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}

		}
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}

void moveCharacter3_S2()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	// Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
	if (g_abKeyPressed[K_UP])
	{
		if (!IsPassable3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y - 2))
		{
			if (IsPassable3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y - 1))
			{
				if (checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y - 1))
				{
					g_sChar3_Stage2.m_cLocation.Y--;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y - 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[0].m_cLocate.X) && ((g_sChar3_Stage2.m_cLocation.Y - 1) == sBlockIndex3_S2[0].m_cLocate.Y))
			{
				sBlockIndex3_S2[0].m_cLocate.Y--;
				g_sChar3_Stage2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y - 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[1].m_cLocate.X) && ((g_sChar3_Stage2.m_cLocation.Y - 1) == sBlockIndex3_S2[1].m_cLocate.Y))
			{
				sBlockIndex3_S2[1].m_cLocate.Y--;
				g_sChar3_Stage2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y - 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[2].m_cLocate.X) && ((g_sChar3_Stage2.m_cLocation.Y - 1) == sBlockIndex3_S2[2].m_cLocate.Y))
			{
				sBlockIndex3_S2[2].m_cLocate.Y--;
				g_sChar3_Stage2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y - 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[3].m_cLocate.X) && ((g_sChar3_Stage2.m_cLocation.Y - 1) == sBlockIndex3_S2[3].m_cLocate.Y))
			{
				sBlockIndex3_S2[3].m_cLocate.Y--;
				g_sChar3_Stage2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y - 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[4].m_cLocate.X) && ((g_sChar3_Stage2.m_cLocation.Y - 1) == sBlockIndex3_S2[4].m_cLocate.Y))
			{
				sBlockIndex3_S2[4].m_cLocate.Y--;
				g_sChar3_Stage2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y - 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[5].m_cLocate.X) && ((g_sChar3_Stage2.m_cLocation.Y - 1) == sBlockIndex3_S2[5].m_cLocate.Y))
			{
				sBlockIndex3_S2[5].m_cLocate.Y--;
				g_sChar3_Stage2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar3_Stage2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
		}
	}


	if (g_abKeyPressed[K_LEFT])
	{

		if (!IsPassable3_S2(g_sChar3_Stage2.m_cLocation.X - 2, g_sChar3_Stage2.m_cLocation.Y))
		{
			if (IsPassable3_S2(g_sChar3_Stage2.m_cLocation.X - 1, g_sChar3_Stage2.m_cLocation.Y))
			{
				if (checkblock3_S2(g_sChar3_Stage2.m_cLocation.X - 1, g_sChar3_Stage2.m_cLocation.Y))
				{
					g_sChar3_Stage2.m_cLocation.X--;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X - 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X - 1) == sBlockIndex3_S2[0].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[0].m_cLocate.Y))
			{
				sBlockIndex3_S2[0].m_cLocate.X--;
				g_sChar3_Stage2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X - 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X - 1) == sBlockIndex3_S2[1].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[1].m_cLocate.Y))
			{
				sBlockIndex3_S2[1].m_cLocate.X--;
				g_sChar3_Stage2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X - 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X - 1) == sBlockIndex3_S2[2].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[2].m_cLocate.Y))
			{
				sBlockIndex3_S2[2].m_cLocate.X--;
				g_sChar3_Stage2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X - 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X - 1) == sBlockIndex3_S2[3].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[3].m_cLocate.Y))
			{
				sBlockIndex3_S2[3].m_cLocate.X--;
				g_sChar3_Stage2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X - 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X - 1) == sBlockIndex3_S2[4].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[4].m_cLocate.Y))
			{
				sBlockIndex3_S2[4].m_cLocate.X--;
				g_sChar3_Stage2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X - 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X - 1) == sBlockIndex3_S2[5].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[5].m_cLocate.Y))
			{
				sBlockIndex3_S2[5].m_cLocate.X--;
				g_sChar3_Stage2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar3_Stage2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}

		}
	}


	if (g_abKeyPressed[K_RIGHT])
	{
		if (!IsPassable3_S2(g_sChar3_Stage2.m_cLocation.X + 2, g_sChar3_Stage2.m_cLocation.Y))
		{
			if (IsPassable3_S2(g_sChar3_Stage2.m_cLocation.X + 1, g_sChar3_Stage2.m_cLocation.Y))
			{
				if (checkblock3_S2(g_sChar3_Stage2.m_cLocation.X + 1, g_sChar3_Stage2.m_cLocation.Y))
				{
					g_sChar3_Stage2.m_cLocation.X++;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X + 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X + 1) == sBlockIndex3_S2[0].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[0].m_cLocate.Y))
			{
				sBlockIndex3_S2[0].m_cLocate.X++;
				g_sChar3_Stage2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X + 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X + 1) == sBlockIndex3_S2[1].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[1].m_cLocate.Y))
			{
				sBlockIndex3_S2[1].m_cLocate.X++;
				g_sChar3_Stage2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X + 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X + 1) == sBlockIndex3_S2[2].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[2].m_cLocate.Y))
			{
				sBlockIndex3_S2[2].m_cLocate.X++;
				g_sChar3_Stage2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X + 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X + 1) == sBlockIndex3_S2[3].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[3].m_cLocate.Y))
			{
				sBlockIndex3_S2[3].m_cLocate.X++;
				g_sChar3_Stage2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X + 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X + 1) == sBlockIndex3_S2[4].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[4].m_cLocate.Y))
			{
				sBlockIndex3_S2[4].m_cLocate.X++;
				g_sChar3_Stage2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X + 1, g_sChar3_Stage2.m_cLocation.Y)) && ((g_sChar3_Stage2.m_cLocation.X + 1) == sBlockIndex3_S2[5].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y == sBlockIndex3_S2[5].m_cLocate.Y))
			{
				sBlockIndex3_S2[5].m_cLocate.X++;
				g_sChar3_Stage2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar3_Stage2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}

		}
	}


	if (g_abKeyPressed[K_DOWN])
	{

		if (!IsPassable3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y + 2))
		{
			if (IsPassable3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y + 1))
			{
				if (checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y + 1))
				{
					g_sChar3_Stage2.m_cLocation.Y++;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y + 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[0].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y + 1 == sBlockIndex3_S2[0].m_cLocate.Y))
			{
				sBlockIndex3_S2[0].m_cLocate.Y++;
				g_sChar3_Stage2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y + 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[1].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y + 1 == sBlockIndex3_S2[1].m_cLocate.Y))
			{
				sBlockIndex3_S2[1].m_cLocate.Y++;
				g_sChar3_Stage2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2
			(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y + 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[2].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y + 1 == sBlockIndex3_S2[2].m_cLocate.Y))
			{
				sBlockIndex3_S2[2].m_cLocate.Y++;
				g_sChar3_Stage2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y + 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[3].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y + 1 == sBlockIndex3_S2[3].m_cLocate.Y))
			{
				sBlockIndex3_S2[3].m_cLocate.Y++;
				g_sChar3_Stage2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y + 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[4].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y + 1 == sBlockIndex3_S2[4].m_cLocate.Y))
			{
				sBlockIndex3_S2[4].m_cLocate.Y++;
				g_sChar3_Stage2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock3_S2(g_sChar3_Stage2.m_cLocation.X, g_sChar3_Stage2.m_cLocation.Y + 1)) && (g_sChar3_Stage2.m_cLocation.X == sBlockIndex3_S2[5].m_cLocate.X) && (g_sChar3_Stage2.m_cLocation.Y + 1 == sBlockIndex3_S2[5].m_cLocate.Y))
			{
				sBlockIndex3_S2[5].m_cLocate.Y++;
				g_sChar3_Stage2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar3_Stage2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}

		}
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}