cmake_minimum_required(VERSION 3.28)

project(CALDEIRA_LEGGET)

file(GLOB SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

add_compile_options(${PROJECT_NAME} -Wall -O3)