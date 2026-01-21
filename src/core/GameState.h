//
// Created by Chang on 2026/1/13.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Types.h"
#include <vector>

struct GameState {
    int round;
    Phase phase;
    int cards[2][9];
    int tokenSum[2][9];
    bool used[2][9];
    bool revealed[2][9];
    int wincardsum[2];
    bool readytoSelect[2];
    PendingPlacement pending[2];
    std::vector<int> tokenHistory[2][9];
    int selectedSlot[2];
    int score[2];
    GameState();
    void reset();
};
const char* phaseToString(Phase p);
#endif //GAMESTATE_H
