cmake_minimum_required(VERSION 3.2)
project(circularity)

find_package(Boost)
if (${Boost_VERSION_STRING} LESS "1.66")
   set(BOOST_TEST_LIB "test_exec_monitor")
else ()
   set(BOOST_TEST_LIB "unit_test_framework")
endif ()
find_package(Boost COMPONENTS system ${BOOST_TEST_LIB} REQUIRED)
add_compile_options(-Wno-overflow -Wall -Wextra -Wpedantic -Werror)

add_executable(autotest_aligned
   aligned_autotest.cpp)
target_link_libraries(autotest_aligned ${Boost_LIBRARIES})

add_executable(autotest_based
   based_autotest.cpp)
target_link_libraries(autotest_based ${Boost_LIBRARIES})
