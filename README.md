# Between Plus and Minus

A turn-based two-player strategy game engine implemented in C++, focusing on game rule modeling, state management, and extensible agent design rather than graphics or UI.

This project is designed as a clean, modular simulation framework that can later support AI agents, strategy experiments, and automated match analysis.


## Overview

* Players: 2
* Game length: up to 9 rounds
* Core elements:

    * Cards numbered 1–9 (each used once)
    * +1 / −1 tokens
    * Partial information via limited reveal actions

The goal is to win rounds by strategically modifying card values using tokens and choosing cards under imperfect information.


## Game Flow (Per Round)

1. **PlaceTokens**
   Each player places one +1 token and one −1 token on their own slots, subject to legality constraints.

2. **Reveal**
   Each player may reveal one unrevealed slot of the opponent. Revealed information remains visible.

3. **SelectCard**
   Both players secretly select one unused card.

4. **Resolve**
   Final value = card value + sum of tokens on that slot.
   The higher value wins the round and scores 1 point.

## Win Condition

After 9 rounds:

1. Higher total score wins.
2. If tied, the player whose **winning cards have a smaller total face value** wins.

## About Design

* **Explicit state machine** controlling game phases
* **Action-driven architecture**: agents interact with the game only through validated actions
* **Strict rule enforcement** via centralized legality checks
* **Separation of concerns** between core game logic and agents


## Project Structure

```
between-plus-minus/
├── CMakeLists.txt
├── README.md
├── data                        # (reserved)
└── src/
    ├── main.cpp
    ├── agents/                 # Agent interface + implementations
    │   ├── IAgent.h
    │   ├── RandomAgent.h
    │   └── RandomAgent.cpp
    ├── core/                   # Core game model + rules + resolution
    │   ├── Actions.h
    │   ├── Types.h
    │   ├── GameState.h
    │   ├── GameState.cpp
    │   ├── Rules.h
    │   ├── Rules.cpp
    │   ├── Resolver.h
    │   ├── Resolver.cpp
    │   └── cli/                # CLI helpers + argument parsing
    │       ├── CliArgs.h
    │       ├── CliArgs.cpp
    │       ├── Clihelpers.h
    │       └── Clihelpers.cpp
    ├── sim/                    # Simulation runners / modes
    │   ├── modes.h
    │   ├── modes.cpp
    │   ├── RunGame.h
    │   └── RunGame.cpp
    ├── io/                     # (reserved) logging / replay / file I/O
    └── ui/                     # (reserved) future UI frontends

```

## Agents

Current agents:

* HumanAgentCLI
* RandomAgent

The design allows easy extension to heuristic or AI-based agents.

---

## Build & Run

from project root:
mkdir build
cd build
cmake ..
cmake --build .

Build output executable:

Windows: between.exe

From the build directory:

./between --mode human-human

or run automated simulations:

./between --mode random-random --games 1000 --seed 42

## Future Work Expected

1. Match logging and replay export (e.g., into a data/ directory)

2. Stronger AI agents

3. Batch simulation for strategy evaluation


## Notes

This project emphasizes **architecture and game logic modeling** rather than UI or graphics.


## Author

Wanchang Xiong

University of Florida
