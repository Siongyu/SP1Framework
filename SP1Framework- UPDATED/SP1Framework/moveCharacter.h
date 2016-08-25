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
extern SGameBlock  sBlockIndex[];
extern SGameBlock2  sBlockIndex2[];
extern SGameChar  g_sChar;
extern SGameChar  g_sChar2;
extern SGameChar	g_sArrow;
extern double  g_dBounceTime;
using namespace std;
extern bool completedlevel1;
extern bool completedlevel2;

void moveCharacter1();
void MoveCharacter2();

#endif