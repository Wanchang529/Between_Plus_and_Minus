//
// Created by Chang on 2026/1/20.
//

#ifndef RUNGAME_H
#define RUNGAME_H
struct GameResult {
    int winner;
    int score0;
    int score1;
};
GameResult runGame(IAgent& a0, IAgent& a1);
static IAgent& agentFor(PlayerId p, IAgent& a0, IAgent& a1);
#endif //RUNGAME_H
