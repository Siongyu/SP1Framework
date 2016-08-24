#ifndef _Pause_h
#define _Pause_h
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

extern double  g_dBounceTime;
extern bool    g_abKeyPressed[K_COUNT];
extern double  g_dElapsedTime;
extern bool	paused;

void Pause();

#endif