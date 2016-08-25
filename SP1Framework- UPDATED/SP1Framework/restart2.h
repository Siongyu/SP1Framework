#ifndef _restart2_h
#define _restart2_h
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

extern SGameBlock2 sBlockIndex2[];
extern SGameBlock2 sEndZoneIndex2[];
extern SGameChar  g_sChar2;

void Restart2();

using namespace std;

#endif