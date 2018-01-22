cmake_minimum_required(VERSION 3.1)

# Project's name
project(Calculator)

# C++ standard
set (CMAKE_CXX_STANDARD 14)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

file(GLOB SOURCES "./src/*.cpp")
file(GLOB HEADERS "./src/*.hpp")
file(GLOB FORMS "./src/forms/*.ui")

QT5_WRAP_UI( UI_HEADERS ${FORMS} )

# Tell CMake to create the helloworld executable
add_executable(calc ${SOURCES} ${HEADERS} ${UI_HEADERS})

# Use the Widgets module from Qt 5.
target_link_libraries(calc Qt5::Widgets)
