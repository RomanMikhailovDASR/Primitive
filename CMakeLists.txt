cmake_minimum_required(VERSION 3.15)
project(Circle)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp Vector2D.cpp Vector2D.h Matrix.cpp Matrix.h Vector3D.cpp Vector3D.h Circle.cpp Circle.h)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(untitled ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})



target_link_libraries(untitled sfml-graphics sfml-audio)