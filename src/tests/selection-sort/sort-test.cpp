#include "selection-sort.h"

namespace Test {
template <typename T>
void print(const GM::Vector<T> &vec) {
  for (auto itor = vec.begin(); itor != vec.end(); itor++) {
    std::cout << *itor << " ";
  }
  std::cout << '\n';
}

void ints() {
  GM::Vector<int> test;
  test.push_back(1);
  test.push_back(2);
  test.push_back(501);
  test.push_back(69);
  test.push_back(48);
  test.push_back(153629);
  test.push_back(6666);
  std::cout << "Unsorted Vector: ";
  print(test);
  selection_sort(test);
  std::cout << "Sorted Vector: ";
  print(test);
}
}  // namespace Test