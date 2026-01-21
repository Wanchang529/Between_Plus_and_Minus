//
// Created by Chang on 2026/1/16.
//

#ifndef CLIHELPERS_H
#define CLIHELPERS_H
#include "../Resolver.h"
#include <iostream>
int slotCharToIndex(char c);
char slotIndexToChar(int idx);
int readSlotAI(const char* prompt);
void printStatus(const GameState& st);
void p0status(const GameState& st);
void p1status(const GameState& st);
void confirmPlayer0();
void confirmPlayer1();
void publicP0(const GameState& st);
void publicP1(const GameState& st);
void doActionUntilLegal(GameState& st, PlayerId p, ActionType type, const char* prompt);
void handlePlaceToken(GameState& st);
void handleReveal(GameState& st);
void handleSelect(GameState& st);
void handleResolve(GameState& st);
void handleGameOver(const GameState& st);

#endif //CLIHELPERS_H
