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
  using ReferenceType = typename Vector::Type &;

 public:
  Iterator(PointerType it) : it_(it) {}

  Iterator &operator++() {
    assert(it_ != nullptr);
    ++it_;
    return *this;
  }

  Iterator operator++(int) {
    Iterator it = *this;
    ++(*this);
    return it;
  }

  Iterator operator+(const int &count) {
    assert(it_ != nullptr);
    return it_ + count;
  }

  Iterator operator-(const int &count) {
    assert(it_ != nullptr);
    return it_ - count;
  }

  ReferenceType operator*() {
    assert(it_ != nullptr);
    return *it_;
  }

  bool operator==(const Iterator &rhs) {
    return it_ == rhs.it_;
  }

  bool operator!=(const Iterator &rhs) {
    return !(*this == rhs);
  }

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
    return const_iterator(data_ + size_);
  }

  // THIS IS NOT DONE
  iterator insert(iterator it, const T &value) {
    if (size_ >= capacity_) {
      Vector::realloc((capacity_ + 1) + (capacity_ / 2));
    }

    T _tp = *it;
    T __tp = T();
    for (iterator kt = it + 1; kt != end(); kt++) {
      __tp = *(kt - 1);
      _tp = *(kt + 1);
      *kt = _tp;
    }

    *it = value;
    ++size_;
    return it;
  }

  iterator erase(iterator it) {
    assert(it != iterator(data_ + size_));

    if (it == iterator(data_ + (size_ - 1))) {
      return iterator(data_ + (--size_));
    }

    for (iterator kt = it + 1; kt != end(); kt++) {
      *(kt - 1) = *kt;
    }

    --size_;
    return it;
  }

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

  // Reference: https://en.cppreference.com/w/cpp/container/vector/emplace_back
  template <typename... Args>
  T &emplace_back(Args &&... args) {
    if (size_ >= capacity_) {
      Vector::realloc((capacity_ + 1) + (capacity_ / 2));
    }

    return data_[size_++] = T(std::forward<Args>(args)...);
  }

  void push_back(const T &value) {
    if (size_ >= capacity_) {
      Vector::realloc((capacity_ + 1) + (capacity_ / 2));
    }

    data_[size_++] = value;
  }

  std::optional<T> pop_back() {
    if (isEmpty()) {
      return {};
    }

    return data_[--size_];
  }

  void reserve(const int &newCap) {
    if (newCap > capacity_) {
      Vector::realloc(newCap);
    }
  }

 public:
#ifndef NDEBUG
  void print() {
    for (int i = 0; i < size_; i++) {
      std::cout << data_[i] << " ";
    }
    std::cout << "\n";
  }
#endif

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

  void realloc(const int &count) {
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