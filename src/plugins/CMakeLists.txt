cmake_minimum_required(VERSION 3.19)

project(krkrsdl2plugin)

add_library(${PROJECT_NAME} STATIC)

add_subdirectory(external/glm-1.0.2)
target_link_libraries(${PROJECT_NAME} PUBLIC glm::glm)
target_link_libraries(${PROJECT_NAME} PUBLIC glm::glm-header-only)

target_compile_definitions(${PROJECT_NAME} PUBLIC ${KRKRSDL2_DEFINITIONS})

add_subdirectory(extrans)
add_subdirectory(KAGParserEx)
add_subdirectory(motionplayer)
add_subdirectory(psbfile)
add_subdirectory(win32dialog)

target_include_directories(${PROJECT_NAME} PUBLIC .)
set(KRKRSDL2PLUGIN_INCLUDES "${KRKRSDL2COMMON_INCLUDES}")
list(TRANSFORM KRKRSDL2PLUGIN_INCLUDES PREPEND "${CMAKE_SOURCE_DIR}/")
target_include_directories(${PROJECT_NAME} PUBLIC ${KRKRSDL2PLUGIN_INCLUDES})

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${KRKRSDL2COMMON_NAME}
    extrans
    KAGParserEx
    motionplayer
    psbfile
    win32dialog
)
