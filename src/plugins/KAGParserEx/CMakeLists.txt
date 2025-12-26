cmake_minimum_required(VERSION 3.16)

project(KAGParserEx)

add_compile_definitions(KAGPARSER_EX_PLUGIN)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
    KAGParserEx.cpp
    KAGParserEx.hpp
    Main.cpp
    tjsHashSearch.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE krkrsdl2plugin)
