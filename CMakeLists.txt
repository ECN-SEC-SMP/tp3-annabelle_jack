
cmake_minimum_required(VERSION 3.0)
project(CPP_TP3_JAK_ANNA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

file(MAKE_DIRECTORY output) # Create directory for outputs

set(sources
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TPoint.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TForme.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TRectangle.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TCarre.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ListeFormes.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TPointSpecialisation.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_compile_definitions(PROJECT_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(CPP_TP3_JAK_ANNA ${sources})