#include <chrono>
#include <ctime>
#include <string>
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

std::string Date::fmt(std::string str) {
    std::string dateStr;
    dateStr += str;
    std::string dayFmt = std::to_string(this->day);
    std::string mnthFmt = std::to_string(this->month);
    if (dayFmt.length() == 1 && str.find("mm") != std::string::npos) {
        dayFmt = "0" + dayFmt;
    }
    if (mnthFmt.length() == 1 && str.find("mm") != std::string::npos) {
        mnthFmt = "0" + mnthFmt;
    }
    if (str.find("yyyy") != std::string::npos) {
        dateStr.replace(dateStr.find("yyyy"), sizeof("yyyy") - 1, std::to_string(year));
    }
    if (str.find("dd") != std::string::npos) {
        dateStr.replace(dateStr.find("dd"), sizeof("dd") - 1, dayFmt);
    } else if (str.find("d") != std::string::npos) {
        dateStr.replace(dateStr.find("d"), sizeof("d") - 1, dayFmt);
    }
    if (str.find("mm") != std::string::npos) {
        dateStr.replace(dateStr.find("mm"), sizeof("mm") - 1, mnthFmt);
    } else if (str.find("m") != std::string::npos) {
        dateStr.replace(dateStr.find("m"), sizeof("m") - 1, mnthFmt);
    }
    return dateStr;
}

std::string Date::toString() {
    return this->fmt("yyyy/mm/dd");
}
