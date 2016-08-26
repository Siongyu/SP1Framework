#ifndef _level2_h
#define _level2_h

#include <iostream>
#include "Framework\console.h"
#include "game.h"
#include "highscore.h"

const int MAP2_WIDTH = 48;
const int MAP2_HEIGHT = 17;

int nMap2Array[MAP2_HEIGHT][MAP2_WIDTH];
extern double  GameTime;
extern SGameChar  g_sChar2;
extern EGAMESTATES g_eGameState;

using namespace std;

#endif