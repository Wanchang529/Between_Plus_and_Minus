cmake_minimum_required(VERSION 3.31)
project(Between_Plus_and_Minus)

set(CMAKE_CXX_STANDARD 17)

add_executable(between
        src/main.cpp
        src/core/GameState.cpp
        src/core/Rules.cpp
        src/core/Resolver.cpp
        src/core/cli/Clihelpers.cpp
        src/sim/modes.cpp
        src/agents/RandomAgent.cpp
        src/sim/RunGame.cpp
        src/core/cli/CliArgs.cpp
)
