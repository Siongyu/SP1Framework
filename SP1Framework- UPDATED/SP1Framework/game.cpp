// This is the main file for the game logic and function
//
//
#include "game.h"
#include "moveCharacter.h"
#include "movemenuarrow.h"
#include "Renderplayerandgametime.h"
#include "Timecheck.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "highscore.h"
#include "restart.h"
#include "Pause.h"

double  g_dElapsedTime;
double  g_dDeltaTime;
double  GameTime;
bool    g_abKeyPressed[K_COUNT];
extern bool	paused = false;
bool completedlevel1 = false;
bool completedlevel2 = false;
bool completedlevel3 = false;
bool completedlevel3_S2 = false;


// Game specific variables here
SGameChar  g_sChar;
SGameChar	g_sChar2;
SGameChar g_sChar3;
SGameChar g_sChar3_Stage2;
SGameChar	g_sArrow;

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


		g_sChar2.m_cLocation.X = 12;
		g_sChar2.m_cLocation.Y = 4;
		g_sChar2.bPassable = false;

		g_sChar3.m_cLocation.X = 12;
		g_sChar3.m_cLocation.Y = 5;
		g_sChar3.bPassable = false;

		g_sChar3_Stage2.m_cLocation.X = 2;
		g_sChar3_Stage2.m_cLocation.Y = 5;
		g_sChar3_Stage2.bPassable = false;

	g_sArrow.m_cLocation.X = g_Console.getConsoleSize().X / 2 - 15;
	g_sArrow.m_cLocation.Y = 3;

	// sets the width, height and the font name to use in the console
	g_Console.setConsoleFont(2, 39, L"Arial");
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
	g_abKeyPressed[K_RESTART] = isKeyPressed(0x52);
	g_abKeyPressed[K_ENTER] = isKeyPressed(VK_RETURN);
	if (!paused)
	{
		g_abKeyPressed[K_UP] = isKeyPressed(VK_UP);
		g_abKeyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
		g_abKeyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
		g_abKeyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
		g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
		g_abKeyPressed[K_RESTART] = isKeyPressed(0x52);
		g_abKeyPressed[K_BACK] = isKeyPressed(VK_BACK);
	}
}

// ------------------------------------------------------U P D A T E ------------------------------------- //

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
	case S_GAME1: gameplay(); // gameplay logic when we are in the game
		break;
	case S_GAME2: gameplay();
		break;
	case S_GAME2_S2: gameplay();
		break;
	case S_MENU: menu(); // menu for game
		break;
	case S_STORY: Story(); // story for game
		break;
	}
}


//--------------------------------------------------------------
// Purpose	: Render the functions for the screens
// Input	: void
// Output   : void
//--------------------------------------------------------------
void splashScreenWait()    // waits for time to pass in splash screen
{
	if (g_dElapsedTime > 1.0) // wait for 1 seconds to switch to game mode, else do nothing
		g_eGameState = S_MENU;
}

void menu()
{
	Movemenuarrow(); // process arrow movement
	processUserInput();
}

void gameplay()            // gameplay logic
{
	if (!completedlevel1)
	{
		end1();
		moveCharacter1();
	}
	else if (!completedlevel2)
	{
		end2();
		moveCharacter2();
	}
	else if (!completedlevel3)
	{
		end3();
		moveCharacter3();
	}
	else if (!completedlevel3_S2)
	{
		end3_S2();
		moveCharacter3_S2();
	}
	Restart();
	timecheck();
	Pause();
	// sound can be played here too.
}

//--------------------------------------------------------------
// Purpose	: Functions that are in the update group
// Input	: void
// Output   : void
//--------------------------------------------------------------

void processUserInput()
{
	
	if (g_abKeyPressed[K_BACK] && g_eGameState == S_STORY)
	{
		g_bBackspace = true;
		g_eGameState = S_MENU;
	}
	if (g_abKeyPressed[K_BACK] && g_eGameState == S_SCORE)
	{
		g_bBackspace = true;
		g_eGameState = S_MENU;
	}
}

void clearScreen()
{
	// Clears the buffer with this colour attribute
	g_Console.clearBuffer(0x03);
} // Background colour for the screen





// ------------------------------------------------------R E N D E R ------------------------------------- //






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
	case S_GAME1: renderGame1();
		break;
	case S_GAME2: renderGame2();
		break;
	case S_GAME2_S2: renderGame2_Stage2();
		break;
	case S_MENU: renderMenu();
		break;
	case S_STORY: renderStory(); 
		break;
	case S_SCORE: renderScore();
		break;
	}
	renderFramerate();  // renders debug information, frame rate, elapsed time, etc
	renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}



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
	g_Console.writeToBuffer(c, "ScoreBoard", 0x03);

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
	Story();
}

void renderGame()
{
	renderMap1();        // renders the map to the buffer first
	characterlevel1();  // renders the character into the buffer
	renderplayerandgametime();
}

void renderGame1()
{
	renderMap2();
	characterlevel2();
	renderplayerandgametime();
}

void renderGame2()
{
	renderMap3();
	characterlevel3();
	renderplayerandgametime();
}

void renderGame2_Stage2()
{
	renderMap3_Stage2();
	characterlevel3_S2();

	renderplayerandgametime();
}


//--------------------------------------------------------------
// Purpose	: Renders the display onto the screen
// Input	: void
// Output   : void
//--------------------------------------------------------------

void renderMap1()
{
	if (!paused)
	{
		Level1();
		GameInstruction();
	}
}

void renderMap2()
{
	if (!paused)
	{
		Level2();
		GameInstruction();
	}
}

void renderMap3()
{
	if (!paused)
	{
		Level3_Stage1();
		GameInstruction();
	}
}

void renderMap3_Stage2()
{
	if (!paused)
	{
		Level3_Stage2();
		GameInstruction();
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
		//g_Console.writeToBuffer(c, ss.str());
		ss.str("");
		ss << "x location: " << g_sChar2.m_cLocation.X << " & y location: " << g_sChar2.m_cLocation.Y;
		c.Y = 1;
		//g_Console.writeToBuffer(c, ss.str());
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
		//g_Console.writeToBuffer(c, ss.str());
		ss.str("");
		ss << "x location: " << g_sChar2.m_cLocation.X << " & y location: " << g_sChar2.m_cLocation.Y;
		c.Y = 1;
		//g_Console.writeToBuffer(c, ss.str());
	}
}

void renderplayerandgametime()
{
	timecheck();
	Renderplayerandgametime();
}

void renderToScreen()
{
	// Writes the buffer to the console, hence you will see what you have written
	g_Console.flushBufferToConsole();
}
