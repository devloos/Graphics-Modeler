#pragma once
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

namespace GM {
template <typename T>
class Vector {
 private:
  T* data_ = nullptr;
  int capacity_ = 0;
  int size_ = 0;

 public:
  Vector() {}

  explicit Vector(const int &capacity) {
    assert(capacity > 0);
    capacity_ = capacity;
    data_ = new T[capacity];
  }

  Vector(const Vector &rhs) : capacity_(rhs.capacity_), size_(rhs.size_) {
    veccpy(rhs);
  }

  Vector &operator=(const Vector &rhs) {
    veccpy(rhs);
    return *this;
  }

  Vector(Vector &&rhs) : capacity_(rhs.capacity_), size_(rhs.size_) {
    vecmove(rhs);
  }

  Vector &operator=(Vector &&rhs) {
    if (this == &rhs) {
      return *this;
    }
    vecmove(rhs);
    return *this;
  }

  ~Vector() noexcept {
    size_ = 0;
    capacity_ = 0;
    delete[] data_;
    data_ = nullptr;
  }

  T &operator[](const int &index) {
    assert(index >= 0 && index < size_);
    return data_[index];
  }

  const T &operator[](const int &index) const {
    assert(index >= 0 && index < size_);
    return data_[index];
  }

  int size() const {
    return size_;
  }

  int capacity() const {
    return capacity_;
  }

  void resize(const int &count, const T &value = T()) {
    assert(count > 0);
    T* block = new T[count];

    if (count <= size_) {
      deepCpy(block, data_, count);
    } else {
      deepCpy(block, data_, size_);
      for (int i = size_; i < count; i++) {
        block[i] = value;
      }
    }

    size_ = count;
    capacity_ = count;
    delete[] data_;
    data_ = block;
    block = nullptr;
  }

  bool isEmpty() {
    return size_ == 0;
  }

  void print() {
    for (int i = 0; i < size_; i++) {
      std::cout << data_[i] << " ";
    }
    std::cout << "\n";
  }

  void push_back(const T &value) {
    if (size_ >= capacity_) {
      reAlloc((capacity_ + 1) + (capacity_ / 2));
    }

    data_[size_++] = value;
  }

  void reserve(const int &newCap) {
    if (newCap > capacity_) {
      reAlloc(newCap);
    }
  }

  typedef T* iterator;
  typedef const T* const_iterator;

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  iterator insert(iterator it, const T &data);
  iterator erase(iterator it);

 private:
  void veccpy(const Vector &src) {
    assert(src.capacity_ > 0 || src.size_ > 0);

    size_ = src.size_;
    capacity_ = src.capacity_;
    data_ = new T[capacity_];

    for (int i = 0; i < size_; i++) {
      data_[i] = src.data_[i];
    }
  }

  void vecmove(Vector &&src) {
    size_ = src.size_;
    capacity_ = src.capacity_;
    data_ = src.data_;

    // Clean Up
    src.size_ = 0;
    src.capacity_ = 0;
    src.data_ = nullptr;
  }

  void deepCpy(T* dest, const T* src, const int &size) {
    for (int i = 0; i < size; i++) {
      dest[i] = src[i];
    }
  }

  void reAlloc(const int &count) {
    assert(count > capacity_);

    T* block = new T[count];
    deepCpy(block, data_, size_);

    capacity_ = count;
    delete[] data_;
    data_ = block;
    block = nullptr;
  }
};
}  // namespace GM