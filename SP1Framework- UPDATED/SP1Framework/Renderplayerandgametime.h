#ifndef _Renderplayerandgametime_h
#define _Renderplayerandgametime_h
#include "game.h"
#include "moveCharacter.h"
#include "Framework\console.h"
#include "Framework\timer.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "highscore.h"
#include "moveCharacter.h"
#include "Timecheck.h"

extern double  g_dElapsedTime;
extern double  g_dDeltaTime;
extern double  GameTime;
extern bool    g_abKeyPressed[K_COUNT];
extern bool	paused;
extern SGameBlock  sBlockIndex[];
extern SGameBlock sEndZoneIndex[];
extern SGameChar  g_sChar;
extern SGameChar  g_sArrow;
extern double  g_dBounceTime;
void Renderplayerandgametime();

#endif