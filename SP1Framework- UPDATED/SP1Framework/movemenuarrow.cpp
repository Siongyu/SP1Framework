#include "movemenuarrow.h"

void Movemenuarrow()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;


	// Code to move arrow down
	if ((g_abKeyPressed[K_DOWN] && (g_sArrow.m_cLocation.Y == 3)) || (g_abKeyPressed[K_DOWN] && (g_sArrow.m_cLocation.Y == 6)) || (g_abKeyPressed[K_DOWN] && (g_sArrow.m_cLocation.Y == 9)))
	{
		//Beep(1440, 30);
		g_sArrow.m_cLocation.Y += 3;
		bSomethingHappened = true;
	}

	// Code to move arrow up
	if (g_abKeyPressed[K_UP] && ((g_sArrow.m_cLocation.Y == 6) || (g_sArrow.m_cLocation.Y == 9) || (g_sArrow.m_cLocation.Y == 12)))
	{
		//Beep(1440, 30);
		g_sArrow.m_cLocation.Y -= 3;
		bSomethingHappened = true;
	}




	if (g_abKeyPressed[K_ENTER])
	{
		if (g_sArrow.m_cLocation.Y == 3)
		{
			g_eGameState = S_GAME;
		}
		else if (g_sArrow.m_cLocation.Y == 6)
		{
			g_eGameState = S_STORY;
		}
		else if (g_sArrow.m_cLocation.Y == 9)
		{
			g_eGameState = S_SCORE;
		}
		else
		{
			if (g_sArrow.m_cLocation.Y == 12)
			{
				g_bQuitGame = true;
			}
		}
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}