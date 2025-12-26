cmake_minimum_required(VERSION 3.16)

project(extrans)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
	extrans.cpp
	mosaic.cpp
	ripple.cpp
	rotatebase.cpp
	rotatetrans.cpp
	turn.cpp
	turntrans_table.cpp
	wave.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE krkrsdl2plugin)
