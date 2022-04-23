#ifndef EXCEL_TYPES_DATE_HPP
#define EXCEL_TYPES_DATE_HPP

typedef struct Date {
    int day;
    int month;
    int year;

public:
    static Date now();
    std::string fmt(std::string str);
    std::string toString();
} Date;

#endif /* EXCEL_TYPES_DATE_HPP */
