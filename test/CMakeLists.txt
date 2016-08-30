set(test_exe mathtest)

set(test_srcs
        ../inc/brents_fun.h
        ../inc/math_container.h
        ../inc/simple_fun.h
        ../inc/sort_fun.h
        brents_fun_test.cpp
        simple_fun_test.cpp
        sort_fun_test.cpp
        test_all.cpp)

add_executable(${test_exe} ${test_srcs})

target_link_libraries(${test_exe} mathhao)

install(TARGETS ${test_exe}  DESTINATION test)
