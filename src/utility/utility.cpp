#include "utility.h"

namespace Utility {
namespace Debug {
void log(const std::string &msg) {
  std::cout << msg << "\n";
}
}  // namespace Debug

namespace Parser {
std::size_t parseHashKey(const std::string &raw) {
  std::string clean = raw.substr(raw.find(":") + 2);
  return std::hash<std::string>{}(clean);
}

void parseShapes(GM::Vector<Shape> &shapes) {
  std::fstream fin("../src/db/shapes.db", std::ios::in);

  if (!fin.is_open()) {
    Debug::log("File was not able to be opened.");
    return;
  }
  Qt::PenCapStyle style = strToPenCapStyle.at("FlatCap");
}
}  // namespace Parser

namespace Login {
bool isValid(const std::size_t &hash) {
  std::fstream fin("../src/db/users.db", std::ios::in);

  if (!fin.is_open()) {
    Debug::log("File was not able to be opened.");
    return false;
  }

  std::string key;
  for (int i = 0; i < 2; i++) {
    if (!fin.eof()) {
      std::getline(fin, key);
    }
  }
  fin.close();

  try {
    if (Parser::parseHashKey(key) != hash) {
      return false;
    }
  } catch (const std::invalid_argument &e) {
    Debug::log(e.what() + std::string("."));
    return false;
  }

  return true;
}
}  // namespace Login
}  // namespace Utility