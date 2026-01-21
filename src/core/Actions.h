//
// Created by Chang on 2026/1/14.
//

#ifndef ACTIONS_H
#define ACTIONS_H
#include "GameState.h"
inline Action makePlacePlus(int slot) {
    return Action{ActionType::PlacePlus, slot};
}
inline Action makePlaceMinus(int slot) {
    return Action{ActionType::PlaceMinus,slot};
}
inline Action makeRevealOppSlot(int slot) {
    return Action{ActionType::RevealOppSlot, slot};
}

inline Action makeSelectMySlot(int slot) {
    return Action{ActionType::SelectMySlot, slot};
}


#endif //ACTIONS_H
