#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include "textfile.h"

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
    S_GAME,
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

void init        ( void );      // initialize your variables, allocate memory, etc
void getInput    ( void );      // get input from player
void update      ( double dt ); // update the game and the state of the game
void render      ( void );      // renders the current state of the game to the console
void shutdown    ( void );      // do clean up, free memory

void splashScreenWait();    // waits for time to pass in splash screen
void gameplay();            // gameplay logic
void menu();				// menu logic
void moveCharacter();       // moves the character, collision detection, physics, etc, done - yan wen
void processUserInput();	// 
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void renderMenu();			// renders the menu
void renderStory();			
void renderGame();         // renders the game stuff
void renderMap(); 
void renderScore();// renders the map to the buffer first
void Level1();			   // -siong yu
bool IsPassable(int nMapX, int nMapY); //-siong yu
bool checkblock(int charMapX, int charMapY); // -siongyu
void renderCharacter();     // renders the character into the buffer
void characterlevel1();
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderplayerandgametime();
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game
void end();
#endif // _GAME_H