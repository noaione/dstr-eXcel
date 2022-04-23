#include <iostream>
#include <vector>

#include "menu.hpp"

Menu* Menu::create(const std::string& title) {
    return new Menu(title);
}

Menu::Menu(const std::string& title) {
    this->display << title;
    this->options = 0;
}

Menu* Menu::option(MenuOption* option){
    this->selections.push_back(option);
    return this;
}

Menu* Menu::option(const std::string& option, const std::function<void()>& on_select) {
    int opt = ++this->options;
    this->display << std::endl;
    this->display << opt << ". ";
    this->display << option;
    return this->option(new MenuOption{opt, option, on_select});
}

Menu* Menu::option(const std::string& option) {
    return this->option(option, [](){});
}

int Menu::wait(std::istream &in, std::ostream &out) {
    out << this->display.str();
    out << std::endl;

    if (this->options == 0) {
        return 0;
    }

    int choice;
    int attempts = 0;
    do {
        if (attempts > 0) {
            out << "Invalid choice entered.";
            out << std::endl;
        }

        if (this->options == 1) {
            out << "Enter choice [1]: ";
        } else {
            out << "Enter choice [1-" << this->options << "]: ";
        }

        in >> choice;
        attempts++;
    } while (choice <= 0 || choice > this->options);

    this->selections[choice - 1]->callback();
    return choice;
}

int Menu::wait() {
    return this->wait(std::cin, std::cout);
}

void Menu::waitUntil(const std::string& option) {
    int index = -1;
    for (MenuOption* opt : this->selections) {
        if (opt->name == option) {
            index = opt->index;
            break;
        }
    }
    if (index == -1) {
        throw std::invalid_argument("Invalid option");
    }
    while (this->wait() != index);
}
