#include "SlintRenderer.hpp"

void SlintRenderer::RenderSlintDemo()
{
    // std::cout << "Slint Demo Will Go Here" << std::endl;
    auto main_window = MainWindow::create();
    main_window->set_my_label("A new main window label");
    main_window->run();
}
