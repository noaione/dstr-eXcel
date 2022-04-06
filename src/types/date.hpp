#ifndef EXCEL_TYPES_DATE_HPP
#define EXCEL_TYPES_DATE_HPP

typedef struct Date {
    int day;
    int month;
    int year;

public:
    static Date now();
} Date;

#endif /* EXCEL_TYPES_DATE_HPP */
