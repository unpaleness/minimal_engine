#pragma once

class GLFWwindow;

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
};
