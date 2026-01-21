//
// Created by Chang on 2026/1/13.
//

#ifndef TYPES_H
#define TYPES_H

enum PlayerId {
    P0 = 0,
    P1 = 1
};

inline PlayerId opponent(PlayerId p) {
    return (p == P0) ? P1 : P0;
}

//In the Game
enum Phase {
    PlaceTokens,
    Reveal,
    SelectCard,
    Resolve,
    GameOver
};


enum ActionType {
    PlacePlus,        // +1
    PlaceMinus,       // -1
    RevealOppSlot,    // see your opp's slot
    SelectMySlot      // select your slot to compare it with your opp
};


struct Action {
    ActionType type;
    int slot;   // 0 ~ 8，but A-I in the game. It is the slot but not number to compare
};


struct PendingPlacement {
    bool hasPlus;
    bool hasMinus;
    int plusSlot;
    int minusSlot;

    void reset() {
        hasPlus = false;
        hasMinus = false;
        plusSlot = -1;
        minusSlot = -1;
    }

    bool done() {
        return hasPlus && hasMinus;
    }
};


struct RoundResult {
    int round;          // 0/8
    int slotP0;
    int slotP1;
    int valueP0;        // final number to compare
    int valueP1;
    int winner;         // -1: draw. 0: P0 wins, 1: P1 wins
};


struct Outcome {
    bool terminal;      // if the game terminates
    int winner;         // -1 draw，0=P0，1=P1
};

#endif //TYPES_H
