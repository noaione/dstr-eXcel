#ifndef EXCEL_FILEIO_HPP
#define EXCEL_FILEIO_HPP

#include <string>
#include <vector>

std::string getCurrentDirectory();
void saveData(std::string data, std::string path);
std::string readData(std::string path) ;
std::vector<std::string> readDataPerLine(std::string path);

#endif /* EXCEL_FILEIO_HPP */