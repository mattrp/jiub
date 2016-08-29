#include "main.h"
#include "global.h"
#include "in_handlr.h"
#include "out_handlr.h"


void process_input() {
    std::string prefix("--foo=");
    for (std::string s : local_input_memory) { 
        if (s == "q") {
            running = 0;
            break;
        } else if (!s.compare(0, prefix.size(), prefix)) {
            int foo_value = atoi(s.substr(prefix.size()).c_str());
            local_output_memory.push_back("Foo: " + std::to_string(foo_value));
        } else {
            local_output_memory.push_back("Unknown Command: " + s);
        }
    }
}

void main_thread() {
    while (running == 1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        input_mutex.lock();
        local_input_memory = shared_input_memory;
        shared_input_memory.clear();
        input_mutex.unlock();

        process_input();

        std::unique_lock<std::mutex> locker(output_mutex);
        shared_output_memory = local_output_memory;
        locker.unlock();
        output_ready.notify_all();
        local_output_memory.clear();
    }
}

int main() {
    running = 1;

    std::thread t1(out_handlr);
    std::thread t2(in_handlr);

    main_thread();

    t2.join();
    t1.join();
}
