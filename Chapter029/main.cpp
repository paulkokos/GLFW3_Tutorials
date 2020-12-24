#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <string>
#include <fstream>

#pragma comment( lib, "glew32.lib" )
#pragma comment( lib, "glfw3.lib" )
#pragma comment (lib, "OpenGL32.lib")


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL - Triangle", nullptr, nullptr); // Windowed
    glfwMakeContextCurrent(window);

    glewInit();

    float vertices[] = {
            -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.0f, 1.0f,
            0.0f,  0.5f, 0.0f, 1.0f
    };

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    std::ifstream ivs("vs.glsl");
    std::string vs((std::istreambuf_iterator<char>(ivs)), (std::istreambuf_iterator<char>()));
    const char* vsc = vs.c_str();
    std::ifstream ifs("fs.glsl");
    std::string fs((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    const char* fsc = fs.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vsc, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fsc, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glUseProgram(shaderProgram);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);

        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}