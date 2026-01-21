//
// Created by Chang on 2026/1/14.
//

#ifndef RULES_H
#define RULES_H
#include "Actions.h"
#include <vector>
bool isTerminal(const GameState& st);
int winner(const GameState& st);
bool isLegal(const GameState& st, PlayerId p, const Action& a);
std::vector<Action> legalActions(const GameState& st, PlayerId p);

#endif //RULES_H
