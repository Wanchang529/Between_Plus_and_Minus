//
// Created by Chang on 2026/1/20.
//
#include "CliArgs.h"
#include <iostream>
Config parseArgs(int argc, char* argv[]) {
    Config cfg;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--mode" && i + 1 < argc) cfg.mode = argv[++i];
        else if (arg == "--games" && i + 1 < argc) cfg.games = std::stoi(argv[++i]);
        else if (arg == "--seed" && i + 1 < argc) cfg.seed = (unsigned int)std::stoul(argv[++i]);
        else if (arg == "--help") {
            std::cout << "Usage:\n"
                      << "  --mode [human-human | random-random]\n"
                      << "  --games N (for random-random)\n"
                      << "  --seed N\n";
            std::exit(0);
        } else {
            std::cerr << "Unknown arg: " << arg << "\n";
            std::exit(1);
        }
    }
    return cfg;
}