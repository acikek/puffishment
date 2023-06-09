cmake_minimum_required(VERSION 3.3.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Puffishment VERSION 1.0.0)

# Use GLOB_RECURSE instead of GLOB
# to recursively add all source files 
# under src/ 
#file(GLOB_RECURSE SOURCES
#	src/*.cpp
#)

# Set up the mod binary
add_library(${PROJECT_NAME} SHARED 
    src/main.cpp
    src/modify/PlayerObjectMod.cpp
    src/modify/PlayLayerMod.cpp
    src/modify/EndLevelLayerMod.cpp
    src/types/BufferData.cpp
    src/types/punishments/Punishment.cpp
    src/types/punishments/Collection.cpp
    src/types/punishments/impl/Boost.cpp
    src/types/punishments/impl/Popup.cpp
    src/types/punishments/impl/Ding.cpp
)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} $ENV{GEODE_SDK}/build)

# Set up dependencies, resources, link Geode
setup_geode_mod(${PROJECT_NAME})
