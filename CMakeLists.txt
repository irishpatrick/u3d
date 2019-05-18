cmake_minimum_required(VERSION 3.0)

project(game)

if (MSVC)

set(CMAKE_MSVCIDE_RUN_PATH "D:\\vcpkg\\installed\\x86-windows\\bin")

find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_library(ASSIMP_LIB assimp-vc140-mtd REQUIRED)
find_library(GL_LIB opengl32 REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
set(LIB 
	GLEW::GLEW 
	glm
	glfw
	${GL_LIB}
	SDL2::SDL2
	SDL2::SDL2main
	SDL2::SDL2_image
	${ASSIMP_LIB}
)

if (MSVC)
set(COMPILE_OPTS /DEBUG /std:c++latest /W3 /WX /MP /sdl /Od)
else (MSVC)
set(COMPILE_OPTS -g -std=c++11 -Wall -Werror)
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
    ${GLFW_LIBRARY_DIRS}
)
set(LIB SDL2 SDL2_image GL GLEW assimp glfw)
set(COMPILE_OPTS -g -std=c++11)

endif(MSVC)

file(GLOB sources src/*)
file(GLOB assets assets/*)

add_executable(${PROJECT_NAME} ${sources})

target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB})

file(COPY ${assets} DESTINATION ./assets)
