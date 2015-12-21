set(math_test_srcs simple_fun_test.cpp sort_fun_test.cpp brents_fun_test.cpp test_all.cpp)

add_executable(mathtest ${math_test_srcs})

target_link_libraries(mathtest mathhao)

install(TARGETS mathtest  DESTINATION test)
