#ifndef _restart_h
#define _restart_h
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "highscore.h"

extern double  g_dElapsedTime;
extern double  g_dDeltaTime;
extern double  GameTime;
extern double  g_dBounceTime;
extern bool    g_abKeyPressed[K_COUNT];

extern SGameBlock sBlockIndex[];
extern SGameBlock sEndZoneIndex[];
extern SGameChar  g_sChar;
extern bool completedlevel1;
extern SGameBlock2 sBlockIndex2[];
extern SGameBlock2 sEndZoneIndex2[];
extern SGameChar  g_sChar2;
extern bool completedlevel2;

void Restart();

using namespace std;

#endif