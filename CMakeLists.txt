cmake_minimum_required(VERSION 3.16)
project(Snaky_gamey)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 11)

add_executable(snake_conquer main.cpp)

target_link_libraries(snake_conquer ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
