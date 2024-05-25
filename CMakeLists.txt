cmake_minimum_required(VERSION 3.14)
project(wordle)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_executable(
  main
  main.cpp
  lista_ordenada.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
