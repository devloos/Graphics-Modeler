#pragma once
#include <cassert>
#include <cstring>
#include <iostream>
#include <optional>
#include <vector>

namespace GM {
template <typename Vector>
class Iterator {
 private:
  using PointerType = typename Vector::Type*;

 public:
  Iterator(PointerType it) : it_(it) {}

 private:
  PointerType it_ = nullptr;
};

template <typename T>
class Vector {
 public:
  using iterator = Iterator<Vector<T>>;
  using const_iterator = const Iterator<Vector<T>>;
  using Type = T;

 public:
  iterator begin() {
    return iterator(data_);
  }

  iterator end() {
    return iterator(data_ + size_);
  }

  const_iterator begin() const {
    return const_iterator(data_);
  }

  const_iterator end() const {
    return const_iterator(data_);
  }

  iterator insert(iterator it, const T &data);
  iterator erase(iterator it);

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
      deepcpy(block, data_, count);
    } else {
      deepcpy(block, data_, size_);
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

#ifndef NDEBUG
  void print() {
    for (int i = 0; i < size_; i++) {
      std::cout << data_[i] << " ";
    }
    std::cout << "\n";
  }
#endif

  void push_back(const T &value) {
    if (size_ >= capacity_) {
      reAlloc((capacity_ + 1) + (capacity_ / 2));
    }

    data_[size_++] = value;
  }

  std::optional<T> pop_back() {
    if (isEmpty()) {
      return {};
    }

    return data[--size_];
  }

  void reserve(const int &newCap) {
    if (newCap > capacity_) {
      reAlloc(newCap);
    }
  }

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

  void deepcpy(T* dest, const T* src, const int &size) {
    for (int i = 0; i < size; i++) {
      dest[i] = src[i];
    }
  }

  void reAlloc(const int &count) {
    assert(count > capacity_);

    T* block = new T[count];
    deepcpy(block, data_, size_);

    capacity_ = count;
    delete[] data_;
    data_ = block;
    block = nullptr;
  }

 private:
  T* data_ = nullptr;
  int capacity_ = 0;
  int size_ = 0;
};
}  // namespace GM