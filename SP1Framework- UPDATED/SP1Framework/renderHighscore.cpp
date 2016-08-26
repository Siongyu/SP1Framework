#include "renderHighscore.h"

extern Console g_Console;

void displayHighscore() {

	COORD c = g_Console.getConsoleSize();
	c.Y = 1;
	c.X = g_Console.getConsoleSize().X / 2 - 30;

	string line;
	ifstream myFile("scoreTitle.txt");

	if (myFile.is_open()) {

		while (getline(myFile, line)) {

			c.Y += 1;
			g_Console.writeToBuffer(c, line);
		}
		myFile.close();
	}
}