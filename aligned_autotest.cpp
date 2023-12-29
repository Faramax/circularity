#define BOOST_TEST_MODULE aligned
#include <boost/test/unit_test.hpp>

#include "aligned.hpp"

BOOST_AUTO_TEST_CASE( less_test )
{
   using namespace circ;
   BOOST_CHECK(less(0, 5));
   BOOST_CHECK(!less(5, 0));
   BOOST_CHECK(less(-5, 0));
   BOOST_CHECK(!less(0, -5));
   BOOST_CHECK(!less(0, 0));
   BOOST_CHECK(!less(5, 5));
   BOOST_CHECK(!less(-5, -5));

   BOOST_CHECK(less<ptrdiff_t>(-6, std::numeric_limits<ptrdiff_t>::max() - 5));
   BOOST_CHECK(less<ptrdiff_t>(std::numeric_limits<ptrdiff_t>::max() - 5, -6));

   BOOST_CHECK(!less<ptrdiff_t>(-5, std::numeric_limits<ptrdiff_t>::max() - 6));
   BOOST_CHECK(!less<ptrdiff_t>(std::numeric_limits<ptrdiff_t>::max() - 5, -5));
   BOOST_CHECK(less<ptrdiff_t>(std::numeric_limits<ptrdiff_t>::max() - 4, -5));


   BOOST_CHECK(less<ptrdiff_t>(5, std::numeric_limits<ptrdiff_t>::max() + 5));
   BOOST_CHECK(!less<ptrdiff_t>(4, std::numeric_limits<ptrdiff_t>::max() + 5));
   BOOST_CHECK(!less<ptrdiff_t>(std::numeric_limits<ptrdiff_t>::max() + 5, 5));
   BOOST_CHECK(less<ptrdiff_t>(std::numeric_limits<ptrdiff_t>::max() + 6, 5));

   BOOST_CHECK(less<uint8_t>(0x0,   0xEF));
   BOOST_CHECK(less<uint8_t>(0xEF,  0xF0));
   BOOST_CHECK(less<uint8_t>(0xF0,  0x0));
   BOOST_CHECK(less<uint8_t>(0xF0,  0xFF));
   BOOST_CHECK(less<uint8_t>(0xFF,  0x7F));
   BOOST_CHECK(less<uint8_t>(0x80,  0xFF));
}

BOOST_AUTO_TEST_CASE( distance_test )
{
   using namespace circ;
   BOOST_CHECK_EQUAL(distance(-5, 5), 10);
   BOOST_CHECK_EQUAL(distance(5, -5), 10);
   BOOST_CHECK_EQUAL(distance(5, 5), 0);
   BOOST_CHECK_EQUAL(distance(-5, -5), 0);

   BOOST_CHECK_EQUAL(distance<ptrdiff_t>(-5, std::numeric_limits<ptrdiff_t>::max() - 5), std::numeric_limits<ptrdiff_t>::max());
   BOOST_CHECK_EQUAL(distance<ptrdiff_t>(-5, std::numeric_limits<ptrdiff_t>::max() - 4), std::numeric_limits<ptrdiff_t>::min());
}