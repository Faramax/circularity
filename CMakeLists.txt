project(circularity)
cmake_minimum_required(VERSION 3.2)
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost)
if (${Boost_VERSION_STRING} LESS "1.66")
   set(BOOST_TEST_LIB "test_exec_monitor")
else ()
   set(BOOST_TEST_LIB "unit_test_framework")
endif ()

add_subdirectory(based)
add_subdirectory(aligned)
