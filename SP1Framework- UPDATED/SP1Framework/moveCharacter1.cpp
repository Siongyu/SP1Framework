#include "moveCharacter.h"

void moveCharacter1()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	// Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
	if (g_abKeyPressed[K_UP])
	{
		if (!IsPassable(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y - 2))
		{
			if (IsPassable(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y - 1))
			{
				if (checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y - 1))
				{
					g_sChar.m_cLocation.Y--;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{			
			if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y - 1)) && (g_sChar.m_cLocation.X == sBlockIndex[0].m_cLocate.X) && ((g_sChar.m_cLocation.Y - 1) == sBlockIndex[0].m_cLocate.Y))
			{
				sBlockIndex[0].m_cLocate.Y--;
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y - 1)) && (g_sChar.m_cLocation.X == sBlockIndex[1].m_cLocate.X) && ((g_sChar.m_cLocation.Y - 1) == sBlockIndex[1].m_cLocate.Y))
			{
				sBlockIndex[1].m_cLocate.Y--;
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y - 1)) && (g_sChar.m_cLocation.X == sBlockIndex[2].m_cLocate.X) && ((g_sChar.m_cLocation.Y - 1) == sBlockIndex[2].m_cLocate.Y))
			{
				sBlockIndex[2].m_cLocate.Y--;
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y - 1)) && (g_sChar.m_cLocation.X == sBlockIndex[3].m_cLocate.X) && ((g_sChar.m_cLocation.Y - 1) == sBlockIndex[3].m_cLocate.Y))
			{
				sBlockIndex[3].m_cLocate.Y--;
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y - 1)) && (g_sChar.m_cLocation.X == sBlockIndex[4].m_cLocate.X) && ((g_sChar.m_cLocation.Y - 1) == sBlockIndex[4].m_cLocate.Y))
			{
				sBlockIndex[4].m_cLocate.Y--;
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y - 1)) && (g_sChar.m_cLocation.X == sBlockIndex[5].m_cLocate.X) && ((g_sChar.m_cLocation.Y - 1) == sBlockIndex[5].m_cLocate.Y))
			{
				sBlockIndex[5].m_cLocate.Y--;
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
		}
	}


	if (g_abKeyPressed[K_LEFT])
	{

		if (!IsPassable(g_sChar.m_cLocation.X - 2, g_sChar.m_cLocation.Y))
		{
			if (IsPassable(g_sChar.m_cLocation.X - 1, g_sChar.m_cLocation.Y))
			{
				if (checkblock(g_sChar.m_cLocation.X - 1, g_sChar.m_cLocation.Y))
				{
					g_sChar.m_cLocation.X--;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock(g_sChar.m_cLocation.X - 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X - 1) == sBlockIndex[0].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[0].m_cLocate.Y))
			{
				sBlockIndex[0].m_cLocate.X--;
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X - 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X - 1) == sBlockIndex[1].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[1].m_cLocate.Y))
			{
				sBlockIndex[1].m_cLocate.X--;
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X - 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X - 1) == sBlockIndex[2].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[2].m_cLocate.Y))
			{
				sBlockIndex[2].m_cLocate.X--;
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X - 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X - 1) == sBlockIndex[3].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[3].m_cLocate.Y))
			{
				sBlockIndex[3].m_cLocate.X--;
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X - 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X - 1) == sBlockIndex[4].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[4].m_cLocate.Y))
			{
				sBlockIndex[4].m_cLocate.X--;
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X - 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X - 1) == sBlockIndex[5].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[5].m_cLocate.Y))
			{
				sBlockIndex[5].m_cLocate.X--;
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}

		}
	}


	if (g_abKeyPressed[K_RIGHT])
	{
		if (!IsPassable(g_sChar.m_cLocation.X + 2, g_sChar.m_cLocation.Y))
		{
			if (IsPassable(g_sChar.m_cLocation.X + 1, g_sChar.m_cLocation.Y))
			{
				if (checkblock(g_sChar.m_cLocation.X + 1, g_sChar.m_cLocation.Y))
				{
					g_sChar.m_cLocation.X++;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock(g_sChar.m_cLocation.X + 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X + 1) == sBlockIndex[0].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[0].m_cLocate.Y))
			{
				sBlockIndex[0].m_cLocate.X++;
				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X + 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X + 1) == sBlockIndex[1].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[1].m_cLocate.Y))
			{
				sBlockIndex[1].m_cLocate.X++;
				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X + 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X + 1) == sBlockIndex[2].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[2].m_cLocate.Y))
			{
				sBlockIndex[2].m_cLocate.X++;
				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X + 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X + 1) == sBlockIndex[3].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[3].m_cLocate.Y))
			{
				sBlockIndex[3].m_cLocate.X++;
				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X + 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X + 1) == sBlockIndex[4].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[4].m_cLocate.Y))
			{
				sBlockIndex[4].m_cLocate.X++;
				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X + 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X + 1) == sBlockIndex[5].m_cLocate.X) && (g_sChar.m_cLocation.Y == sBlockIndex[5].m_cLocate.Y))
			{
				sBlockIndex[5].m_cLocate.X++;
				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}

		}
	}


	if (g_abKeyPressed[K_DOWN])
	{

		if (!IsPassable(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y + 2))
		{
			if (IsPassable(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y + 1))
			{
				if (checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y + 1))
				{
					g_sChar.m_cLocation.Y++;
					bSomethingHappened = true;
					playersteps++;
				}
			}
		}
		else
		{
			if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y + 1)) && (g_sChar.m_cLocation.X == sBlockIndex[0].m_cLocate.X) && (g_sChar.m_cLocation.Y + 1 == sBlockIndex[0].m_cLocate.Y))
			{
				sBlockIndex[0].m_cLocate.Y++;
				g_sChar.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y + 1)) && (g_sChar.m_cLocation.X == sBlockIndex[1].m_cLocate.X) && (g_sChar.m_cLocation.Y + 1 == sBlockIndex[1].m_cLocate.Y))
			{
				sBlockIndex[1].m_cLocate.Y++;
				g_sChar.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y + 1)) && (g_sChar.m_cLocation.X == sBlockIndex[2].m_cLocate.X) && (g_sChar.m_cLocation.Y + 1 == sBlockIndex[2].m_cLocate.Y))
			{
				sBlockIndex[2].m_cLocate.Y++;
				g_sChar.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y + 1)) && (g_sChar.m_cLocation.X == sBlockIndex[3].m_cLocate.X) && (g_sChar.m_cLocation.Y + 1 == sBlockIndex[3].m_cLocate.Y))
			{
				sBlockIndex[3].m_cLocate.Y++;
				g_sChar.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y + 1)) && (g_sChar.m_cLocation.X == sBlockIndex[4].m_cLocate.X) && (g_sChar.m_cLocation.Y + 1 == sBlockIndex[4].m_cLocate.Y))
			{
				sBlockIndex[4].m_cLocate.Y++;
				g_sChar.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y + 1)) && (g_sChar.m_cLocation.X == sBlockIndex[5].m_cLocate.X) && (g_sChar.m_cLocation.Y + 1 == sBlockIndex[5].m_cLocate.Y))
			{
				sBlockIndex[5].m_cLocate.Y++;
				g_sChar.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
			else
			{
				g_sChar.m_cLocation.Y++;
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
