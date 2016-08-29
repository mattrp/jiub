#include "global.h"
#include "out_handlr.h"

void out_handlr() {
    std::cout << ":> ";
    std::deque<std::string> local_output_memory;
    while (true) {
        std::unique_lock<std::mutex> locker(output_mutex);
        output_ready.wait(locker);
        local_output_memory = shared_output_memory;
        shared_output_memory.clear();
        locker.unlock();

        if (running == 1) {
            if (!local_output_memory.empty()) {
                for (; !local_output_memory.empty(); 
                        local_output_memory.pop_front()) {
                    std::cout << local_output_memory.front() << "\n";
                }
                std::cout << ":> " << std::flush;
            }
        } else {
            std::cout << "GOODBYE\n" << std::flush;
            return;
        }
    }
}

