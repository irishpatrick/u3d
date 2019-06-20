
project(u3d)

file(GLOB sources *.cpp *.hpp *.inl)

add_library(${PROJECT_NAME} STATIC ${sources})

target_compile_options(${PROJECT_NAME} PRIVATE ${cflags})
target_include_directories(${PROJECT_NAME} PRIVATE ${incl})
target_link_libraries(${PROJECT_NAME} PRIVATE ${libs})

set(${PROJECT_NAME}_incl ${PROJECT_SOURCE_DIR} CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
set(incl ${incl} ${${PROJECT_NAME}_incl}})
