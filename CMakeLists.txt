cmake_minimum_required(VERSION 4.3.1)

project(MinimalEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(../glfw _cmake/glfw)
add_subdirectory(../glm _cmake/glm)

find_package(Vulkan REQUIRED)

add_executable(MinimalEngine src/main.cpp)

target_link_libraries(MinimalEngine PRIVATE
    Vulkan::Vulkan
    glfw
    glm
)
