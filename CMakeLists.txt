cmake_minimum_required(VERSION 3.16.0)
project(led VERSION 0.1.0
            DESCRIPTION "show machine statics on raspberry"
            LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# set bin prosition
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include(FetchContent)

# include u8g2 to show info on oleds

set(U8G2 u8g2)

FetchContent_Declare(
        ${U8G2}
        GIT_REPOSITORY https://hub.fastgit.org/olikraus/u8g2.git
        GIT_TAG 2.29.11)

# define register_component
function(register_component)
configure_file("csrc/mui.h" inc/mui.h COPYONLY)
endfunction(register_component)

# enddeifine register_component
FetchContent_MakeAvailable(${U8G2})

# end include u8g2
add_subdirectory(${CMAKE_SOURCE_DIR}/src)