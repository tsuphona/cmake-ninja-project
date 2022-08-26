#include <iostream>
#include <adder.hpp>
#include <GLFW/glfw3.h>

int main()
{
    std::cout << "CMake is an awesome tool!\n";
    std::cout << "Ninja is also an awesome tool!\n";
    std::cout << add(6.5f, 5.5f) << "\n";

    GLFWwindow *window;
    int width, height;

    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(300, 300, "Gears", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}