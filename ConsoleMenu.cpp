#include <iostream>
#include <map>

#include "ConsoleMenu.hpp"

#include <ranges>

void Menu::Init(const std::string& menu_path)
{
    const std::string full_path = menu_path + this->Name;
    std::string input;

    while (true)
    {
        std::cout << full_path + "> ";
        std::cin >> input;
        if (this->actions.contains(input))
            actions[input].Action();
        else if (this->submenus.contains(input))
            submenus[input].Init(full_path + "/");
        else if (input == "back") return;
        else if (input == "exit") exit(0);
        else if (input == "info")
        {
            std::string name;
            std::cin >> name;

            if (this->submenus.contains(name))
                std::cout << this->submenus[name].Description << std::endl;
            else if (this->actions.contains(name))
                std::cout << this->actions[name].Description << std::endl;
            else
                std::cout << "unrecognized name: " << name << std::endl;
        }
        else if (input == "ls")
        {
            std::cout << "submenus: ";
            for (const auto& name : this->submenus | std::views::keys)
                std::cout << name << " ";
            std::cout << std::endl;

            std::cout << " actions: ";
            for (const auto& name : this->actions | std::views::keys)
                std::cout << name << " ";
            std::cout << std::endl;
        }
        else
            std::cout << "unrecognized name: " << input << std::endl;
    }
}
