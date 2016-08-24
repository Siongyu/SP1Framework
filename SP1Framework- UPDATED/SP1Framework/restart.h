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

extern SGameBlock  sBlockIndex[];
extern SGameBlock sEndZoneIndex[];
extern SGameChar  g_sChar;;

void Restart();

using namespace std;

#endif