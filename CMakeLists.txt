cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(main)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

# Graphics Modelers
add_executable(${PROJECT_NAME} src/core/main.cpp)
target_include_directories(
  ${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)

# Libraries
target_include_directories(${PROJECT_NAME} PUBLIC /opt/homebrew/include)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

# Letting CMake find library
# find_library(${LIB_NAME} ${LIB_TO_FIND} PATHS /tmp/customPath)
# User explicitly finding library
# target_include_directories(${PROJECT_NAME} PUBLIC ${LIB_HEADER_FILES})
# target_link_libraries(${PROJECT_NAME} PUBLIC ${LIB_TO_INCLUDE})

