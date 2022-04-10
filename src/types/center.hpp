#ifndef EXCEL_TYPES_CENTER_HPP
#define EXCEL_TYPES_CENTER_HPP

#include <string>

class Center {
private:
    int id;
    std::string name;
public:
    Center();
    Center(std::string name);
    Center(int id, std::string name);

    int getId();
    std::string getName();
    void setId(int id);
    void setName(std::string name);

    // XXX: Should we really have this?
    void print();
    static Center importData(std::string line);
    std::string exportData();
};

#endif /* EXCEL_TYPES_CENTER_HPP */