#pragma once
#ifndef _MOVEMENUARROW_h
#define _MOVEMENUARROW_h

#include "game.h"

extern bool    g_abKeyPressed[K_COUNT];
extern SGameChar	g_sArrow;
extern EGAMESTATES g_eGameState;
extern double  g_dBounceTime;
extern double  g_dElapsedTime;

void Movemenuarrow();

#endif