//
// Created by Chang on 2026/1/20.
//

#ifndef RANDOMAGENT_H
#define RANDOMAGENT_H
#include "IAgent.h"
#include <random>
class RandomAgent : public IAgent {
public:
    explicit RandomAgent(unsigned int seed = 0);

    std::string name() const override { return "RandomAgent"; }

    bool chooseAction(const GameState& st, PlayerId p, Action& out) override;

private:
    std::mt19937 rng_;

    int uniformIndex(int n);
};
#endif //RANDOMAGENT_H
