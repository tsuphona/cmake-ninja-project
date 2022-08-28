#include <GLFW/glfw3.h>
#include <cnpConfig.h>
#include <iostream>
#ifdef USE_ADDER
  #include <adder.hpp>
#endif

int main(int argc, char *argv[]) {
  std::cout << "CMake is an awesome tool!\n";
  std::cout << "Ninja is also an awesome tool!\n";

#ifdef USE_ADDER
  std::cout << "Using Adder lib: " << add(6.5f, 5.5f) << "\n";
#else
  std::cout << "Not using Adder lib: " << 6.5f + 5.5f << "\n";
#endif

  std::cout << argv[0] << " Version " << cnp_VERSION_MAJOR << "."
            << cnp_VERSION_MINOR << "\n";

  GLFWwindow *window;
  int width, height;

  if (!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    exit(EXIT_FAILURE);
  }

  window = glfwCreateWindow(300, 300, "Gears", NULL, NULL);
  if (!window) {
    fprintf(stderr, "Failed to open GLFW window\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  return 0;
}