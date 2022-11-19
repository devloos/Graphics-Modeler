#pragma once
#include <cstddef>
#include <fstream>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>

namespace Utility {
namespace Debug {
void log(const std::string &msg);
}  // namespace Debug
namespace Model {
class Exception {};
}  // namespace Model
namespace Parser {
std::size_t parsePasswordHash(const std::string &raw);
}
namespace Login {
bool isValid(const std::size_t &hash);
}
}  // namespace Utility
