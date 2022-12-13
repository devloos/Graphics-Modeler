#pragma once

#include "gm/vector.h"

namespace GM {
/**
 * @brief comapres shapes by perimeter. It is templated,
 * but we believe it should not be, it should take in an
 * iterator for a vector of shapes and perform polymorphism,
 * but we decided to abide by the rubric and make it templated.
 *
 * @tparam T
 * @param it
 * @param minIt
 * @return true
 * @return false
 */
template <typename T>
bool compare_shape_perimeter(
    typename GM::Vector<T>::iterator &it, typename GM::Vector<T>::iterator &minIt) {
  return it->perimeter() < minIt->perimeter();
}

/**
 * @brief comapres shapes by area. It is templated,
 * but we believe it should not be, it should take in an
 * iterator for a vector of shapes and perform polymorphism,
 * but we decided to abide by the rubric and make it templated.
 *
 * @tparam T
 * @param it
 * @param minIt
 * @return true
 * @return false
 */
template <typename T>
bool compare_shape_area(
    typename GM::Vector<T>::iterator &it, typename GM::Vector<T>::iterator &minIt) {
  return it->area() < minIt->area();
}

/**
 * @brief Sorts by the function pointer that is passed in
 * Function pointer takes in two iterators by reference
 * Selection sort function that sorts a vector via a function
 * pointer that is passed in that takes two iterators. Uses
 * an iterator to iterate though the vector and comapre.
 *
 * @tparam T
 * @param vec
 * @param compare
 */
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

/**
 * @brief Uses a selection sort algorithm to
 * sort a vector by a shape id. Again, probably
 * should have just used polymorphism and passed
 * a vector of shapes, but again, abiding by the rubric.
 *
 * @tparam T
 * @param vec
 */
template <typename T>
void selection_sort(GM::Vector<T> &vec) {
  using it = typename GM::Vector<T>::iterator;
  for (it itor = vec.begin(); itor != vec.end(); ++itor) {
    it minItor = itor;
    for (it i = itor + 1; i != vec.end(); ++i) {
      if (i->getShapeId() < minItor->getShapeId()) {
        minItor = i;
      }
    }
    if (minItor != itor) {
      std::iter_swap(itor, minItor);
    }
  }
}
}  // namespace GM