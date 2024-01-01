#ifndef CONSOLE_MENU_HPP
#define CONSOLE_MENU_HPP

#include <string>
#include <map>
#include <utility>

typedef struct {
    std::string Name;
    std::string Description;
    void (*Action)();
} MenuItem;

class Menu {
protected:
    std::map<std::string, Menu> submenus;
    std::map<std::string, MenuItem> actions;
public:
    Menu() = default;
    Menu(std::string name, std::string desc) : Name(std::move(name)), Description(std::move(desc)) {}
    std::string Name;
    std::string Description;
    void AddMenu(Menu const& m) { this->submenus[m.Name] = m; }
    void AddAction(MenuItem const& m) { this->actions[m.Name] = m; }
    void Init(const std::string&);
};

class MainMenu : public Menu {
public:
    using Menu::Menu;
    inline void Init() { this->Menu::Init(""); }
};

#endif