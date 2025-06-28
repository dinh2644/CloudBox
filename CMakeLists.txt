# Declare versions
cmake_minimum_required(VERSION 3.25.1)

# Define the C++ standard whose features we request to build this project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the project version
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_REVISION 0)

# Set the project name with the corresponding version
project(CloudBox VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REVISION})

# Add an executable to our project
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/core/VmManager.cpp
    src/platform/linux/QemuController.cpp 
    src/cli/CLIParser.cpp
    )

# Adds src include folder
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/include)



