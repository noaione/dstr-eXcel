#ifndef EXCEL_UTILS_MENU_HPP
#define EXCEL_UTILS_MENU_HPP

#include <functional>
#include <iostream>
#include <sstream>
#include <vector>

typedef struct MenuOption {
    int index;
    std::string name;
    std::function<void()> callback;
} MenuOption;

class Menu
{
private:
    std::stringstream display;
    int options;
    std::vector<MenuOption*> selections;

    explicit Menu(const std::string&);
    Menu* option(MenuOption* option);

public:
    static Menu* create(const std::string&);
    Menu* option(const std::string&);
    Menu* option(const std::string&, const std::function<void()>& on_select);

    int wait();
    int wait(std::istream&, std::ostream&);
    void waitUntil(const std::string& option);
};

#endif /* EXCEL_UTILS_MENU_HPP */