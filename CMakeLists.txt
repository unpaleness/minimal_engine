cmake_minimum_required(VERSION 4.3.1)

project(MinimalEngine LANGUAGES CXX)

add_compile_definitions(PROJECT_NAME="${CMAKE_PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(../glfw _cmake/glfw)
add_subdirectory(../glm _cmake/glm)

find_package(Vulkan REQUIRED)

set(SHADER_DIR ${PROJECT_SOURCE_DIR}/src/shaders)
set(SHADER_OUT_DIR compiled_shaders)
set(SHADER_OUT_DIR_FULL ${PROJECT_SOURCE_DIR}/${SHADER_OUT_DIR})
file(MAKE_DIRECTORY ${SHADER_OUT_DIR_FULL})
file(GLOB SHADERS ${SHADER_DIR}/*.vert ${SHADER_DIR}/*.frag)

foreach (SHADER IN LISTS SHADERS)
    get_filename_component(FILENAME ${SHADER} NAME)
    add_custom_command(OUTPUT ${SHADER_OUT_DIR_FULL}/${FILENAME}.spv
            COMMAND ${Vulkan_GLSLC_EXECUTABLE} ${SHADER} -o ${SHADER_OUT_DIR_FULL}/${FILENAME}.spv
            DEPENDS ${SHADER}
            COMMENT "Compiling shader ${FILENAME}.spv")
    add_custom_target(${FILENAME} DEPENDS ${SHADER} ${SHADER_OUT_DIR_FULL}/${FILENAME}.spv)
    list(APPEND SPV_SHADERS ${FILENAME})
endForeach ()

add_custom_target(shaders ALL DEPENDS ${SPV_SHADERS})

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
add_dependencies(${CMAKE_PROJECT_NAME} shaders)

set(SHADER_OUT_BUILD_DIR $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/${SHADER_OUT_DIR})
set(SHADER_COPY_TMP ${PROJECT_SOURCE_DIR}/copy_shaders_tmp)
add_custom_command(OUTPUT ${SHADER_COPY_TMP}
        COMMAND "${CMAKE_COMMAND}" -E copy_directory_if_newer
        "${SHADER_OUT_DIR_FULL}"
        "${SHADER_OUT_BUILD_DIR}"
        DEPENDS shaders)
add_custom_target(copy_shaders DEPENDS ${SHADER_COPY_TMP})

set(TEXTURES_OUT_BUILD_DIR $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/textures)
set(TEXTURES_COPY_TMP ${PROJECT_SOURCE_DIR}/copy_textures_tmp)
add_custom_command(OUTPUT ${TEXTURES_COPY_TMP}
        COMMAND "${CMAKE_COMMAND}" -E copy_directory_if_newer
        "${PROJECT_SOURCE_DIR}/src/textures"
        "${TEXTURES_OUT_BUILD_DIR}")
add_custom_target(copy_textures DEPENDS ${TEXTURES_COPY_TMP})

add_dependencies(${CMAKE_PROJECT_NAME} copy_shaders copy_textures)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE src/app.cpp src/app.h src/render.cpp src/render.h)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ../stb/)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE GLFW_INCLUDE_VULKAN)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE PROJECT_NAME="${CMAKE_PROJECT_NAME}")
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE SHADER_OUT_DIR="${SHADER_OUT_DIR}")
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
