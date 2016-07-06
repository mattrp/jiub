#include "out.h"

void out(std::deque<std::string>& input) {
    while (input.size() > 0) {
        std::cout << ":< " << input.front() << std::endl;
        input.pop_back();
        if (input.size() == 0) {
            std::cout << ":> " << std::flush;
        }
    }
}
