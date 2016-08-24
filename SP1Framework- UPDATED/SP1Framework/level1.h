#ifndef _level1_h
#define _level1_h

#include <iostream>
#include "Framework\console.h"
#include "game.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

extern const int MAP1_WIDTH = 48;
extern const int MAP1_HEIGHT = 16;

int nMap1Array[MAP1_HEIGHT][MAP1_WIDTH];

using namespace std;

void Level1();
#endif