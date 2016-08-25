#ifndef _level1_h
#define _level1_h

#include <iostream>
#include "Framework\console.h"
#include "game.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include "highscore.h"

const int MAP1_WIDTH = 48;
const int MAP1_HEIGHT = 16;

int nMap1Array[MAP1_HEIGHT][MAP1_WIDTH];
extern double  GameTime;
extern SGameChar  g_sChar;
extern EGAMESTATES g_eGameState;

using namespace std;

#endif