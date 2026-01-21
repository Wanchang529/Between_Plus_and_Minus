//
// Created by Chang on 2026/1/14.
//

#ifndef RESOLVER_H
#define RESOLVER_H
#include "Rules.h"
void applyAction(GameState& st, PlayerId p, const Action& a);
std::vector<int> resolveRound(GameState& st);
void commitPlacementsIfReady(GameState& st);
void advanceIfReady(GameState& st);
bool skipReveal(const GameState& st, PlayerId p);
void markRevealDone(GameState& st, PlayerId p);

#endif //RESOLVER_H
