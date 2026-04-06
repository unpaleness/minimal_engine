cmake_minimum_required(VERSION 4.3.1)

project(MinimalEngine LANGUAGES CXX)

add_compile_definitions(PROJECT_NAME="${CMAKE_PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(../glfw _cmake/glfw)
add_subdirectory(../glm _cmake/glm)

find_package(Vulkan REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_sources(${CMAKE_PROJECT_NAME} PRIVATE src/app.cpp src/app.h src/render.cpp src/render.h)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE GLFW_INCLUDE_VULKAN)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<CXX_COMPILER_ID:MSVC>:/WX>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wextra>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Werror>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-O2>)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        Vulkan::Vulkan
        glfw
        glm
)
