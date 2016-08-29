#ifndef GLOBAL_H
#define GLOBAL_H


#ifdef MAIN_H
  #define EXTERN
#else
  #define EXTERN extern
#endif

#include <string>
#include <deque>
#include <mutex>
#include <condition_variable>

EXTERN std::mutex input_mutex;
EXTERN std::deque<std::string> shared_input_memory;
EXTERN std::mutex output_mutex;
EXTERN std::deque<std::string> shared_output_memory;
EXTERN std::condition_variable output_ready;
EXTERN int running;

#endif
