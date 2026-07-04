cmake_minimum_required(VERSION 3.16)

project(TodoApp
    VERSION 1.0.0
    LANGUAGES CXX
)

add_library(todo_core
    src/Commander.cpp
    src/Parser.cpp
    src/Shell.cpp
)

target_include_directories(todo_core
    PUBLIC
    ${CMAKE+CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(todo_core
    PUBLIC
        cxx_std_17
)

add_executable(todo
    src/Todo.cpp
)

target_link_libraries(todo
    PRIVATE
        todo_core
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/config.txt
    ${CMAKE_CURRENT_BINARY_DIR}/config.txt
    COPYONLY
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/task_list.txt
    ${CMAKE_CURRENT_BINARY_DIR}/task_list.txt
    COPYONLY
)