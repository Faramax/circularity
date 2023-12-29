#pragma once
#include <type_traits>
#include <cmath>

namespace circ {
   template <typename T>
   bool less(T const& l, T const& r)
   {
      static_assert(std::is_integral<T>::value, "Valid only for integral types");
      auto const sub = typename std::make_signed<T>::type(l - r);
      return sub < 0;
   }

   template <typename T>
   T distance(T const& l, T const& r)
   {
      static_assert(std::is_integral<T>::value, "Valid only for the integral types");
      return std::abs(l - r);
   }

} // circ