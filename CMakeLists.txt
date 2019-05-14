cmake_minimum_required(VERSION 3.0)

project(temp)

if (MSVC)
set(ASSIMP_NAME "assimp-vc140-mt")
set(DEVIL_NAME "DevIL")
set(GL_NAME "opengl32")
else (MSVC)
set(ASSIMP_NAME "assimp")
set(DEVIL_NAME "IL")
set(GL_NAME "GL")
endif (MSVC)

#if (MSVC)

set(CMAKE_MSVCIDE_RUN_PATH "D:\\vcpkg\\installed\\x86-windows\\bin")

find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_library(ASSIMP_LIB ${ASSIMP_NAME} REQUIRED)
find_library(GL_LIB ${GL_NAME} REQUIRED)
find_library(DEVIL_LIB ${DEVIL_NAME} REQUIRED)

#if (UNIX)
find_library(TIFF_LIB tiff REQUIRED)
find_library(Z_LIB z REQUIRED)
find_library(PNG_LIB png REQUIRED)
find_library(JPEG_LIB jpeg REQUIRED)
find_library(JASPER_LIB jasper REQUIRED)
find_library(LZMA_LIB lzma REQUIRED)
find_library(TURBO_LIB turbojpeg REQUIRED)
find_library(LCMS2_LIB lcms2 REQUIRED)

set(LIB 
	GLEW::GLEW 
	glm
	glfw
	${ASSIMP_LIB}
	${GL_LIB}
	${DEVIL_LIB}
	${TIFF_LIB}
	${Z_LIB}
	${JPEG_LIB}
	${TURBO_LIB}
	${PNG_LIB}
	${JASPER_LIB}
	${LZMA_LIB}
	${LCMS2_LIB}
)

#else (UNIX)

set(LIB 
	GLEW::GLEW 
	glm
	glfw
	${ASSIMP_LIB}
	${GL_LIB}
	${DEVIL_LIB}
)

#endif (UNIX)

if (MSVC)
set(COMPILE_OPTS /DEBUG /std:c++latest /W3 /WX /MP /sdl /Od)
else (MSVC)
set(COMPILE_OPTS -g -std=c++11 -Wall -Werror)
endif (MSVC)

#else(MSVC)

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(SDL2 REQUIRED sdl2)
#pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
#pkg_check_modules(GLEW REQUIRED glew)
#pkg_check_modules(GLM REQUIRED glm)
#pkg_check_modules(ASSIMP REQUIRED assimp)

#set(
#    I_DIR 
#    ${ASSIMP_INCLUDE_DIRS}
#    ${SDL2_INCLUDE_DIRS} 
#    ${SDL2_IMAGE_INCLUDE_DIRS} 
#    ${GLEW_INCLUDE_DIRS}
#    ${GLM_INCLUDE_DIRS}
#)
#set(
#    L_DIR 
#    ${ASSIMP_LIBRARY_DIRS}
#    ${SDL2_LIBRARY_DIRS} 
#    ${SDL2_IMAGE_LIBRARY_DIRS} 
#    ${GLEW_LIBRARY_DIRS}
#)
#set(LIB SDL2 SDL2_image GL GLEW assimp)
#set(COMPILE_OPTS -g -std=c++11)

#endif(MSVC)

file(GLOB sources src/*)
file(GLOB assets assets/*)

add_executable(${PROJECT_NAME} ${sources})

target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB})

file(COPY ${assets} DESTINATION ./assets)
