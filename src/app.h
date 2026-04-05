#pragma once

#include <memory>

class GLFWwindow;
class Graphics;

class App
{
public:
    void Run();

private:
    void InitWindow();
    void MainLoop();
    void Cleanup();

    GLFWwindow* window = nullptr;
    Graphics* graphics = nullptr;
};
