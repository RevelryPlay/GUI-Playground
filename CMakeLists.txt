cmake_minimum_required(VERSION 3.27)

# Project Options
project(GUI_Playground
        DESCRIPTION "Testing various GUI tools for future inclusion in Argo"
        VERSION 0.0.1
        LANGUAGES CXX C
)

SET(OPTS_USE_OPENGL ON)
SET(OPTS_USE_SLINT ON)

# End options

set(CMAKE_CXX_STANDARD 23)

add_executable(GUI_Playground
        main.cpp
        ConsoleMenu.cpp
        ConsoleMenu.hpp
)

if (OPTS_USE_OPENGL)
    target_compile_definitions(${PROJECT_NAME} PRIVATE OPTS_USE_OPENGL)

    TARGET_SOURCES(
            ${PROJECT_NAME} PRIVATE
            opengl/imguiRenderer.cpp
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
endif ()

if (OPTS_USE_SLINT)
    target_compile_definitions(${PROJECT_NAME} PRIVATE OPTS_USE_SLINT)

    TARGET_SOURCES(
            ${PROJECT_NAME} PRIVATE
            slint/SlintRenderer.cpp slint/SlintRenderer.hpp
    )

    include(FetchContent)
    FetchContent_Declare(
            Slint
            GIT_REPOSITORY https://github.com/slint-ui/slint.git
            # `release/1` will auto-upgrade to the latest Slint >= 1.0.0 and < 2.0.0
            # `release/1.0` will auto-upgrade to the latest Slint >= 1.0.0 and < 1.1.0
            GIT_TAG release/1
            SOURCE_SUBDIR api/cpp
    )
    FetchContent_MakeAvailable(Slint)

    target_link_libraries(${PROJECT_NAME} PRIVATE Slint::Slint)
    slint_target_sources(${PROJECT_NAME} slint/MainWindow.slint)
    # On Windows, copy the Slint DLL next to the application binary so that it's found.
    if (WIN32)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:gui-playground> $<TARGET_FILE_DIR:gui-playground> COMMAND_EXPAND_LISTS)
    endif()
endif ()
