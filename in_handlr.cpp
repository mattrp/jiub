#include "global.h"
#include "in_handlr.h"

void in_handlr() {
    std::string tempInput = "initialize";
    while (running == 1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        getline(std::cin, tempInput);
        input_mutex.lock();
        shared_input_memory.push_back(tempInput);
        input_mutex.unlock();
        if (tempInput == "q") break;
    }
}

