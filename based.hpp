#pragma once

#include "based.ipp"

namespace circular
{
   //! Нормализация в положительную сторону. Результирующеее число будет в диапазоне [0; base)
   template <typename T>
   T normalize_positive(const T &a, const T &base);

   //! Нормализация относительно 0. Результирующеее число будет в диапазоне [-base/2; base/2)
   template <typename T>
   T normalize_around_0(const T &a, const T &base);

   //! Вычисляет расстояние между двумя значениями опираясь на базу. Ответ в диапазоне [0; base/2)
   template <typename T>
   T bi_distance(T const& a, T const& b, T const& base);

   //! Вычисляет расстояние между двумя углами. Входные углы в любом диапазоне. Ответ в диапазоне [0; Pi)
   template <typename T>
   T angle_distance(T const& a, T const& b);

   //! normalize_around_0, для углов. Входные углы в любом диапазоне. Ответ в диапазоне [-Pi; Pi)
   template <typename T>
   T normalize_angle(const T& a);

}