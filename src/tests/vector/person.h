#include <iostream>
#include <string>

class Person {
 public:
  Person();

  Person(const std::string &name, int age);

  Person(const Person &rhs);

  Person &operator=(const Person &rhs);

  Person(Person &&rhs);

  Person &operator=(Person &&rhs);

  friend std::ostream &operator<<(std::ostream &os, const Person &obj);

  ~Person() noexcept;

 private:
  std::string name_;
  int age_ = 0;
  int* ptr_ = nullptr;
};