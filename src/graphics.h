#pragma once

struct VkDebugUtilsMessengerEXT_T;
struct VkDevice_T;
struct VkInstance_T;
struct VkPhysicalDevice_T;
struct VkQueue_T;

class Graphics
{
public:
    Graphics();
    ~Graphics();

    void CreateInstance();
    void SetupDebugMessenger();
    void PickPhysicalDevice();
    void CreateLogicalDevice();

private:
    VkInstance_T* instance = nullptr;
    VkDebugUtilsMessengerEXT_T* debugMessenger = nullptr;
    VkPhysicalDevice_T* physicalDevice = nullptr;
    VkDevice_T* device = nullptr;
    VkQueue_T* graphicsQueue = nullptr;
};
