#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

#include "fileio.hpp"

std::string getCurrentDirectory() {
    return std::filesystem::current_path().string();
}

void saveData(std::string data, std::string path) {
    std::ofstream iostream(path);
    iostream << data;
    iostream.close();
}

std::string readData(std::string path) {
    std::string target = "";
    std::ifstream iostream(path);
    std::string line;
    while (std::getline(iostream, line)) {
        target += line + "\n";
    }
    iostream.close();
    return target;
}

int countLines(std::string linedata) {
    int counted = 0;
    std::string line;
    for (int i = 0; i < linedata.length(); i++) {
        if (linedata[i] == '\n') {
            counted++;
            line = "";
        } else {
            line += linedata[i];
        }
    }
    if (line != "") {
        counted++;
    }
    return counted;
}

std::vector<std::string> readDataPerLine(std::string path) {
    std::string data = readData(path);
    int counted = countLines(data);
    std::vector<std::string> lines;
    lines.reserve((size_t)(counted + 1));
    std::string line;
    for (int i = 0; i < data.length(); i++) {
        if (data[i] == '\n') {
            lines.push_back(line);
            line = "";
        } else {
            line += data[i];
        }
    }
    if (line != "") {
        lines.push_back(line);
    }
    return lines;
}