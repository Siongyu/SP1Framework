/*#include "game.h"
#include "Framework\console.h"
#include <iomanip>
#include <sstream>

double  g_dElapsedTime;
double  g_dBounceTime;
bool    g_abKeyPressed[K_COUNT];
bool	paused = false;

void pause()
{
	g_abKeyPressed[K_PAUSE] = isKeyPressed(0x50);
	g_dElapsedTime = 0.0;
	g_dBounceTime = 0.0;

	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;
	if (g_abKeyPressed[K_PAUSE])
	{
		paused = !paused;
		(bSomethingHappened) = true;
	}
	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}*/
