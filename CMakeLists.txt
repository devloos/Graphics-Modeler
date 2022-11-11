cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

project(gm)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

# Graphics Modelers
add_executable(${PROJECT_NAME} src/core/main.cpp)
target_include_directories(
  ${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)

# Libraries

if (APPLE)
  target_include_directories(${PROJECT_NAME} PUBLIC /opt/homebrew/include)
  target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)
endif (APPLE)
