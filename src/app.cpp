#include "app.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;

void App::run()
{
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void App::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(WIDTH, HEIGHT, PROJECT_NAME, nullptr, nullptr);
}

void App::initVulkan()
{
}

void App::mainLoop()
{
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
}

void App::cleanup()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
