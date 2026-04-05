cmake_minimum_required(VERSION 4.3.1)

project(MinimalEngine LANGUAGES CXX)

add_compile_definitions(PROJECT_NAME="${CMAKE_PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(../glfw _cmake/glfw)
add_subdirectory(../glm _cmake/glm)

find_package(Vulkan REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_sources(${CMAKE_PROJECT_NAME} PRIVATE src/app.cpp src/app.h)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        Vulkan::Vulkan
        glfw
        glm
)
