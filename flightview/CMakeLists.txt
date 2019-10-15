
project(flightview)

file(GLOB sources *.cpp *.hpp *.inl)
file(GLOB assets assets/*)
file(COPY ${assets} DESTINATION ./assets)

add_executable(${PROJECT_NAME} ${sources})

target_compile_options(${PROJECT_NAME} PRIVATE ${cflags})
target_include_directories(${PROJECT_NAME} PRIVATE ${incl} ${u3d_incl})
target_link_libraries(${PROJECT_NAME} PRIVATE u3d)
