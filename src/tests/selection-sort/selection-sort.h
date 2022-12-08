#pragma once
#include "gm/vector.h"

template <typename T>
void selection_sort(GM::Vector<T> &vec) {
  using it = typename GM::Vector<T>::iterator;
  for (it itor = vec.begin(); itor != vec.end(); ++itor) {
    it minItor = itor;
    for (it i = itor + 1; i != vec.end(); ++i) {
      if (*i < *minItor) {
        minItor = i;
      }
    }
    if (minItor != itor) {
      std::iter_swap(itor, minItor);
    }
  }
}

namespace Test {
void ints();
}  // namespace Test