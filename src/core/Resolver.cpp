//
// Created by Chang on 2026/1/14.
//
#include "Resolver.h"
#include <iostream>

void applyAction(GameState& st, PlayerId p, const Action& a) {
    int me = (p == P0) ? 0 : 1;

    if (a.type == PlacePlus) {
        st.pending[me].hasPlus = true;
        st.pending[me].plusSlot = a.slot;
    }
    else if (a.type == PlaceMinus) {
        st.pending[me].hasMinus = true;
        st.pending[me].minusSlot = a.slot;
    }
    else if (a.type == RevealOppSlot) {
        int op = (p==P1) ? 0 : 1;
        st.revealed[op][a.slot] = true;
    }
    else if (a.type == SelectMySlot) {
        st.selectedSlot[me] = a.slot;
    }
}
bool skipReveal(const GameState& st, PlayerId p) {
    if (st.phase!=Reveal) {
        return false;
    }
    int op = (p == P0) ? 1 : 0;
    for (int i=0; i<9; ++i) {
        if (!st.used[op][i]) {
            if (!st.revealed[op][i]) {
                return false;
            }
        }
    }
    return true;
}
void commitPlacementsIfReady(GameState& st) {
    if (st.phase != PlaceTokens) return;
    if (!st.pending[0].done()) return;
    if (!st.pending[1].done()) return;

    st.tokenSum[0][st.pending[0].plusSlot]  += 1;
    st.tokenSum[0][st.pending[0].minusSlot] -= 1;
    st.tokenHistory[0][st.pending[0].plusSlot].push_back(1);
    st.tokenHistory[0][st.pending[0].minusSlot].push_back(-1);

    st.tokenSum[1][st.pending[1].plusSlot]  += 1;
    st.tokenSum[1][st.pending[1].minusSlot] -= 1;
    st.tokenHistory[1][st.pending[1].plusSlot].push_back(1);
    st.tokenHistory[1][st.pending[1].minusSlot].push_back(-1);

    st.pending[0].reset();
    st.pending[1].reset();

    st.phase = Reveal;
}
void advanceIfReady(GameState& st) {
    if (st.phase == PlaceTokens) {
        commitPlacementsIfReady(st);
        return;
    }
    if (st.phase==Reveal) {
        if (st.readytoSelect[0] && st.readytoSelect[1]) {
            st.phase=SelectCard;
            st.readytoSelect[0] = false;
            st.readytoSelect[1] = false;
        }
        return;
    }
    if (st.phase==SelectCard) {
        if (st.selectedSlot[0]!=-1 and st.selectedSlot[1]!=-1) {
            st.phase = Resolve;
            return;
        }
    }
}
std::vector<int> resolveRound(GameState& st) {
    std::vector<int> vec;
    if (st.phase != Resolve) return vec;
    st.round++;

    int s0 = st.selectedSlot[0];
    int s1 = st.selectedSlot[1];
    vec.push_back(s0);
    vec.push_back(s1);
    int v0 = st.cards[0][s0] + st.tokenSum[0][s0];
    int v1 = st.cards[1][s1] + st.tokenSum[1][s1];
    vec.push_back(v0);
    vec.push_back(v1);

    if (v0 > v1) {
        st.score[0] ++;
        st.wincardsum[0]+=st.cards[0][s0];
        vec.push_back(0);
    }
    else if (v1 > v0) {
        st.score[1] ++;
        st.wincardsum[1]+=st.cards[1][s1];
        vec.push_back(1);
    }
    else {
        vec.push_back(2);
    }
    st.used[0][s0] = true;
    st.revealed[0][s0]=true;
    st.used[1][s1] = true;
    st.revealed[1][s1]=true;

    st.selectedSlot[0] = -1;
    st.selectedSlot[1] = -1;
    if (st.round==10 || st.score[0]>=5 || st.score[1]>=5) {
        st.phase = GameOver;
    } else {
        st.phase = PlaceTokens;
    }
    return vec;
}
void markRevealDone(GameState& st, PlayerId p) {
    int me = (p==P0)?0:1;
    st.readytoSelect[me] = true;
}

