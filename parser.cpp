#include "parser.h"
#include <sstream>

std::vector<std::string> parseInput(const std::string &input) {
    std::vector<std::string> args;
    std::istringstream iss(input);
    std::string token;

    // Extract each word separated by whitespace
    while (iss >> token) {
        args.push_back(token);
    }

    return args;
}
