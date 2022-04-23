#include <iostream>
#include <random>
#include "utils.hpp"

std::random_device rd;

int randomId() {
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, 69420);
    return dist(mt);
}

void wait_for_enter_key() {
    std::cout << "[Press Enter to Continue]";
    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }
    while (std::cin.peek() != '\n');
}
