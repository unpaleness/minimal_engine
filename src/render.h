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
    void OnFrameBufferResized();

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
    void CreateCommandBuffers();
    void CreateSyncObjects();
    void CreateSyncObjectsPresent();
    void CleanSwapChain();
    void RecreateSwapChain();
    void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

private:
    GLFWwindow* window = nullptr;
    VkInstance instance = nullptr;
    VkDebugUtilsMessengerEXT debugMessenger = nullptr;
    VkPhysicalDevice physicalDevice = nullptr;
    VkDevice device = nullptr;
    VkQueue graphicsQueue = nullptr;
    VkQueue presentQueue = nullptr;
    VkSurfaceKHR surface = nullptr;
    VkSwapchainKHR swapChain = nullptr;
    uint32_t swapChainImageCount = 0;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    VkPipelineLayout pipelineLayout = nullptr;
    VkRenderPass renderPass = nullptr;
    VkPipeline graphicsPipeline = nullptr;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkCommandPool commandPool = nullptr;
    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> presentSemaphores;
    std::vector<VkFence> inFlightFences;
    uint32_t currentFrame = 0;
    bool framebufferResized = false;
};
