cmake_minimum_required(VERSION 3.0)

project(u3d)

if (MSVC)

set(CMAKE_MSVCIDE_RUN_PATH "D:\\vcpkg\\installed\\x86-windows\\bin")

find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_library(ASSIMP_LIB assimp-vc140-mtd REQUIRED)
find_library(GL_LIB opengl32 REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)
set(libs
	GLEW::GLEW 
	glm
	glfw
	${GL_LIB}
	SDL2::SDL2
	SDL2::SDL2main
	SDL2::SDL2_image
	${ASSIMP_LIB}
	Catch2::Catch2
)

if (MSVC)
set(cflags /DEBUG /std:c++latest /W3 /WX /MP /sdl /Od)
else (MSVC)
set(cflags -g -std=c++11 -Wall -Werror)
endif (MSVC)

else(MSVC)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(GLEW REQUIRED glew)
pkg_check_modules(GLM REQUIRED glm)
pkg_check_modules(ASSIMP REQUIRED assimp)

set(
    incl
    ${ASSIMP_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS} 
    ${SDL2_IMAGE_INCLUDE_DIRS} 
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
)
set(
    ldir
    ${ASSIMP_LIBRARY_DIRS}
    ${SDL2_LIBRARY_DIRS} 
    ${SDL2_IMAGE_LIBRARY_DIRS} 
    ${GLEW_LIBRARY_DIRS}
    ${GLFW_LIBRARY_DIRS}
)
set(libs SDL2 SDL2_image GL GLEW assimp glfw)
set(cflags -g -std=c++11)

endif(MSVC)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
add_subdirectory(${CMAKE_SOURCE_DIR}/game)
add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
