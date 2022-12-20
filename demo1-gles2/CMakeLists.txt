project(Demo1-GLES2)
cmake_minimum_required(VERSION 3.0)


find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)


set(SOURCE_DIR src)
set(SOURCES ${SOURCE_DIR}/main.cpp)

add_executable(demo1 ${SOURCES})

target_link_libraries(demo1 ${OPENGL_LIBRARIES} SDL2::SDL2)
