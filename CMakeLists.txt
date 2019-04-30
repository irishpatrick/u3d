cmake_minimum_required(VERSION 3.0)

project(temp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(GLEW REQUIRED glew)
pkg_check_modules(GLM REQUIRED glm)
pkg_check_modules(ASSIMP REQUIRED assimp)

set(
    I_DIR 
    ${ASSIMP_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS} 
    ${SDL2_IMAGE_INCLUDE_DIRS} 
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
)
set(
    L_DIR 
    ${ASSIMP_LIBRARY_DIRS}
    ${SDL2_LIBRARY_DIRS} 
    ${SDL2_IMAGE_LIBRARY_DIRS} 
    ${GLEW_LIBRARY_DIRS}
)
set(LIB SDL2 SDL2_image GL GLEW assimp)

set(COMPILE_OPTS -g -std=c++11)

add_subdirectory(./u3d)
add_subdirectory(./demo)