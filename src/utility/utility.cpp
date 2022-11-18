#include "utility.h"

namespace Utility {
namespace Login {
bool isValid(const std::size_t &hash) {
  std::string key = "scrumKingsbabyCakes123";

  if (std::hash<std::string>{}(key) != hash) {
    return false;
  }

  return true;
}
}  // namespace Login
}  // namespace Utility