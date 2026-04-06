#pragma once

struct GLFWwindow;
struct VkDebugUtilsMessengerEXT_T;
struct VkDevice_T;
struct VkInstance_T;
struct VkPhysicalDevice_T;
struct VkQueue_T;
struct VkSurfaceKHR_T;

class Graphics
{
public:
    Graphics(GLFWwindow* aWindow);
    ~Graphics();

private:
    void CreateInstance();
    void SetupDebugMessenger();
    void CreateSurface();
    void PickPhysicalDevice();
    void CreateLogicalDevice();

private:
    GLFWwindow* window = nullptr;
    VkInstance_T* vkInstance = nullptr;
    VkDebugUtilsMessengerEXT_T* vkDebugMessenger = nullptr;
    VkPhysicalDevice_T* vkPhysicalDevice = nullptr;
    VkDevice_T* vkDevice = nullptr;
    VkQueue_T* vkPresentQueue = nullptr;
    VkSurfaceKHR_T* vkSurface = nullptr;
};
