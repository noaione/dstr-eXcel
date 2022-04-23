#include <cstdlib>
#include <iostream>
#include <string>

#include "subject.hpp"
#include "../utils/utils.hpp"

// Top implement
Subject::Subject() {
    this->id = randomId();
    this->name = "N/A";
    this->payRate = 0;
}

Subject::Subject(std::string name, int payRate) {
    this->id = randomId();
    this->name = name;
    this->payRate = payRate;
}

Subject::Subject(int id, std::string name, int payRate) {
    this->id = id;
    this->name = name;
    this->payRate = payRate;
}

// Getter/Setter
int Subject::getId() {
    return this->id;
}

std::string Subject::getName() {
    return this->name;
}

int Subject::getPayRate() {
    return this->payRate;
}

void Subject::setId(int id) {
    this->id = id;
}

void Subject::setName(std::string name) {
    this->name = name;
}

void Subject::setPayRate(int payRate) {
    this->payRate = payRate;
}

// Misc
void Subject::print() {
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Pay Rate: RM" << this->payRate << std::endl;
}

Subject Subject::importData(std::string line) {
    std::string delim = "\t";

    try {
        size_t pos = 0;
        pos = line.find(delim);
        int idToken = std::stoi(line.substr(0, pos));
        line.erase(0, pos + delim.length());
        pos = line.find(delim);
        std::string nameToken = line.substr(0, pos);
        line.erase(0, pos + delim.length());
        pos = line.find(delim);
        int payRateToken = std::stoi(line.substr(0, pos));
        return Subject(idToken, nameToken, payRateToken);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
