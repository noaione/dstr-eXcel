#ifndef EXCEL_TYPES_SUBJECT_HPP
#define EXCEL_TYPES_SUBJECT_HPP

#include <string>

class Subject {
private:
    int id;
    std::string name;
    int payRate;
public:
    Subject();
    Subject(std::string name, int payRate);
    Subject(int id, std::string name, int PayRate);

    int getId();
    std::string getName();
    int getPayRate();
    void setId(int id);
    void setName(std::string name);
    void setPayRate(int payRate);

    // XXX: Should we really have this?
    void print();
    static Subject importData(std::string line);
    std::string exportData();
};

#endif /* EXCEL_TYPES_SUBJECT_HPP */