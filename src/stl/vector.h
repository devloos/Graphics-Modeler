#pragma once

namespace GM {
static const int DEFAULT = -1;

template <typename T>
class Vector {
 private:
  T* data_ = nullptr;
  int capacity_ = 0;
  int size_ = 0;

 public:
  Vector() {}
  explicit Vector(const int &capacity) {
    assert(capacity <= 0);
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

  T &operator[](const int &index);
  const T &operator[](const int &index) const;

  int size() const;
  int capacity() const;

  void resize(const int &newSize = DEFAULT);
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

 private:
  void veccpy(const Vector &src) {
    assert(src.capacity_ <= 0 || src.size_ <= 0);
    size_ = src.size_;
    capacity_ = src.capacity_;
    data_ = new T[capacity_];
    memcpy(data_, src.data_, sizeof(T) * src.size_);
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
};
}  // namespace GM