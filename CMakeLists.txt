cmake_minimum_required(VERSION 3.1)

# Project's name
project(Calculator)

# C++ standard
set(CMAKE_CXX_STANDARD 14)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

file(GLOB SOURCES "./src/*.cpp")
file(GLOB HEADERS "./src/*.hpp")
file(GLOB FORMS "./src/forms/*.ui")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/./src ${CMAKE_CURRENT_SOURCE_DIR}/./src/sct ${CMAKE_CURRENT_SOURCE_DIR}/./src/ut)

QT5_WRAP_UI( UI_HEADERS ${FORMS} )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UI_HEADERS})

set(SCT_SERVER OFF CACHE BOOL "Do you want to build program with SCT server?")
if(SCT_SERVER)
  add_definitions(-DSCT_SERVER)
  include( "./src/sct/SctServer.cmake" )
endif()

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

enable_testing()
# add unit test executable
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/./src/main.cpp")
SET(UNIT_TESTS_PROJECT ${PROJECT_NAME}_ut)
SET(UNIT_TESTS_MAIN "./src/ut/main.cpp")
add_executable(${UNIT_TESTS_PROJECT} ${SOURCES} ${UNIT_TESTS_MAIN} ${HEADERS} ${UI_HEADERS})
add_test(UnitTests ${UNIT_TESTS_PROJECT})
target_link_libraries(${UNIT_TESTS_PROJECT} Qt5::Widgets)
