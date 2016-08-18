#ifndef _drawmap_h
#define _drawmap_h

#include <iostream>
#include "Framework\console.h"
#include <fstream>
#include <string>

using namespace std;

#define MAP_WIDTH   80
#define MAP_HEIGHT  16
// Tile Types
#define TILE_FLOOR  0
#define TILE_WALL   1
#define TILE_CLOSEDDOOR	2
#define TILE_OPENDOOR	3
#define TILE_GRASS		4
#define TILE_TREE		5
#define TILE_FIRE       6


struct TILE_TYPE
{
	char    nCharacter; // ASCII character for this tile type
	short   nColorCode; // Color code for this tile type
	bool	bPassable;
};
// Global array used to define all tile types used in the game
TILE_TYPE  sTileIndex[] = {
	{ 'F', 1, true},     // (0) TILE_FLOOR
	{ '#', 2, false },     // (1) TILE_WALL
	{ '+', 6, false},     // (2) TILE_CLOSEDDOOR
	{ '/', 6, true },     // (3) TILE_OPENDOOR
	{ '.', 10, true },        // (4) TILE_GRASS
	{ 'T', 10, false },     // (5) TILE_TREE
	{ '*', 4, true}  // (6) TILE_FIRE
};

#endif // _drawmap_h