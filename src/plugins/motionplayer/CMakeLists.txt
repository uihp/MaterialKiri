cmake_minimum_required(VERSION 3.19)

project(motionplayer)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
    emotefile.cpp
    emoteplayer.cpp
    emoteplayerclass.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE krkrsdl2plugin)
