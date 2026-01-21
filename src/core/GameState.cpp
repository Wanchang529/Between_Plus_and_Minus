//
// Created by Chang on 2026/1/14.
//
#include "GameState.h"
#include <algorithm>
#include <random>
GameState::GameState() {
    reset();
}
void GameState::reset() {
    round=1;
    phase=Phase::PlaceTokens;
    static std::mt19937 rng(123456);
    for (int i=0; i<2; i++) {
        pending[i].reset();
        selectedSlot[i]=-1;
        score[i]=0;
        wincardsum[i]=0;
        readytoSelect[i]=0;

        std::vector<int> v;
        for (int c = 1; c <=9; ++c) v.push_back(c);
        std::shuffle(v.begin(), v.end(), rng);

        for (int j=0; j<9; j++) {
            cards[i][j] = v[j];
            used[i][j]=0;
            revealed[i][j]=0;
            tokenSum[i][j]=0;
            tokenHistory[i][j].clear();
        }
    }
}
const char* phaseToString(Phase p){
    switch (p) {
        case PlaceTokens: return "PlaceTokens";
        case Reveal:      return "Reveal";
        case SelectCard:  return "SelectCard";
        case Resolve:     return "Resolve";
        case GameOver:    return "GameOver";
        default:          return "UnknownPhase";
    }
}