// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>

double  g_dElapsedTime;
double  g_dDeltaTime;
double  GameTime;
bool    g_abKeyPressed[K_COUNT];
bool	paused = false;

// Game specific variables here
SGameChar   g_sChar;
SGameChar	g_sArrow;
SGameChar	g_sBlock1;
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once

// Console object
Console g_Console(80, 25, "SP1 Framework");


int playersteps;


//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init(void)
{
	// Set precision for floating point output
	g_dElapsedTime = 0.0;
	g_dBounceTime = 0.0;
	GameTime = 0.0;
	playersteps = 0;

	// sets the initial state for the game
	g_eGameState = S_SPLASHSCREEN;
	// character initialisation
	g_sChar.m_cLocation.X = 12;
	g_sChar.m_cLocation.Y = 5;
	g_sChar.bPassable = false;

	g_sArrow.m_cLocation.X = g_Console.getConsoleSize().X / 2 - 15;
	g_sArrow.m_cLocation.Y = 3;
	// block initialisation
	g_sBlock1.m_cLocation.X = 25;
	g_sBlock1.m_cLocation.Y = 9;
	g_sBlock1.bPassable = false;

	// sets the width, height and the font name to use in the console
	g_Console.setConsoleFont(2, 39, L"Consolas");
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown(void)
{
	// Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Getting all the key press states
//            This function checks if any key had been pressed since the last time we checked
//            If a key is pressed, the value for that particular key will be true
//
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput(void)
{
	g_abKeyPressed[K_PAUSE] = isKeyPressed(0x50);
	g_abKeyPressed[K_ENTER] = isKeyPressed(VK_RETURN);
	if (!paused)
	{
		g_abKeyPressed[K_UP] = isKeyPressed(VK_UP);
		g_abKeyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
		g_abKeyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
		g_abKeyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
		g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	}
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
	// get the delta time
	g_dElapsedTime += dt;
	g_dDeltaTime = dt;

	switch (g_eGameState)
	{
	case S_SPLASHSCREEN: splashScreenWait(); // game logic for the splash screen
		break;
	case S_GAME: gameplay(); // gameplay logic when we are in the game
		break;
	case S_MENU: menu(); // menu for game
		break;
	case S_STORY: story(); // story for game
		break;
	}
}

//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
	clearScreen();      // clears the current screen and draw from scratch 
	switch (g_eGameState)
	{
	case S_SPLASHSCREEN: renderSplashScreen();
		break;
	case S_GAME: renderGame();
		break;
	case S_MENU: renderMenu();
		break;
	case S_STORY: renderStory(); // pause game
		break;
	}
	renderFramerate();  // renders debug information, frame rate, elapsed time, etc
	renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

//--------------------------------------------------------------
// Purpose	: Render the functions for the screens
// Input	: void
// Output   : void
//--------------------------------------------------------------
void splashScreenWait()    // waits for time to pass in splash screen
{
	if (g_dElapsedTime > 1.0) // wait for 3 seconds to switch to game mode, else do nothing
		g_eGameState = S_MENU;
}

void menu()
{
	processUserInput(); // process user input function
	movemenuarrow(); // process arrow movement
}

void story()
{
	processUserInput(); // process user input function
}

void gameplay()            // gameplay logic
{
	processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
	moveCharacter();    // moves the character, collision detection, physics, etc
	pause();
	TimeCheck();
	// sound can be played here too.
}

//--------------------------------------------------------------
// Purpose	: Functions that are in the render screens group
// Input	: void
// Output   : void
//--------------------------------------------------------------


void moveCharacter()
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
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
				playersteps++;
			}
		}
		else
		{
			if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y - 1)) && (g_sChar.m_cLocation.X == g_sBlock1.m_cLocation.X) && (g_sChar.m_cLocation.Y - 1 == g_sBlock1.m_cLocation.Y))
				{
					g_sBlock1.m_cLocation.Y--;
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
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
				playersteps++;
			}
		}
		else
		{
			if ((!checkblock(g_sChar.m_cLocation.X - 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X - 1) == g_sBlock1.m_cLocation.X) && (g_sChar.m_cLocation.Y == g_sBlock1.m_cLocation.Y))
			{
				g_sBlock1.m_cLocation.X--;
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
				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
				playersteps++;
			}
		}
		else
		{
			if ((!checkblock(g_sChar.m_cLocation.X + 1, g_sChar.m_cLocation.Y)) && ((g_sChar.m_cLocation.X + 1) == g_sBlock1.m_cLocation.X) && (g_sChar.m_cLocation.Y == g_sBlock1.m_cLocation.Y))
			{
				g_sBlock1.m_cLocation.X++;
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

		if (!IsPassable(g_sChar.m_cLocation.X , g_sChar.m_cLocation.Y+ 2))
		{
			if (IsPassable(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y + 1))
			{
				g_sChar.m_cLocation.Y++;
				bSomethingHappened = true;
				playersteps++;
			}
		}
		else
		{
			if ((!checkblock(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y+1)) && (g_sChar.m_cLocation.X == g_sBlock1.m_cLocation.X) && (g_sChar.m_cLocation.Y+ 1 == g_sBlock1.m_cLocation.Y))
			{
				g_sBlock1.m_cLocation.Y++;
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


void processUserInput()
{
}

void movemenuarrow()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;


	// Code to move arrow down
	if ((g_abKeyPressed[K_DOWN] && (g_sArrow.m_cLocation.Y == 3)) || (g_abKeyPressed[K_DOWN] && (g_sArrow.m_cLocation.Y == 6)))
	{
		//Beep(1440, 30);
		g_sArrow.m_cLocation.Y += 3;
		bSomethingHappened = true;
	}

	// Code to move arrow up
	if (g_abKeyPressed[K_UP] && ((g_sArrow.m_cLocation.Y == 6) || (g_sArrow.m_cLocation.Y == 9)))
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
		else
		{
			if (g_sArrow.m_cLocation.Y == 9)
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

void pause()
{

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
}


void clearScreen()
{
	// Clears the buffer with this colour attribute
	g_Console.clearBuffer(0x03);
} // Background colour for the screen

// ------------------------------------------------------------- 
// Purpose	: The different levels 
// Input    : g_eGameState
// Output   : void
//--------------------------------------------------------------

void renderSplashScreen()  // renders the splash screen
{
	COORD c = g_Console.getConsoleSize();

	// CREATING TITLE//
	c.Y = 3;

	// Adding in the text file
	c.X = g_Console.getConsoleSize().X / 2 - 30;

	string line;
	ifstream myfile("SplashScreen.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			c.Y += 1;
			g_Console.writeToBuffer(c, line);
		}
		myfile.close();
	}

}

void renderMenu()
{
	COORD c = g_Console.getConsoleSize();

	c.Y = 3; // Game at y 3
	c.X = g_Console.getConsoleSize().X / 2 - 9;
	g_Console.writeToBuffer(c, "Start Game");

	c.Y += 3; // Story at y 6
	g_Console.writeToBuffer(c, "Story", 0x03);

	c.Y += 3; // Story at y 9
	c.X = g_Console.getConsoleSize().X / 2 - 9;
	g_Console.writeToBuffer(c, "Quit Game", 0x03);


	c.Y = 14;
	c.X = 33;

	string line;
	ifstream myfile("MenuInstructions.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			c.Y += 1;
			g_Console.writeToBuffer(c, line);
		}
		myfile.close();
	}

	g_Console.writeToBuffer(g_sArrow.m_cLocation, ">");

}

void renderStory()
{
	COORD c = g_Console.getConsoleSize();

	c.Y = 3; // Story at y 9
	c.X = g_Console.getConsoleSize().X / 2 - 9;
	g_Console.writeToBuffer(c, "Insert Story line using text file and letters by letters", 0x03);

	c.Y += 3;
	c.X = 0;
	string line;
	ifstream myfile("Story.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			c.Y += 1;
			g_Console.writeToBuffer(c, line);
		}
		myfile.close();
	}
}

void renderGame()
{
	renderMap();        // renders the map to the buffer first
	renderCharacter();  // renders the character into the buffer
	renderplayerandgametime();
}

//--------------------------------------------------------------
// Purpose	: Renders the display onto the screen
// Input	: void
// Output   : void
//--------------------------------------------------------------

void renderMap()
{
	if (!paused)
	{
		Level1();
		GameInstruction();
	}
}

void renderCharacter()
{
	if (!paused)
	{
		// Draw the location of the character
		WORD charColor = 0x01;
			g_Console.writeToBuffer(g_sBlock1.m_cLocation, 'B', 4);

		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)1, charColor);
	}
}

void renderFramerate()
{
	COORD c;

	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	if (!paused)
	{
		// displays the framerate
		ss << (int) (1.0 / g_dDeltaTime) << "fps";
		c.X = g_Console.getConsoleSize().X - 5;
		c.Y = 0;
		g_Console.writeToBuffer(c, ss.str());


		// displays the system elapsed time
		ss.str("");
		ss << g_dElapsedTime << "secs";
		c.X = 0;
		c.Y = 0;
		//g_Console.writeToBuffer(c, ss.str());


		ss.str("");
		ss << "x location: " << g_sChar.m_cLocation.X << " & y location: " << g_sChar.m_cLocation.Y;
		c.Y = 1;
		g_Console.writeToBuffer(c, ss.str());
	}
	else
	{
		c.Y = 0;
		c.X = g_Console.getConsoleSize().X / 2;
		g_Console.writeToBuffer(c, "Game Paused");

		// displays the framerate
		ss << (int)(1.0 / g_dDeltaTime) << "fps";
		c.X = g_Console.getConsoleSize().X - 5;
		c.Y = 0;
		g_Console.writeToBuffer(c, ss.str());

		// displays the system elapsed time
		ss.str("");
		ss << g_dElapsedTime << "secs";
		c.X = 0;
		c.Y = 0;
		//g_Console.writeToBuffer(c, ss.str());


		ss.str("");
		ss << "x location: " << g_sChar.m_cLocation.X << " & y location: " << g_sChar.m_cLocation.Y;
		c.Y = 1;
		g_Console.writeToBuffer(c, ss.str());
	}
}

void TimeCheck()
{
	if (!paused)
	{
		GameTime += g_dDeltaTime;
	}
}

void renderplayerandgametime()
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

void renderToScreen()
{
	// Writes the buffer to the console, hence you will see what you have written
	g_Console.flushBufferToConsole();
}