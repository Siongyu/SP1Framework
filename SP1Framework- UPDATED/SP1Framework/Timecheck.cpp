#include "Timecheck.h"
void timecheck()
{
	if (!paused)
	{
		GameTime += g_dDeltaTime;
	}
}