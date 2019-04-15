cmake_minimum_required(VERSION 3.0)

project(demo)

file(GLOB sources src/*)

link_directories(${PROJECT_NAME} PRIVATE ${L_DIR})
add_executable(${PROJECT_NAME} ${sources})
target_include_directories(${PROJECT_NAME} PRIVATE ${I_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB})
