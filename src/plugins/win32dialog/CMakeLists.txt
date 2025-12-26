cmake_minimum_required(VERSION 3.16)

project(win32dialog)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
	main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE krkrsdl2plugin)
