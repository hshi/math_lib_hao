set(src_lib mathhao)

set(srcs
        ../inc/brents_fun.h
        ../inc/math_container.h
        ../inc/simple_fun.h
        ../inc/sort_fun.h
        brents_fun.cpp
        simple_fun.cpp)

add_library(${src_lib} STATIC ${srcs})

install(TARGETS ${src_lib}  DESTINATION lib)
