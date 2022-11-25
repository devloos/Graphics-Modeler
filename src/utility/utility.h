#pragma once
#include <cstddef>
#include <fstream>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>

#include "gm/vector.h"
#include "models/shape.h"

namespace Utility {
namespace Debug {
void log(const std::string &msg);
}  // namespace Debug

namespace Model {
class Exception {};
}  // namespace Model

namespace Parser {
std::size_t parseHashKey(const std::string &raw);
void parseShapes(GM::Vector<Shape> &shapes);
}  // namespace Parser

namespace Login {
bool isValid(const std::size_t &hash);
}
}  // namespace Utility
