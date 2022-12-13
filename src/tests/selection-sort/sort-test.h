#pragma once

#include "gm/selection-sort.h"
#include "gm/vector.h"
#include "models/free-form/circle.h"

namespace Test {

template <typename T>
void print(const GM::Vector<T> &vec) {
  for (auto itor = vec.begin(); itor != vec.end(); itor++) {
    std::cout << *itor << " ";
  }
  std::cout << '\n';
}

void sortingShapeByPer();
void sortingShapeById();
}  // namespace Test