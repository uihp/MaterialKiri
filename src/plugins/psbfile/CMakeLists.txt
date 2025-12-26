cmake_minimum_required(VERSION 3.19)

project(psbfile)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
    PSB.cpp
    psbData.cpp
    PSBFile.cpp
    psbMedia.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE krkrsdl2plugin)
