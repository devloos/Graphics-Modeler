#pragma once
#include "gm/vector.h"

template <typename T>
void selection_sort(GM::Vector<T> &vec) {
  using it = typename GM::Vector<T>::iterator;
  for (it itor = vec.begin(); itor != vec.end(); ++itor) {
    it currentMinimumItor = itor;
    for (it i = itor + 1; i != vec.end(); ++i) {
      if (*i < *currentMinimumItor) {
        currentMinimumItor = i;
      }
    }
    if (currentMinimumItor != itor) {
      std::iter_swap(itor, currentMinimumItor);
    }
  }
}

namespace Test {
void ints();
}  // namespace Test