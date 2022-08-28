add_library(adder adder.cpp)

install(TARGETS adder DESTINATION lib)
install(FILES adder.hpp DESTINATION include)