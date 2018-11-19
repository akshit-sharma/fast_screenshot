cmake_minimum_required(VERSION 3.8)
project(screenshot)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package( OpenCV REQUIRED )
find_package( X11 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${X11_INCLUDE_DIRS} )

set(SOURCE_FILES 
  src/screenshot.cpp
  )

set(SIMPLE_FILE
  src/simple.cpp
  )


add_executable(screenshot src/main.cpp ${SOURCE_FILES})
add_executable(simple src/simple.cpp)

target_link_libraries( screenshot ${OpenCV_LIBS} ${X11_LIBRARIES} )
target_link_libraries( simple ${OpenCV_LIBS} ${X11_LIBRARIES} )

add_custom_command(TARGET screenshot POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_CURRENT_SOURCE_DIR})

