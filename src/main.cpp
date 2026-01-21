#include <iostream>
#include "core/Resolver.h"
#include "core/cli/Clihelpers.h"
#include "core/cli/CliArgs.h"
#include "sim/modes.h"

int main(int argc, char* argv[]) {
    Config cfg = parseArgs(argc, argv);

    if (cfg.mode == "human-human") {
        humanHuman();
    } else if (cfg.mode == "random-random") {
        unsigned int seed = cfg.seed ? cfg.seed : 123;
        randomRandom(cfg.games, seed);
    } else {
        std::cerr << "Unknown mode\n";
        return 1;
    }
    return 0;
}
