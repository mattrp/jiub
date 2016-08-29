#include "in.h"


void processInput(std::deque<std::string>& input, std::deque<std::string>& output) {
    while (input.size() > 0) {
        handleCommand(input[0], output)
        input.pop_back();
    }
}


void handleCommand(string command, std::deque<std::string>& output) {
    output.push_back(command);
}

