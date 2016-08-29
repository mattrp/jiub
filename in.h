#ifndef IN_H
#define IN_H

#include <deque>
#include <string>

void handleCommand(std::string command, std::deque<std::string>& output) {
    std::string commandFirstChars = command.substr(0,2);
    if (commandFirstChars == "-a") {
        output.push_back("BlahBlah");
    } else {
        output.push_back(command);
    }
}


void processInput(std::deque<std::string>& input, std::deque<std::string>& output) {
    while (input.size() > 0) {
        handleCommand(input[0], output);
        input.pop_back();
    }
}


#endif
