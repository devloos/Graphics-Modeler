#include "utility.h"

namespace Utility {
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
    std::cout << "File was not able to be opened.\n";
    return false;
  }

  std::string key;
  std::getline(fin, key);
  std::getline(fin, key);
  fin.close();

  try {
    if (Parser::parsePasswordHash(key) != hash) {
      return false;
    }
  } catch (const std::invalid_argument &e) {
    std::cout << e.what() + std::string(".\n");
    return false;
  }

  return true;
}
}  // namespace Login
}  // namespace Utility