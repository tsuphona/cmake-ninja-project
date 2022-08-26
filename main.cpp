#include <iostream>
#include <adder.hpp>

int main()
{
    std::cout << "CMake is an awesome tool!\n";
    std::cout << "Ninja is also an awesome tool!\n";
    std::cout << add(6.5f, 5.5f) << "\n";

    return 0;
}