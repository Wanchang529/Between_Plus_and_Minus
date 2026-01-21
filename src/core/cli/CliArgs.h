//
// Created by Chang on 2026/1/20.
//

#ifndef CLIARGS_H
#define CLIARGS_H
#include <string>
struct Config {
    std::string mode="human-human";
    int games=1000;
    unsigned int seed = 0;
};

Config parseArgs(int argc, char* argv[]);
#endif //CLIARGS_H
