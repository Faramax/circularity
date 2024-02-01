#define BOOST_TEST_MODULE based
#include <boost/test/unit_test.hpp>
#include "based.hpp"

BOOST_AUTO_TEST_CASE(angle_distance_test)
{
   using namespace circular;
   BOOST_CHECK_EQUAL(angle_distance( 0.f,                  1.f),                 1);
   BOOST_CHECK_EQUAL(angle_distance( 1.f,                  0.f),                 1);
   BOOST_CHECK_EQUAL(angle_distance( 0.f,                 -1.f),                 1);
   BOOST_CHECK_EQUAL(angle_distance(-1.f,                  0.f),                 1);
   BOOST_CHECK_EQUAL(angle_distance(-0.5f,                 0.5f),                1);
   BOOST_CHECK_EQUAL(angle_distance( 0.5f,                -0.5f),                1);

   BOOST_CHECK_EQUAL(angle_distance(2*float(M_PI),         1.f),                 1);
   BOOST_CHECK_EQUAL(angle_distance(1.f,                   2*float(M_PI)),       1);
   BOOST_CHECK_EQUAL(angle_distance(0.f,                   2*float(M_PI) - 1),   1);
   BOOST_CHECK_EQUAL(angle_distance(2*float(M_PI) - 1,     0.f),                 1);
   BOOST_CHECK_EQUAL(angle_distance(2*float(M_PI)-0.5f,    0.5f),                1);
   BOOST_CHECK_EQUAL(angle_distance(0.5f,                  2*float(M_PI)-0.5f),  1);

   BOOST_CHECK_CLOSE(angle_distance(0.f,                   float(M_PI) + 1),     float(M_PI) - 1, 0.1f);
   BOOST_CHECK_CLOSE(angle_distance(float(M_PI) + 1,       0.f),                 float(M_PI) - 1, 0.1f);

   BOOST_CHECK_EQUAL(angle_distance(0.5f,                  1.5f),                1);
   BOOST_CHECK_EQUAL(angle_distance(1.5f,                  0.5f),                1);
   BOOST_CHECK_EQUAL(angle_distance(-0.5f,                -1.5f),                1);
   BOOST_CHECK_EQUAL(angle_distance(-1.5f,                -0.5f),                1);
}


BOOST_AUTO_TEST_CASE(normalize_around_0_test)
{
   using namespace circular;
   BOOST_CHECK_EQUAL(normalize_around_0<int32_t>(200, 200),    0);
   BOOST_CHECK_EQUAL(normalize_around_0<int32_t>(0, 200),      0);
   BOOST_CHECK_EQUAL(normalize_around_0<int32_t>(-50, 200),    -50);
   BOOST_CHECK_EQUAL(normalize_around_0<int32_t>(-250, 200),   -50);
   BOOST_CHECK_EQUAL(normalize_around_0<int32_t>(150, 200),    -50);
   BOOST_CHECK_EQUAL(normalize_around_0<int32_t>(350, 200),    -50);
   BOOST_CHECK_EQUAL(normalize_around_0<int32_t>(50, 200),     50);
}

BOOST_AUTO_TEST_CASE(normalize_positive_test)
{
   using namespace circular;
   BOOST_CHECK_EQUAL(normalize_positive<int32_t>(200, 200),    0);
   BOOST_CHECK_EQUAL(normalize_positive<int32_t>(0, 200),      0);
   BOOST_CHECK_EQUAL(normalize_positive<int32_t>(-50, 200),    150);
   BOOST_CHECK_EQUAL(normalize_positive<int32_t>(-250, 200),   150);
   BOOST_CHECK_EQUAL(normalize_positive<int32_t>(150, 200),    150);
   BOOST_CHECK_EQUAL(normalize_positive<int32_t>(350, 200),    150);
   BOOST_CHECK_EQUAL(normalize_positive<int32_t>(50, 200),     50);
}

BOOST_AUTO_TEST_CASE(bi_distance_test)
{
   using namespace circular;
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(200,  0,    200), 0);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(0,    200,  200), 0);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(0,    0,    200), 0);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(200,  200,  200), 0);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(-50,  0,    200), 50);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(-250, 0,    200), 50);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(150,  0,    200), 50);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(350,  0,    200), 50);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(50,   0,    200), 50);

   BOOST_CHECK_EQUAL(bi_distance<int32_t>(200,  100,  200), 100);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(100,  200,  200), 100);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(0,    100,  200), 100);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(100,  0,    200), 100);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(-50,  100,  200), 50);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(-250, 100,  200), 50);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(150,  100,  200), 50);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(350,  100,  200), 50);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(50,   100,  200), 50);

   BOOST_CHECK_EQUAL(bi_distance<int32_t>(10,   20,   200), 10);
   BOOST_CHECK_EQUAL(bi_distance<int32_t>(20,   10,   200), 10);
}