#pragma once
#include <cassert>
#include <cstring>
#include <iostream>
#include <optional>
#include <vector>

namespace GM {

/**
 * @brief Templated iterator class that
 * takes in a vector
 *
 * @tparam Vector
 */
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

  int operator+(const Iterator &rhs) {
    return it_ + rhs.it_;
  }

  int operator-(const Iterator &rhs) {
    return it_ - rhs.it_;
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

  PointerType operator->() {
    return it_;
  }

  const PointerType operator->() const {
    return it_;
  }

 private:
  PointerType it_ = nullptr;
};

/**
 * @brief Custom templated vector class
 *
 * @tparam T
 */
template <typename T>
class Vector {
 public:
  using iterator = Iterator<Vector<T>>;
  using const_iterator = const Iterator<Vector<T>>;
  using Type = T;

 public:
  /**
   * @brief Returns an iterator pointing to the beginning
   * of the vector
   *
   * @return iterator
   */
  iterator begin() {
    return iterator(data_);
  }

  /**
   * @brief Returns an iterator pointing to the end
   * of the vector
   *
   * @return iterator
   */
  iterator end() {
    return iterator(data_ + size_);
  }

  /**
   * @brief Returns a const iterator pointing to the
   * beginning of the vector
   *
   * @return iterator
   */
  const_iterator begin() const {
    return const_iterator(data_);
  }

  /**
   * @brief Returns a const iterator pointing to the end
   * of the vector
   *
   * @return iterator
   */
  const_iterator end() const {
    return const_iterator(data_ + size_);
  }

  /**
   * @brief The vector is extended by inserting new elements
   * before the element at the specified position (iterator it),
   * increasing the container size by the number of elements
   * inserted
   *
   * @param it
   * @param value
   * @return iterator
   */
  iterator insert(iterator it, const T &value) {
    if (size_ == capacity_) {
      int diff = it - begin();
      Vector::realloc((capacity_ + 1) + (capacity_ / 2));
      it = iterator(data_ + diff);
    }

    if (it == end()) {
      *it = value;
      size_++;
      return it;
    }

    T _tp = *it;
    T __tp = T();
    ++size_;
    for (iterator kt = it + 1; kt != end(); kt++) {
      __tp = *kt;
      *kt = _tp;
      _tp = __tp;
    }

    *it = value;
    return it;
  }

  /**
   * @brief removes a single element(it) from the vector
   *
   * @param it
   * @return iterator
   */
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
  /**
   * @brief Constructs an empty container, with no elements.
   *
   */
  Vector() {}

  /**
   * @brief Constructs a container with (capacity) number
   * of elements.
   *
   * @param capacity
   */
  explicit Vector(const int &capacity) {
    assert(capacity > 0);
    capacity_ = capacity;
    data_ = new T[capacity];
  }

  /**
   * @brief Copy Constructor, constructs a container with a copy of
   * each of the elements in rhs, in the same order.
   *
   * @param rhs
   */
  Vector(const Vector &rhs) : capacity_(rhs.capacity_), size_(rhs.size_) {
    veccpy(rhs);
  }

  /**
   * @brief Copy assignment: copies all the elements from rhs into
   * the container (with rhs preserving its contents).
   *
   * @param rhs
   * @return Vector&
   */
  Vector &operator=(const Vector &rhs) {
    veccpy(rhs);
    return *this;
  }

  /**
   * @brief Move constructor: Constructs a container that aquires the
   * elements of rhs.
   *
   * @param rhs
   */
  Vector(Vector &&rhs) : capacity_(rhs.capacity_), size_(rhs.size_) {
    vecmove(rhs);
  }

  /**
   * @brief Move assignment - moves the elements of rhs into the container.
   *
   * @param rhs
   * @return Vector&
   */
  Vector &operator=(Vector &&rhs) {
    if (this == &rhs) {
      return *this;
    }
    vecmove(rhs);
    return *this;
  }

  /**
   * @brief Destroy the Vector object, deallocates all of the storage capcity.
   *
   */
  ~Vector() noexcept {
    size_ = 0;
    capacity_ = 0;
    delete[] data_;
    data_ = nullptr;
  }

  /**
   * @brief Index (subscript) operator - returns a reference to the element
   * at position (index) in the vector container.
   *
   * @param index
   * @return T&
   */
  T &operator[](const int &index) {
    assert(index >= 0 && index < size_);
    return data_[index];
  }

  /**
   * @brief Const Index (subscript) operator - returns a reference to the element
   * at position (index) in the vector container.
   *
   * @param index
   * @return const T&
   */
  const T &operator[](const int &index) const {
    assert(index >= 0 && index < size_);
    return data_[index];
  }

  T &at(const int &index) {
    assert(index >= 0 && index < size_);
    return data_[index];
  }

  /**
   * @brief Returns the number of elements in the vector.
   *
   * @return int
   */
  int size() const {
    return size_;
  }

  /**
   * @brief Returns the size of the storage space currently
   * allocated for the vector.
   *
   * @return int
   */
  int capacity() const {
    return capacity_;
  }

  /**
   * @brief Resizes the container so that it contains (count)
   * elements.
   *
   * @param count
   * @param value
   */
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

  /**
   * @brief Returns whether the vector is empty
   * (i.e. whether its size is  0).
   *
   * @return true
   * @return false
   */
  bool isEmpty() {
    return size_ == 0;
  }

  /**
   * @brief Inserts a new element at the end of the vector, right after
   * its current last element. This new element is constructed in place using
   * args as the arguments for its constructor.
   *
   * This increases the contaner size by one which causes a realloc IF the new
   * vector size is greater than the current vector capacity.
   *
   * The element is constructed in-place by allocating with args forwarded
   *
   * @tparam Args
   * @param args
   * @return T&
   */
  // Reference: https://en.cppreference.com/w/cpp/container/vector/emplace_back
  template <typename... Args>
  T &emplace_back(Args &&... args) {
    if (size_ >= capacity_) {
      Vector::realloc((capacity_ + 1) + (capacity_ / 2));
    }

    return data_[size_++] = T(std::forward<Args>(args)...);
  }

  /**
   * @brief Adds a new element at the end of the vector,
   * after its current last element. The content of value
   * is copied (or moved) to the new element.
   *
   * @param value
   */
  void push_back(const T &value) {
    if (size_ >= capacity_) {
      Vector::realloc((capacity_ + 1) + (capacity_ / 2));
    }

    data_[size_++] = value;
  }

  void push_back(T &&value) {
    if (size_ >= capacity_) {
      Vector::realloc((capacity_ + 1) + (capacity_ / 2));
    }

    data_[size_++] = std::move(value);
  }

  /**
   * @brief Removes the last element in the vector,
   * effectively reducing the container size by one.
   *
   * @return std::optional<T>
   */
  std::optional<T> pop_back() {
    if (isEmpty()) {
      return {};
    }

    return data_[--size_];
  }

  /**
   * @brief Requests that the vector capacity be at least
   * enough to contain newCap elements.
   *
   * @param newCap
   */
  void reserve(const int &newCap) {
    if (newCap > capacity_) {
      Vector::realloc(newCap);
    }
  }

 public:
#ifndef NDEBUG
  /**
   * @brief TESTING FUNCTION
   * prints all the elements of the vector
   *
   */
  void print() {
    for (int i = 0; i < size_; i++) {
      std::cout << data_[i] << " ";
    }
    std::cout << "\n";
  }
#endif

 private:
  /**
   * @brief Copies the the src vector
   *
   * @param src
   */
  void veccpy(const Vector &src) {
    size_ = src.size_;
    capacity_ = src.capacity_;
    data_ = new T[capacity_];

    for (int i = 0; i < size_; i++) {
      data_[i] = src.data_[i];
    }
  }

  /**
   * @brief Moves the src vector
   *
   * @param src
   */
  void vecmove(Vector &&src) {
    size_ = src.size_;
    capacity_ = src.capacity_;
    data_ = src.data_;

    // Clean Up
    src.size_ = 0;
    src.capacity_ = 0;
    src.data_ = nullptr;
  }

  /**
   * @brief (helper function) copies src to dest
   *
   * @param dest
   * @param src
   * @param size
   */
  void deepcpy(T* dest, const T* src, const int &size) {
    for (int i = 0; i < size; i++) {
      dest[i] = std::move(src[i]);
    }
  }

  /**
   * @brief allocates memory
   *
   * @param count
   */
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