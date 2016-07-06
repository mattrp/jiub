#include <iostream>
#include <string>
#include <thread>
#include <deque>
#include <mutex>
#include <chrono>
#include "out.h"
#include "in.h"

std::mutex mu;
std::deque<std::string> input;
int running;

void inChannel() {
    std::string thisInput = "initialize";
    while (thisInput != "q") {
        getline(std::cin, thisInput);
        mu.lock();
        input.push_back(thisInput);
        mu.unlock();
    }
    running = 0;
}


void outChannel() {
    running = 1;
    std::cout << ":> ";
    std::deque<std::string> inputcontainer;
    std::deque<std::string> outputcontainer;
    while (running == 1) {
        if (input.size() > 0) {
            mu.lock();
            inputcontainer = input;
            input.clear();
            mu.unlock();
        }
        processInput(inputcontainer, outputcontainer);
        out(outputcontainer);
    }
}

int main() {
    std::thread t1(inChannel);
    std::thread t2(outChannel);
    t1.join();
    t2.join();
}

