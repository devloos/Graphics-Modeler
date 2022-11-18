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

  std::string key;
  std::getline(fin, key);
  std::getline(fin, key);
  fin.close();

  if (Parser::parsePasswordHash(key) != hash) {
    return false;
  }

  return true;
}
}  // namespace Login
}  // namespace Utility