//
// Created by Chang on 2026/1/14.
//
#include "Rules.h"
bool isTerminal(const GameState &st) {
    return st.phase == GameOver;
}
int winner(const GameState& st) {
    if (st.score[0] > st.score[1]) {
        return 0;
    }
    else if (st.score[1]>st.score[0]) {
        return 1;
    }
    else if (st.wincardsum[0] < st.wincardsum[1]) {
        return 2;
    }
    else if (st.wincardsum[1] < st.wincardsum[0]) {
        return 3;
    }
    else {
        return 4;
    }

}

std::vector<Action> legalActions(const GameState &st, PlayerId p) {
    std::vector<Action> acts;
    if (isTerminal(st)) return acts;
    if (st.phase==Phase::PlaceTokens) {
        if (!st.pending[p].hasPlus) {
            for (int i=0; i<9; i++) {
                if (!st.used[p][i]) {
                    acts.push_back(makePlacePlus(i));
                }
            }
        }
        else if (!st.pending[p].hasMinus) {
            for (int i=0; i<9; i++) {
                if (!st.used[p][i]) {
                    if (st.cards[p][i]+st.tokenSum[p][i]>=1 || st.pending[p].plusSlot==i) {
                        acts.push_back(makePlaceMinus(i));
                    }
                }
            }
        }
    }
    else if (st.phase==Phase::Reveal) {
        PlayerId o=opponent(p);
        for (int i=0; i<9; ++i) {
            if (!st.revealed[o][i]) {
                acts.push_back(makeRevealOppSlot(i));
            }
        }
    }

    else if (st.phase==Phase::SelectCard){
        for (int i=0; i<9; ++i) {
            if (!st.used[p][i]) {
                acts.push_back(makeSelectMySlot(i));
            }
        }
    }
    return acts;
}

bool isLegal(const GameState &st, PlayerId p, const Action &a) {
    std::vector<Action> acts=legalActions(st, p);
    for (int i = 0; i < acts.size(); ++i) {
        if (acts[i].type == a.type && acts[i].slot == a.slot) {
            return true;
        }
    }
    return false;
}

