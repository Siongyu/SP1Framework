#ifndef _drawmap_h
#define _drawmap_h

#include <iostream>
#include "Framework\console.h"
#include "game.h"
#include <fstream>
#include <string>

using namespace std;

struct TILE_TYPE
{
	char    nCharacter; // ASCII character for this tile type
	short   nColorCode; // Color code for this tile type
	bool	bPassable;
};
// Global array used to define all tile types used in the game
TILE_TYPE  sTileIndex[] = {
	{ '.', 10, true },     // (0) TILE_FLOOR
	{ '#', 5, false },     // (1) TILE_WALL
	{ '1', 4, true },     // (2) TILE_BLOCK
	{ 'O', 4, true },     // (3) TILE_PLACEMENT 

};


#endif // _drawmap_h