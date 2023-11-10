find_package(Boost COMPONENTS system ${BOOST_TEST_LIB} REQUIRED)
add_executable(autotest_based
   based_autotest.cpp)
target_link_libraries(autotest_based ${Boost_LIBRARIES})