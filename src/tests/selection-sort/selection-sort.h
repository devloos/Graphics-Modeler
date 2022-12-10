#pragma once

#include "gm/vector.h"
#include "models/free-form/circle.h"

template <typename T>
bool compare_shape_perimeter(
    typename GM::Vector<T>::iterator &it, typename GM::Vector<T>::iterator &minIt) {
  return (*it).perimeter() < (*minIt).perimeter();
}

template <typename T>
bool compare_shape_area(
    typename GM::Vector<T>::iterator &it, typename GM::Vector<T>::iterator &minIt) {
  return (*it).area() < (*minIt).area();
}

// sorts by function pointer
template <typename T>
void selection_sort(
    GM::Vector<T> &vec,
    bool (*compare)(
        typename GM::Vector<T>::iterator &, typename GM::Vector<T>::iterator &)) {
  using it = typename GM::Vector<T>::iterator;
  for (it itor = vec.begin(); itor != vec.end(); ++itor) {
    it minItor = itor;
    for (it i = itor + 1; i != vec.end(); ++i) {
      if (compare(i, minItor)) {
        minItor = i;
      }
    }
    if (minItor != itor) {
      std::iter_swap(itor, minItor);
    }
  }
}

// Sorts by shape id
template <typename T>
void selection_sort(GM::Vector<T> &vec) {
  using it = typename GM::Vector<T>::iterator;
  for (it itor = vec.begin(); itor != vec.end(); ++itor) {
    it minItor = itor;
    for (it i = itor + 1; i != vec.end(); ++i) {
      if ((*i).getShapeId() < (*minItor).getShapeId()) {
        minItor = i;
      }
    }
    if (minItor != itor) {
      std::iter_swap(itor, minItor);
    }
  }
}

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