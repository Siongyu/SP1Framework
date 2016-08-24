#ifndef _moveCharacter_h
#define _movCharacter_h
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "highscore.h"

extern double  g_dElapsedTime;
extern double  g_dDeltaTime;
extern double  GameTime;
extern bool    g_abKeyPressed[K_COUNT];
//extern bool	paused = false;
extern SGameBlock  sBlockIndex[];
//{
//	{ { 19, 5 }, false },     // (0) Block 1
//	{ { 24, 7 }, false },     // (1) Block 2
//	{ { 24, 8 }, false },     // (2) Block 3
//	{ { 24, 12 }, false },     // (3) Block 4
//	{ { 22, 12 }, false },     // (4) Block 5
//	{ { 4, 12 }, false },     // (5) Block 6
//};

extern SGameChar  g_sChar;
extern SGameChar	g_sArrow;
extern double  g_dBounceTime;
using namespace std;
void MoveCharacter();

#endif