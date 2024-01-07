#include <iostream>
#include "ConsoleMenu.hpp"

#ifdef OPTS_USE_OPENGL
#include "opengl/imguiRenderer.cpp"
#endif

#ifdef OPTS_USE_SLINT
#include "slint/SlintRenderer.hpp"
#endif

int main()
{
    std::cout << "To see a list of available commands type `help`" << '\n';
    std::cout << '\n';

    MainMenu main("main", "Main Menu");
    //
    // Menu vulkanSub("vulkan", "Vulkan Menu");
    // main.AddMenu(vulkanSub);

    // main.AddAction({"qt", "QT", []() { std::cout << "QT" << std::endl; }});
    // main.AddAction({"gltk", "GLTK", []() { std::cout << "GLTK" << std::endl; }});
    // main.AddAction({"wxwidgets", "WXWIDGETS", []() { std::cout << "WXWIDGETS" << std::endl; }});

#ifdef OPTS_USE_OPENGL
    // Menu openGlSub("opengl", "OpenGL Menu");
    main.AddAction({
        "imgui", "Render the IMGUI demo window", []()
        {
            ImguiRenderer::renderOpenGL();
        }
    });

    // main.AddMenu(openGlSub);
#endif

#ifdef OPTS_USE_SLINT
    main.AddAction({
        "slint", "Render the Slint demo window", []()
        {
            SlintRenderer::RenderSlintDemo();
        }
    });

#endif

    main.Init();

    return 0;
}
