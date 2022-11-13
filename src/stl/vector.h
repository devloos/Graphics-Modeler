#pragma once

namespace GM {
template <typename T>
class Vector {
 private:
  T* data_ = nullptr;
  int capacity_ = 0;
  int size_ = 0;

 public:
  Vector();
  explicit Vector(const int &capacity);

  // Rule of 5
  Vector(const Vector &rhs);
  Vector &operator=(const Vector &rhs);
  Vector(Vector &&rhs);
  Vector &operator=(Vector &&rhs);
  ~Vector() noexcept;

  T &operator[](const int &index);
  const T &operator[](const int &index);

  int size() const;
  int capacity() const;

  void resize(const int &newSize = size_);
  void push_back(const T &data);
  void reserve(const int &allocSize);

  typedef T* iterator;
  typedef const T* const_iterator;

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  iterator insert(iterator it, const T &data);
  iterator erase(iterator it);
};
}  // namespace GM