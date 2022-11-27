cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (APPLE)
  set(CMAKE_OSX_DEPLOYMENT_TARGET 13.0)
endif (APPLE)


project(gm)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

# Graphics Modelers
add_executable(
  ${PROJECT_NAME} src/core/main.cpp src/qt/main-window.cpp src/utility/utility.cpp
  src/models/shape.cpp src/models/free-form/circle.cpp 
  src/models/free-form/ellipse.cpp src/models/line.cpp 
  src/models/polygon/polygon.cpp src/models/polygon/polyline.cpp 
  src/models/quadrilateral/rectangle.cpp src/models/quadrilateral/square.cpp 
  src/models/text.cpp src/qt/widgets/login-widget.cpp src/qt/widgets/main-widget.cpp)

target_include_directories(
  ${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)

# Libraries

if (APPLE)
  target_include_directories(${PROJECT_NAME} PUBLIC /opt/homebrew/include)
endif (APPLE)

if (WIN32)
  # Not in use rn
  # target_include_directories(${PROJECT_NAME} PUBLIC /opt/homebrew/include)
endif (WIN32)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets Qt6::Gui)
