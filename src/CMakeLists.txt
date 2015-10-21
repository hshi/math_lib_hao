set(math_srcs simple_fun.cpp brents_fun.cpp)

add_library(mathhao STATIC ${math_srcs})

install(TARGETS mathhao DESTINATION lib)
