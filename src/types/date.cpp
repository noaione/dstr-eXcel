#include <chrono>
#include <ctime>
#include <string>
#ifdef DEBUG
#include <iostream>
#endif
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

std::string replaceUntilNone(std::string source, std::string target, std::string fmtr, bool prepend = false) {
    size_t index = source.find(fmtr);
    while (index != std::string::npos) {
        if (prepend && target.length() == 1) {
            target = "0" + target;
        }
#ifdef DEBUG
        std::cout << source << "||" << target << "||" << fmtr << "==>" << index << "||" << sizeof(fmtr) << std::endl;
#endif
        source = source.replace(index, fmtr.size(), target);
#ifdef DEBUG
        std::cout << "!" << source << "||" << target << "||" << fmtr << "==>" << index << std::endl;
#endif
        index = source.find(fmtr);
    }
#ifdef DEBUG
    std::cout << "!!!" << std::endl;
#endif
    return source;
}

std::string Date::fmt(std::string str) {
    std::string dateStr;
    dateStr += str;
    std::string dayFmt = std::to_string(this->day);
    std::string mnthFmt = std::to_string(this->month);
    std::string yearFmt = std::to_string(this->year);
#ifdef DEBUG
    std::cout << str << std::endl;
#endif
    dateStr = replaceUntilNone(dateStr, yearFmt, "yyyy");
    dateStr = replaceUntilNone(dateStr, dayFmt, "dd", true);
    dateStr = replaceUntilNone(dateStr, dayFmt, "d");
    dateStr = replaceUntilNone(dateStr, mnthFmt, "mm", true);
    dateStr = replaceUntilNone(dateStr, mnthFmt, "m");
#ifdef DEBUG
    std::cout << std::endl;
#endif
    return dateStr;
}

std::string Date::toString() {
    return this->fmt("yyyy/mm/dd");
}
