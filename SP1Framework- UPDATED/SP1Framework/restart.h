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
extern SGameBlock3 sBlockIndex3[];
extern SGameBlock3 sEndZoneIndex3[];
extern SGameChar  g_sChar3;
extern bool completedlevel3;
extern SGameBlock3_Stage2 sBlockIndex3_S2[];
extern SGameBlock3_Stage2 sEndZoneIndex3_S2[];
extern SGameChar  g_sChar3_Stage2;
extern bool completedlevel3_S2;

void Restart();

using namespace std;

#endif