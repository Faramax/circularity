find_package(Boost COMPONENTS system ${BOOST_TEST_LIB} REQUIRED)
add_executable(autotest_aligned
   aligned_autotest.cpp)
target_link_libraries(autotest_aligned ${Boost_LIBRARIES})