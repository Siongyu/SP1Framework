#ifndef _timecheck_h
#define _timecheck_h
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "highscore.h"
extern bool	paused;
extern double  g_dElapsedTime;
extern double  g_dDeltaTime;
extern double  GameTime;
extern double  g_dBounceTime;
extern bool    g_abKeyPressed[K_COUNT];
extern SGameBlock  sBlockIndex[];
extern SGameBlock sEndZoneIndex[];
extern SGameChar  g_sChar;
extern SGameChar  g_sArrow;
using namespace std;
void timecheck();
#endif