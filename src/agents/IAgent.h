//
// Created by Chang on 2026/1/20.
//

#ifndef IAGENT_H
#define IAGENT_H
#include "../core/Resolver.h"
#include <string>
class IAgent {
public:
    virtual ~IAgent() = default;

    virtual std::string name() const = 0;

    virtual bool chooseAction(const GameState& st, PlayerId p, Action& out) = 0;
};
#endif //IAGENT_H
