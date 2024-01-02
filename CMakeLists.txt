cmake_minimum_required(VERSION 3.27)
project(GUI_Playground
        DESCRIPTION "Testing various GUI tools for future inclusion in Argo"
        VERSION 0.0.1
        LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 23)

add_executable(GUI_Playground
        main.cpp
        imguiRenderer.cpp
        ConsoleMenu.cpp
        ConsoleMenu.hpp
)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

find_package(glad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)

find_package(imgui CONFIG REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${IMGUI_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)
