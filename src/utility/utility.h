#pragma once
#include <cstddef>
#include <fstream>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "gm/vector.h"
#include "models/shape.h"

namespace Utility {
const std::unordered_map<const char*, Qt::PenStyle> strToPenStyle(
    {{"NoPen", Qt::PenStyle::NoPen},
     {"SolidLine", Qt::PenStyle::SolidLine},
     {"DashLine", Qt::PenStyle::DashLine},
     {"DotLine", Qt::PenStyle::DotLine},
     {"DashDotLine", Qt::PenStyle::DashDotLine},
     {"DashDotDotLine", Qt::PenStyle::DashDotDotLine},
     {"CustomDashLine", Qt::PenStyle::CustomDashLine}});

const std::unordered_map<const char*, Qt::PenCapStyle> strToPenCapStyle(
    {{"FlatCap", Qt::PenCapStyle::FlatCap},
     {"SquareCap", Qt::PenCapStyle::SquareCap},
     {"RoundCap", Qt::PenCapStyle::RoundCap},
     {"MPenCapStyle", Qt::PenCapStyle::MPenCapStyle}});

const std::unordered_map<const char*, Qt::PenJoinStyle> strToPenJoinStyle(
    {{"MiterJoin", Qt::PenJoinStyle::MiterJoin},
     {"BevelJoin", Qt::PenJoinStyle::BevelJoin},
     {"RoundJoin", Qt::PenJoinStyle::RoundJoin},
     {"SvgMiterJoin", Qt::PenJoinStyle::SvgMiterJoin},
     {"MPenJoinStyle", Qt::PenJoinStyle::MPenJoinStyle}});

namespace Debug {
void log(const std::string &msg);
}  // namespace Debug

namespace Parser {
std::size_t parseHashKey(const std::string &raw);
void parseShapes(GM::Vector<Shape> &shapes);
}  // namespace Parser

namespace Login {
bool isValid(const std::size_t &hash);
}
}  // namespace Utility
