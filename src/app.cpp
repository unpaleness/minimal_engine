#include "app.h"

#include <GLFW/glfw3.h>

#include "render.h"

namespace
{
    constexpr uint32_t WIDTH = 800;
    constexpr uint32_t HEIGHT = 600;
} // namespace

void App::Run()
{
    InitWindow();

    render = new Render(window);

    MainLoop();
    Cleanup();
}

void App::InitWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, PROJECT_NAME, nullptr, nullptr);
}

void App::MainLoop()
{
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
}

void App::Cleanup()
{
    delete render;
    render = nullptr;

    glfwDestroyWindow(window);
    glfwTerminate();
}
