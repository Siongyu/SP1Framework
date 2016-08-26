#ifndef _highscore_h
#define _highscore_h
#include <iostream>
#include "Framework\console.h"
#include <fstream>
#include <string>
#include "renderHighscore.h"

using namespace std;

#define TIME_ROW 1
#define STEP_ROW 1

void highScore(string playtime, string playstep);

extern int playersteps;

#endif