#include "moveCharacter.h"

void moveCharacter2()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	// Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
	if (g_abKeyPressed[K_UP])
	{
		if (!IsPassable2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 2))
		{
			if (IsPassable2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 1))
			{
				if (checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 1))
				{
					g_sChar2.m_cLocation.Y--;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[0].m_cLocate.X) && ((g_sChar2.m_cLocation.Y - 1) == sBlockIndex2[0].m_cLocate.Y))
			{
				sBlockIndex2[0].m_cLocate.Y--;
				g_sChar2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[1].m_cLocate.X) && ((g_sChar2.m_cLocation.Y - 1) == sBlockIndex2[1].m_cLocate.Y))
			{
				sBlockIndex2[1].m_cLocate.Y--;
				g_sChar2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[2].m_cLocate.X) && ((g_sChar2.m_cLocation.Y - 1) == sBlockIndex2[2].m_cLocate.Y))
			{
				sBlockIndex2[2].m_cLocate.Y--;
				g_sChar2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[3].m_cLocate.X) && ((g_sChar2.m_cLocation.Y - 1) == sBlockIndex2[3].m_cLocate.Y))
			{
				sBlockIndex2[3].m_cLocate.Y--;
				g_sChar2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[4].m_cLocate.X) && ((g_sChar2.m_cLocation.Y - 1) == sBlockIndex2[4].m_cLocate.Y))
			{
				sBlockIndex2[4].m_cLocate.Y--;
				g_sChar2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[5].m_cLocate.X) && ((g_sChar2.m_cLocation.Y - 1) == sBlockIndex2[5].m_cLocate.Y))
			{
				sBlockIndex2[5].m_cLocate.Y--;
				g_sChar2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[6].m_cLocate.X) && ((g_sChar2.m_cLocation.Y - 1) == sBlockIndex2[6].m_cLocate.Y))
			{
				sBlockIndex2[6].m_cLocate.Y--;
				g_sChar2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[7].m_cLocate.X) && ((g_sChar2.m_cLocation.Y - 1) == sBlockIndex2[7].m_cLocate.Y))
			{
				sBlockIndex2[7].m_cLocate.Y--;
				g_sChar2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y - 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[8].m_cLocate.X) && ((g_sChar2.m_cLocation.Y - 1) == sBlockIndex2[8].m_cLocate.Y))
			{
				sBlockIndex2[8].m_cLocate.Y--;
				g_sChar2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar2.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
		}
	}


	if (g_abKeyPressed[K_LEFT])
	{

		if (!IsPassable2(g_sChar2.m_cLocation.X - 2, g_sChar2.m_cLocation.Y))
		{
			if (IsPassable2(g_sChar2.m_cLocation.X - 1, g_sChar2.m_cLocation.Y))
			{
				if (checkblock2(g_sChar2.m_cLocation.X - 1, g_sChar2.m_cLocation.Y))
				{
					g_sChar2.m_cLocation.X--;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock2(g_sChar2.m_cLocation.X - 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X - 1) == sBlockIndex2[0].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[0].m_cLocate.Y))
			{
				sBlockIndex2[0].m_cLocate.X--;
				g_sChar2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X - 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X - 1) == sBlockIndex2[1].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[1].m_cLocate.Y))
			{
				sBlockIndex2[1].m_cLocate.X--;
				g_sChar2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X - 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X - 1) == sBlockIndex2[2].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[2].m_cLocate.Y))
			{
				sBlockIndex2[2].m_cLocate.X--;
				g_sChar2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X - 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X - 1) == sBlockIndex2[3].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[3].m_cLocate.Y))
			{
				sBlockIndex2[3].m_cLocate.X--;
				g_sChar2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X - 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X - 1) == sBlockIndex2[4].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[4].m_cLocate.Y))
			{
				sBlockIndex2[4].m_cLocate.X--;
				g_sChar2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X - 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X - 1) == sBlockIndex2[5].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[5].m_cLocate.Y))
			{
				sBlockIndex2[5].m_cLocate.X--;
				g_sChar2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X - 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X - 1) == sBlockIndex2[6].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[6].m_cLocate.Y))
			{
				sBlockIndex2[6].m_cLocate.X--;
				g_sChar2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X - 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X - 1) == sBlockIndex2[7].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[7].m_cLocate.Y))
			{
				sBlockIndex2[7].m_cLocate.X--;
				g_sChar2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X - 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X - 1) == sBlockIndex2[8].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[8].m_cLocate.Y))
			{
				sBlockIndex2[8].m_cLocate.X--;
				g_sChar2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar2.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}

		}
	}


	if (g_abKeyPressed[K_RIGHT])
	{
		if (!IsPassable2(g_sChar2.m_cLocation.X + 2, g_sChar2.m_cLocation.Y))
		{
			if (IsPassable2(g_sChar2.m_cLocation.X + 1, g_sChar2.m_cLocation.Y))
			{
				if (checkblock2(g_sChar2.m_cLocation.X + 1, g_sChar2.m_cLocation.Y))
				{
					g_sChar2.m_cLocation.X++;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock2(g_sChar2.m_cLocation.X + 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X + 1) == sBlockIndex2[0].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[0].m_cLocate.Y))
			{
				sBlockIndex2[0].m_cLocate.X++;
				g_sChar2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X + 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X + 1) == sBlockIndex2[1].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[1].m_cLocate.Y))
			{
				sBlockIndex2[1].m_cLocate.X++;
				g_sChar2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X + 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X + 1) == sBlockIndex2[2].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[2].m_cLocate.Y))
			{
				sBlockIndex2[2].m_cLocate.X++;
				g_sChar2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X + 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X + 1) == sBlockIndex2[3].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[3].m_cLocate.Y))
			{
				sBlockIndex2[3].m_cLocate.X++;
				g_sChar2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X + 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X + 1) == sBlockIndex2[4].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[4].m_cLocate.Y))
			{
				sBlockIndex2[4].m_cLocate.X++;
				g_sChar2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X + 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X + 1) == sBlockIndex2[5].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[5].m_cLocate.Y))
			{
				sBlockIndex2[5].m_cLocate.X++;
				g_sChar2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X + 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X + 1) == sBlockIndex2[6].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[6].m_cLocate.Y))
			{
				sBlockIndex2[6].m_cLocate.X++;
				g_sChar2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X + 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X + 1) == sBlockIndex2[7].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[7].m_cLocate.Y))
			{
				sBlockIndex2[7].m_cLocate.X++;
				g_sChar2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X + 1, g_sChar2.m_cLocation.Y)) && ((g_sChar2.m_cLocation.X + 1) == sBlockIndex2[8].m_cLocate.X) && (g_sChar2.m_cLocation.Y == sBlockIndex2[8].m_cLocate.Y))
			{
				sBlockIndex2[8].m_cLocate.X++;
				g_sChar2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar2.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}

		}
	}


	if (g_abKeyPressed[K_DOWN])
	{

		if (!IsPassable2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 2))
		{
			if (IsPassable2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 1))
			{
				if (checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 1))
				{
					g_sChar2.m_cLocation.Y++;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[0].m_cLocate.X) && (g_sChar2.m_cLocation.Y + 1 == sBlockIndex2[0].m_cLocate.Y))
			{
				sBlockIndex2[0].m_cLocate.Y++;
				g_sChar2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[1].m_cLocate.X) && (g_sChar2.m_cLocation.Y + 1 == sBlockIndex2[1].m_cLocate.Y))
			{
				sBlockIndex2[1].m_cLocate.Y++;
				g_sChar2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[2].m_cLocate.X) && (g_sChar2.m_cLocation.Y + 1 == sBlockIndex2[2].m_cLocate.Y))
			{
				sBlockIndex2[2].m_cLocate.Y++;
				g_sChar2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[3].m_cLocate.X) && (g_sChar2.m_cLocation.Y + 1 == sBlockIndex2[3].m_cLocate.Y))
			{
				sBlockIndex2[3].m_cLocate.Y++;
				g_sChar2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[4].m_cLocate.X) && (g_sChar2.m_cLocation.Y + 1 == sBlockIndex2[4].m_cLocate.Y))
			{
				sBlockIndex2[4].m_cLocate.Y++;
				g_sChar2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[5].m_cLocate.X) && (g_sChar2.m_cLocation.Y + 1 == sBlockIndex2[5].m_cLocate.Y))
			{
				sBlockIndex2[5].m_cLocate.Y++;
				g_sChar2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[6].m_cLocate.X) && (g_sChar2.m_cLocation.Y + 1 == sBlockIndex2[6].m_cLocate.Y))
			{
				sBlockIndex2[6].m_cLocate.Y++;
				g_sChar2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[7].m_cLocate.X) && (g_sChar2.m_cLocation.Y + 1 == sBlockIndex2[7].m_cLocate.Y))
			{
				sBlockIndex2[7].m_cLocate.Y++;
				g_sChar2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock2(g_sChar2.m_cLocation.X, g_sChar2.m_cLocation.Y + 1)) && (g_sChar2.m_cLocation.X == sBlockIndex2[8].m_cLocate.X) && (g_sChar2.m_cLocation.Y + 1 == sBlockIndex2[8].m_cLocate.Y))
			{
				sBlockIndex2[8].m_cLocate.Y++;
				g_sChar2.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar2.m_cLocation.Y++;
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
