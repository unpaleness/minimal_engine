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
    void CreateDescriptorSetLayout();
    void CreateGraphicsPipeline();
    void CreateFrameBuffers();
    void CreateCommandPool();
    void CreateTextureImage();
    void CreateTextureImageView();
    void CreateTextureSampler();
    void CreateVertexBuffers();
    void CreateIndexBuffers();
    void CreateUniformBuffers();
    void CreateDescriptorPool();
    void CreateDescriptorSets();
    void CreateCommandBuffers();
    void CreateSyncObjects();
    void CreateSyncObjectsPresent();
    void CleanSwapChain();
    void RecreateSwapChain();
    void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    void UpdateUniformBuffer(uint32_t currentImage);

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
    VkDescriptorSetLayout descriptorSetLayout = nullptr;
    VkPipelineLayout pipelineLayout = nullptr;
    VkRenderPass renderPass = nullptr;
    VkPipeline graphicsPipeline = nullptr;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkCommandPool commandPool = nullptr;
    VkBuffer vertexBuffer = nullptr;
    VkDeviceMemory vertexBufferMemory = nullptr;
    VkBuffer indexBuffer = nullptr;
    VkDeviceMemory indexBufferMemory = nullptr;
    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;
    VkImage textureImage = nullptr;
    VkImageView textureImageView = nullptr;
    VkSampler textureSampler = nullptr;
    VkDeviceMemory textureImageMemory = nullptr;
    VkDescriptorPool descriptorPool = nullptr;
    std::vector<VkDescriptorSet> descriptorSets;
    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> presentSemaphores;
    std::vector<VkFence> inFlightFences;
    uint32_t currentFrame = 0;
    bool framebufferResized = false;
};
