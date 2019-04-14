cmake_minimum_required(VERSION 3.0)

project(example)

set(LIB ${LIB} u3d)
set(I_DIR ${I_DIR} ${u3d_I_DIR})

add_subdirectory(./test)

