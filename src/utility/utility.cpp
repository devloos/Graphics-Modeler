#include "utility.h"

namespace Utility {
namespace Debug {
void log(const std::string &msg) {
  std::cout << msg << "\n";
}
}  // namespace Debug

namespace Model {}

namespace Parser {
std::size_t parsePasswordHash(const std::string &raw) {
  std::string clean = raw.substr(raw.find(":") + 2);
  return std::stoul(clean);
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
    if (Parser::parsePasswordHash(key) != hash) {
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