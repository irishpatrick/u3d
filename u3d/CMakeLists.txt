cmake_minimum_required(VERSION 3.0)

project(u3d)

file(GLOB sources src/*)

link_directories(${PROJECT_NAME} PRIVATE ${L_DIR})
add_library(${PROJECT_NAME} SHARED ${sources})
target_include_directories(${PROJECT_NAME} PRIVATE ${I_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB})

set(${PROJECT_NAME}_I_DIR ${PROJECT_SOURCE_DIR}/src CACHE INTERNAL "${PROJECT_NAME} Include Directories" FORCE)
