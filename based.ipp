#include <type_traits>
#include <cmath>

namespace circular
{
   static constexpr float pi = 3.14159265358979323846;

   namespace detail
   {
      template <typename T>
      T normalize_positive(const T &a, const T &base, typename std::enable_if<std::is_integral<T>::value>::type * = nullptr)
      {
         const T reminder = a % base;
         return (reminder >= 0) ? reminder : reminder + base;
      }

      template <typename T>
      T normalize_positive(const T &a, const T &base, typename std::enable_if<std::is_floating_point<T>::value>::type * = nullptr)
      {
         const T reminder = std::remainder<T>(a, base);
         return (reminder >= 0) ? reminder : reminder + base;
      }

      template <typename T>
      T normalize_around_0(const T &a, const T &base, typename std::enable_if<std::is_integral<T>::value>::type * = nullptr)
      {
         const T reminder = ((a + base/2) % base) - base/2;
         return (reminder >= -base/2) ? reminder : reminder + base;
      }

      template <typename T>
      T normalize_around_0(const T &a, const T &base, typename std::enable_if<std::is_floating_point<T>::value>::type * = nullptr)
      {
         const T reminder = std::remainder<T>(a + base/2, base) - base/2;
         return (reminder >= -base/2) ? reminder : reminder + base;
      }
   }

   //! Нормализация в положительную сторону. Результирующеее число будет в диапазоне [0; base)
   template <typename T>
   T normalize_positive(const T &a, const T &base)
   {
      return detail::normalize_positive<T>(a, base);
   }

   //! Нормализация относительно 0. Результирующеее число будет в диапазоне [-base/2; base/2)
   template <typename T>
   T normalize_around_0(const T &a, const T &base)
   {
      return detail::normalize_around_0<T>(a, base);
   }

   //! Вычисляет расстояние между двумя значениями опираясь на базу. Ответ в диапазоне [0; base/2)
   template <typename T>
   T bi_distance(T const& a, T const& b, T const& base)
   {
      return std::min(normalize_positive<T>(a - b, base), normalize_positive<T>(b - a, base));
   }

   //! Вычисляет расстояние между двумя углами. Входные углы в любом диапазоне. Ответ в диапазоне [0; Pi)
   float angle_distance(float a, float b)
   {
      return bi_distance(a, b, 2*pi);
   }
}