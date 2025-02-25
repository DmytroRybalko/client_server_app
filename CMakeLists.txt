cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ClientServerApp)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define an alias for your source folder
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src_lin")

# Add the include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Check if a specific directory exists
if(EXISTS "${PROJECT_SOURCE_DIR}/include")
    message(STATUS "The include directory exists.")
else()
    message(FATAL_ERROR "The include directory does not exist!")
endif()

# Build the user library.
add_library(user_library STATIC ${SRC_DIR}/user_library.cpp)

# Create the server executable.
add_executable(server ${SRC_DIR}/server.cpp)
target_link_libraries(server PUBLIC user_library)
# Set the runtime output directory for the executable to the root directory.
set_target_properties(server PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Create the client executable.
add_executable(client ${SRC_DIR}/client.cpp)
target_link_libraries(client PUBLIC user_library)
# Set the runtime output directory for the executable to the root directory.
set_target_properties(client PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

#target_include_directories(server PUBLIC "${PROJECT_SOURCE_DIR}/include")



