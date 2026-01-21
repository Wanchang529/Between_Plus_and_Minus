//
// Created by Chang on 2026/1/20.
//
#include "RandomAgent.h"
#include <random>
#include <vector>

RandomAgent::RandomAgent(unsigned int seed) {
    if (seed == 0) {
        std::random_device rd;
        rng_ = std::mt19937(rd());
    } else {
        rng_ = std::mt19937(seed);
    }
}

int RandomAgent::uniformIndex(int n) {
    std::uniform_int_distribution<int> dist(0, n - 1);
    return dist(rng_);
}


bool RandomAgent::chooseAction(const GameState& st, PlayerId p, Action& out) {
    auto acts = legalActions(st, p);
    if (acts.empty()) return false;
    out = acts[uniformIndex((int)acts.size())];
    return true;
}

