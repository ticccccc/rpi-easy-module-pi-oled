add_executable(states states.cpp)

add_library(system lib/system.cpp)
target_include_directories(system PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_compile_definitions(states PUBLIC __ARM_LINUX__)

target_include_directories(states 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
    PUBLIC ${${U8G2}_BINARY_DIR}/inc/c
    PUBLIC ${${U8G2}_BUNARY_DIR}/inc/cpp)

target_link_libraries(states
    system
    cppU8g2lib
    cppU8x8lib
    cppu8g2port
    cppprint
    cu8g2
    cu8x8
    cgpio
    ci2c
    cspi)
