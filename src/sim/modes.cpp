//
// Created by Chang on 2026/1/20.
//
#include "../agents/RandomAgent.h"
#include "RunGame.h"
#include "../core/Resolver.h"
#include "../core/cli/Clihelpers.h"
#include <iostream>
void randomRandom(int games, unsigned int seed) {
    int w0=0, w1=0, tie=0;
    for (int i=0; i<games; ++i) {
        RandomAgent a0(seed+i*2);
        RandomAgent a1(seed+i*2+1);
        GameResult r = runGame(a0, a1);
        if (r.winner == 0) ++w0;
        else if (r.winner == 1) ++w1;
        else if (r.winner==2) ++tie;
    }
    std::cout<< "Seed: "<<seed<<std::endl;
    std::cout << "Random vs Random (" << games << " games)\n";
    std::cout << "P0 wins: " << w0 << "\n";
    std::cout << "P1 wins: " << w1 << "\n";
    std::cout << "Ties: " << tie << "\n";
}
void humanHuman() {
    GameState st;
    std::cout<<"Human VS Human Mode\n";
    std::cout << "Between Plus and Minus Game!\nRead the Rules Carefully and We Are On this Game!!!\n";
    std::cout << "You Have 9 Slots: A B ... I\n\n";

    while (st.phase != GameOver) {
        printStatus(st);

        if (st.phase == PlaceTokens) {
            handlePlaceToken(st);
            continue;
        }
        if (st.phase == Reveal) {
            handleReveal(st);
            continue;
        }

        if (st.phase == SelectCard) {
            handleSelect(st);
            continue;
        }
        if (st.phase == Resolve) {
            handleResolve(st);
            continue;
        }
    }
    handleGameOver(st);
}