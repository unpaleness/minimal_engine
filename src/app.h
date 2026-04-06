#pragma once

class Render;
struct GLFWwindow;

class App
{
public:
    void Run();

private:
    void InitWindow();
    void MainLoop();
    void Cleanup();

    GLFWwindow* window = nullptr;
    Render* render = nullptr;
};
