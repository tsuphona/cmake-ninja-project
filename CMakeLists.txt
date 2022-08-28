cmake_minimum_required(VERSION 3.24.1)

project(cnp VERSION 1.0)

# Adder use logic
option(USE_ADDER "A simple library for adding to floats." ON)

if(USE_ADDER)
    add_subdirectory(adder)

    list(APPEND EXTRA_LIB_DIRS "adder")
    list(APPEND EXTRA_INCLUDE_DIRS "adder")
    list(APPEND EXTRA_LINKS adder)

endif()


configure_file(cnpConfig.h.in cnpConfig.h)

add_executable(${PROJECT_NAME} main.cpp)


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})


add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE external/glfw/src/
    ${EXTRA_LIB_DIRS}
)

target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS} glfw)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/cnpConfig.h" DESTINATION include)