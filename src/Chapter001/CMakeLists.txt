add_executable(Chapter001 main.cpp)
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

if(NOT OpenGL_FOUND)
    message(Error "OpenGL not found")
endif(NOT OpenGL_FOUND)
target_link_libraries(Chapter001 ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES}  ${GLM_LIBRARIES} glfw OpenGL::GL ${CMAKE_DL_LIBS})
