#include "person.h"

Person::Person() {
  ptr_ = new int[5];
}

Person::Person(const std::string &name, int age)
    : name_(name), age_(age), ptr_(new int[5]) {}

Person::Person(const Person &rhs) {
  *this = rhs;
}

Person &Person::operator=(const Person &rhs) {
  if (this == &rhs) {
    return *this;
  }

  delete[] ptr_;

  name_ = rhs.name_;
  age_ = rhs.age_;
  ptr_ = new int[5];
  for (int i = 0; i < 5; i++) {
    ptr_[i] = rhs.ptr_[i];
  }

  return *this;
}

Person::Person(Person &&rhs) : name_(rhs.name_), age_(rhs.age_) {
  ptr_ = rhs.ptr_;
  rhs.ptr_ = nullptr;
}

Person &Person::operator=(Person &&rhs) {
  delete[] ptr_;

  name_ = rhs.name_;
  age_ = rhs.age_;
  ptr_ = rhs.ptr_;
  rhs.ptr_ = nullptr;
  return *this;
}

Person::~Person() noexcept {
  std::cout << "DESTRUCTOR\n";
  delete[] ptr_;
}

std::ostream &operator<<(std::ostream &os, const Person &obj) {
  os << obj.name_ << " " << obj.age_ << "\n";
  return os;
}