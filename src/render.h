#pragma once

#include <vector>

#include <vulkan/vulkan_core.h>

struct GLFWwindow;

class Render
{
public:
    Render(GLFWwindow* aWindow);
    ~Render();

    Render(const Render&) = delete;
    Render(Render&&) = delete;
    Render& operator=(const Render&) = delete;
    Render& operator=(Render&&) = delete;

    void DrawFrame();
    void WaitForIdle();

private:
    void CreateInstance();
    void SetupDebugMessenger();
    void CreateSurface();
    void PickPhysicalDevice();
    void CreateLogicalDevice();
    void CreateSwapChain();
    void CreateImageViews();
    void CreateRenderPass();
    void CreateGraphicsPipeline();
    void CreateFrameBuffers();
    void CreateCommandPool();
    void CreateCommandBuffer();
    void CreateSyncObjects();

    void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

private:
    GLFWwindow* window = nullptr;
    VkInstance vkInstance = nullptr;
    VkDebugUtilsMessengerEXT vkDebugMessenger = nullptr;
    VkPhysicalDevice vkPhysicalDevice = nullptr;
    VkDevice vkDevice = nullptr;
    VkQueue vkGraphicsQueue = nullptr;
    VkQueue vkPresentQueue = nullptr;
    VkSurfaceKHR vkSurface = nullptr;
    VkSwapchainKHR vkSwapChain = nullptr;
    std::vector<VkImage> vkSwapChainImages;
    VkFormat vkSwapChainImageFormat;
    VkExtent2D vkSwapChainExtent;
    std::vector<VkImageView> vkSwapChainImageViews;
    VkPipelineLayout vkPipelineLayout = nullptr;
    VkRenderPass vkRenderPass = nullptr;
    VkPipeline vkGraphicsPipeline = nullptr;
    std::vector<VkFramebuffer> vkSwapChainFramebuffers;
    VkCommandPool vkCommandPool = nullptr;
    VkCommandBuffer vkCommandBuffer = nullptr;
    VkSemaphore vkImageAvailableSemaphore = nullptr;
    VkSemaphore vkRenderFinishedSemaphore = nullptr;
    VkFence vkInFlightFence = nullptr;
};
