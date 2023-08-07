#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string.h>

template<typename... Args>
inline void DEBUG(const std::string& msg = "" , Args... args){
    std::string m = "DEBUG: " + msg + "\n";
    printf(m.c_str(), args...);
    exit(1);
}

template<typename... Args>
inline void LOG(const std::string& msg , Args... args){
    std::string m = "LOG: " + msg + "\n";
    printf(m.c_str(), args...);
}

#endif