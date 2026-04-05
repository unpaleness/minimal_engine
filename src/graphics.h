#pragma once

struct VkDebugUtilsMessengerEXT_T;
struct VkInstance_T;
struct VkPhysicalDevice_T;

class Graphics
{
public:
    Graphics();
    ~Graphics();

    void CreateInstance();
    void SetupDebugMessenger();
    void PickPhysicalDevice();

private:
    VkInstance_T* vkInstance = nullptr;
    VkDebugUtilsMessengerEXT_T* vkDebugMessenger = nullptr;
    VkPhysicalDevice_T* vkPhysicalDevice = nullptr;
};
