#pragma once
#include <type_traits>
#include <cmath>

namespace circular {

   /// Less means minimum distance on circular numbers,
   /// For instance less(250, 5) is true on UINT8_T because distance 250->5 is less than 5->250
   template <typename T>
   bool less(T const& l, T const& r)
   {
      static_assert(std::is_integral<T>::value, "Valid only for integral types");
      using signedT = typename std::make_signed<T>::type;
      auto const sub = signedT(l - r);
      return (sub != std::numeric_limits<signedT>::min()) && (sub < 0);
   }

   /// Here we assume that the circle has begin and calculate distance in one direction from begin to l and r.
   /// For instance less(250, 5, 0) is false on UINT8_T because distance 0->250 is more than 0->5
   template <typename T>
   bool less(T const& l, T const& r, T const& begin)
   {
      return false;
   }

   //! Direction independent distance between two points on the circle
   //! The result is in the range [0, std::numeric_limits<T>::max()/2].
   template <typename T>
   T distance(T const& l, T const& r)
   {
      static_assert(std::is_integral<T>::value, "Valid only for the integral types");
      return std::abs(l - r);
   }

   //! Direction dependent distance strictly from point l to point r. We suppose that l always before r.
   //! The result is in the range [0, std::numeric_limits<T>::max()].
   template <typename T>
   T track(T const& l, T const& r)
   {
      return T{};
   }

} // circ