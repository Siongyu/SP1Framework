#include "Renderplayerandgametime.h"
extern Console g_Console;
void Renderplayerandgametime()
{
	COORD c;

	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	if (!paused)
	{
		// displays the game elapsed time
		ss.str("");
		ss << "Game Time: " << GameTime;
		c.X = 5;
		c.Y = 19;
		g_Console.writeToBuffer(c, ss.str());

		ss.str("");
		ss << "Player Steps: " << playersteps;
		c.X = 5;
		c.Y = 22;
		g_Console.writeToBuffer(c, ss.str());
	}
}