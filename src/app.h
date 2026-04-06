#pragma once

class Graphics;
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
    Graphics* graphics = nullptr;
};
