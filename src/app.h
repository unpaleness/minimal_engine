#pragma once

class GLFWwindow;
struct VkInstance_T;

class App
{
public:
    void run();

private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();

    GLFWwindow* window = nullptr;
    VkInstance_T* vkInstance = nullptr;
};
