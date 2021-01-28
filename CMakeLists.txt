cmake_minimum_required(VERSION 3.16)
project(GLFW3_Tutorials)
#set(CMAKE_CXX_STANDARD 20)
#add_executable(GLFW3_Tutorials main.cpp)
#target_link_libraries(GLFW3_Tutorials  glm )

add_subdirectory(src)
add_subdirectory(tests)
#add_subdirectory(etc)
add_subdirectory(libs)
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})
add_definitions(${GLEW_DEFINITIONS})
if(NOT GLEW_FOUND)
    message(Error " GLEW not found")
endif(NOT GLEW_FOUND)

#Encontrando y linkeando glfw3
#find_package(GLFW REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_directories(${GLFW_LIBRARY_DIRS})
add_definitions(${GLFW_DEFINITIONS})

if(NOT GLFW_FOUND)
    message(Error "GLFW not found")
endif(NOT GLFW_FOUND)

#Encontrando y linkeando glm

#find_package(GLM REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})
link_directories(${GLM_LIBRARY_DIRS})
add_definitions(${GLM_DEFINITIONS})

if(NOT GLM_FOUND)
    message(Error "GLM not found")
endif(NOT GLM_FOUND)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

if(NOT OpenGL_FOUND)
    message(Error "OpenGL not found")
endif(NOT OpenGL_FOUND)

#Incluir archivos

add_executable(GLFW3_Tutorials main.cpp)

#SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
#SET(GCC_COVERAGE_LINK_FLAGS    "-lGL -lglut -lglu")
#
#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
#SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

target_link_libraries(GLFW3_Tutorials ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES}  ${GLM_LIBRARIES} glfw OpenGL::GL ${CMAKE_DL_LIBS})
