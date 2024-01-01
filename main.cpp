#include <iostream>
#include "ConsoleMenu.hpp"

int main()
{
    MainMenu main("main", "Main Menu");

    Menu openGlSub ("opengl", "OpenGL Menu");
    Menu vulkanSub ("vulkan", "Vulkan Menu");

    main.AddAction({"qt", "QT", []() { std::cout << "QT" << std::endl; }});
    main.AddAction({"imgui", "IMGUI", []() { std::cout << "IMGUI" << std::endl; }});
    main.AddAction({"gltk", "GLTK", []() { std::cout << "GLTK" << std::endl; }});
    main.AddAction({"wxwidgets", "WXWIDGETS", []() { std::cout << "WXWIDGETS" << std::endl; }});
    main.AddAction({"slint", "SLINT", []() { std::cout << "SLINT" << std::endl; }});

    main.AddMenu(openGlSub);
    main.AddMenu(vulkanSub);

    main.Init();

    return 0;
}
