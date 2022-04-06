#include <chrono>
#include <ctime>
#include "date.hpp"

Date Date::now() {
    Date date;
    std::chrono::time_point<std::chrono::system_clock> current = std::chrono::system_clock::now();
    std::time_t t_c = std::chrono::system_clock::to_time_t(current);
    std::tm* now = std::localtime(&t_c);
    date.day = now->tm_mday;
    date.month = now->tm_mon + 1;
    date.year = now->tm_year + 1900;
    return date;
}
