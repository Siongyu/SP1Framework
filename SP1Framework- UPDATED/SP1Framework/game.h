#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include "textfile.h"
#include "Framework\console.h"


extern CStopWatch g_swTimer;
extern bool g_bQuitGame;
extern bool g_bBackspace;

// Enumeration to store the control keys that your game will have
enum EKEYS
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
	K_ENTER,
    K_ESCAPE,
	K_PAUSE,
	K_RESTART,
	K_BACK,
    K_COUNT
};

// Enumeration for the different screen states
enum EGAMESTATES
{
    S_SPLASHSCREEN,
    S_GAME, // level 1
	S_GAME1, // level 2
	S_GAME2, // level 3 stage 1
	S_GAME2_S2, // level 3 stage 2
	S_MENU,
	S_STORY,
	S_SCORE,
    S_COUNT
};

// struct for the game character
struct SGameChar
{
	COORD m_cLocation;
	bool	bPassable;
};

struct SGameBlock
{
	COORD m_cLocate;
	bool	bPassable;
};

struct SGameBlock2
{
	COORD m_cLocate;
	char    nCharacter; // ASCII character for this tile type
	short   nColorCode; // Color code for this tile type
	bool	bPassable;
};

struct SGameBlock3
{
	COORD m_cLocate;
	bool	bPassable;
};

struct SGameBlock3_Stage2
{
	COORD m_cLocate;
	char    nCharacter; // ASCII character for this tile type
	short   nColorCode; // Color code for this tile type
	bool	bPassable;
};

void init        ( void );      // initialize your variables, allocate memory, etc
void getInput    ( void );      // get input from player
void update      ( double dt ); // update the game and the state of the game
void render      ( void );      // renders the current state of the game to the console
void shutdown    ( void );      // do clean up, free memory

void splashScreenWait();    // waits for time to pass in splash screen
void gameplay();            // gameplay logic
void menu();				// menu logic
void moveCharacter();       // moves the character, collision detection, physics, etc, done 
void processUserInput();	
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void renderMenu();			// renders the menu
void renderStory();			
void renderGame();			 // renders the game stuff
void renderGame1();
void renderGame2();
void renderGame2_Stage2();
void renderScore();			// renders the map to the buffer first
void renderFramerate();     // renders debug information, frame rate, system elapsed time, etc
void renderplayerandgametime(); // renders game time and player steps 
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game

void Story();
void GameInstruction();
void timecheck();

//------------------------LEVEL 1------------------//

// function call
void Level1(); // load the map

// render map
void characterlevel1();
void renderMap1();
void moveCharacter1();       // moves the character, collision detection, physics, etc, done 
bool IsPassable(int nMapX, int nMapY);
bool checkblock(int charMapX, int charMapY);

// completed function
void end1();

/* end of level 1*/


// ------------------------LEVEL 2-----------------//

// function call
void Level2(); // load the map

// render map
void characterlevel2();
void renderMap2();
void moveCharacter2();
bool IsPassable2(int nMapX, int nMapY);
bool checkblock2(int charMapX, int charMapY);

// completed function
void end2();

/* end of level 2*/

// ----------------------LEVEL 3 Stage 1------------------//

//function call
void Level3_Stage1(); // load the map

// render the map
void characterlevel3();
void renderMap3();
void moveCharacter3();
bool IsPassable3(int nMapX, int nMapY);
bool checkblock3(int charMapX, int charMapY);

// completed function
void end3();

/* end of level 3 stage 1 */

// ---------------------LEVEL 3 Stage 2------------------//

//function call
void Level3_Stage2(); // load the map

// render map
void characterlevel3_S2();
void renderMap3_Stage2();
void moveCharacter3_S2();
bool IsPassable3_S2(int nMapX, int nMapY);
bool checkblock3_S2(int charMapX, int charMapY);

// completed function
void end3_S2();

/* end of level 3 stage 2 */
#endif // _GAME_H