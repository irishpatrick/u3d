
project(game)

file(GLOB sources *.cpp *.hpp *.inl)
file(GLOB assets assets/*)
file(COPY ${assets} DESTINATION ./assets)

add_library(${PROJECT_NAME} STATIC ${sources})

target_compile_options(${PROJECT_NAME} PRIVATE ${cflags})
target_include_directories(${PROJECT_NAME} PRIVATE ${incl})
target_link_libraries(${PROJECT_NAME} PRIVATE ${libs})
