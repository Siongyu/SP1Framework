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
extern SGameBlock3 sBlockIndex3[];
extern SGameBlock3_Stage2 sBlockIndex3_S2[];
extern SGameChar  g_sChar;
extern SGameChar  g_sChar2;
extern SGameChar g_sChar3;
extern SGameChar g_sChar3_Stage2;
extern SGameChar	g_sArrow;
extern double  g_dBounceTime;
using namespace std;
extern bool completedlevel1;
extern bool completedlevel2;
extern bool completedlevel3;
extern bool completedlevel3_S2;

void moveCharacter1();
void moveCharacter2();
void moveCharacter3();
void moveCharacter3_S2();

#endif