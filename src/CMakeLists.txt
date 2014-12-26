set(math_srcs math_container.cpp)

add_library(mathhao STATIC ${math_srcs})

install(TARGETS mathhao DESTINATION lib)
