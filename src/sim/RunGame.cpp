//
// Created by Chang on 2026/1/20.
//
#include "../agents/IAgent.h"
#include "../core/Resolver.h"   // applyAction, advanceIfReady, resolveRound, winner
#include <stdexcept>
#include "RunGame.h"


static IAgent& agentFor(PlayerId p, IAgent& a0, IAgent& a1) {
    return (p == P0) ? a0 : a1;
}

GameResult runGame(IAgent& a0, IAgent& a1) {
    GameState st;
    while (st.phase != GameOver) {
        if (st.phase == PlaceTokens) {
            for (PlayerId p : {P0, P0, P1, P1}) {
                Action a;
                if (!agentFor(p, a0, a1).chooseAction(st, p, a)) {
                    throw std::runtime_error("No legal action in PlaceTokens (unexpected).");
                }
                applyAction(st, p, a);
                advanceIfReady(st);
            }
            continue;
        }

        if (st.phase == Reveal) {
            for (PlayerId p : {P0, P1}) {
                Action a;
                bool ok = agentFor(p, a0, a1).chooseAction(st, p, a);
                if (ok) {
                    applyAction(st, p, a);
                }
                markRevealDone(st, p);
                advanceIfReady(st);
            }
            continue;
        }
        if (st.phase == SelectCard) {
            for (PlayerId p : {P0, P1}) {
                Action a;
                if (!agentFor(p, a0, a1).chooseAction(st, p, a)) {
                    throw std::runtime_error("No legal action in SelectCard (unexpected).");
                }
                applyAction(st, p, a);
                advanceIfReady(st);
            }
            continue;
        }

        if (st.phase == Resolve) {
            resolveRound(st);
            continue;
        }

        throw std::runtime_error("Unknown phase.");
    }

    GameResult gr;
    int w = winner(st);
    if (w == 0 || w == 2) {gr.winner = 0;}
    else if (w==1 || w==3) {gr.winner=1;}
    else {gr.winner = 2;}

    gr.score0 = st.score[0];
    gr.score1 = st.score[1];
    return gr;
}
