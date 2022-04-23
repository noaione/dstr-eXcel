#include <cstdlib>
#include <iostream>
#include <string>

#include "center.hpp"
#include "../utils/utils.hpp"

// Top implement
Center::Center() {
    this->id = randomId();
    this->name = "N/A";
}

Center::Center(std::string name) {
    this->id = randomId();
    this->name = name;
}

Center::Center(int id, std::string name) {
    this->id = id;
    this->name = name;
}

// Getter/Setter
int Center::getId() {
    return this->id;
}

std::string Center::getName() {
    return this->name;
}

void Center::setId(int id) {
    this->id = id;
}

void Center::setName(std::string name) {
    this->name = name;
}

// Misc
void Center::print() {
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Name: " << this->name << std::endl;
}

Center Center::importData(std::string line) {
    std::string delim = "\t";

    try {
        size_t pos = 0;
        pos = line.find(delim);
        int idToken = std::stoi(line.substr(0, pos));
        line.erase(0, pos + delim.length());
        pos = line.find(delim);
        std::string nameToken = line.substr(0, pos);
        return Center(idToken, nameToken);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

std::string Center::exportData() {
    std::string idToken = std::to_string(this->id);
    return idToken + "\t" + this->name;
}
