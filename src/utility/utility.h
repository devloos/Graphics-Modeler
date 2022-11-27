#pragma once
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <locale>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

#include "gm/gm.h"
#include "gm/vector.h"
#include "shapes.h"

namespace Utility {
static const std::filesystem::path DB_PATH = std::filesystem::absolute("../db");

static const std::unordered_map<std::string, Qt::PenStyle> strToPenStyle(
    {{"NoPen", Qt::PenStyle::NoPen},
     {"SolidLine", Qt::PenStyle::SolidLine},
     {"DashLine", Qt::PenStyle::DashLine},
     {"DotLine", Qt::PenStyle::DotLine},
     {"DashDotLine", Qt::PenStyle::DashDotLine},
     {"DashDotDotLine", Qt::PenStyle::DashDotDotLine},
     {"CustomDashLine", Qt::PenStyle::CustomDashLine}});

static const std::unordered_map<std::string, Qt::PenCapStyle> strToPenCapStyle(
    {{"FlatCap", Qt::PenCapStyle::FlatCap},
     {"SquareCap", Qt::PenCapStyle::SquareCap},
     {"RoundCap", Qt::PenCapStyle::RoundCap},
     {"MPenCapStyle", Qt::PenCapStyle::MPenCapStyle}});

static const std::unordered_map<std::string, Qt::PenJoinStyle> strToPenJoinStyle(
    {{"MiterJoin", Qt::PenJoinStyle::MiterJoin},
     {"BevelJoin", Qt::PenJoinStyle::BevelJoin},
     {"RoundJoin", Qt::PenJoinStyle::RoundJoin},
     {"SvgMiterJoin", Qt::PenJoinStyle::SvgMiterJoin},
     {"MPenJoinStyle", Qt::PenJoinStyle::MPenJoinStyle}});

static const std::unordered_map<std::string, Qt::BrushStyle> strToBrushStyle(
    {{"NoBrush", Qt::BrushStyle::NoBrush},
     {"SolidPattern", Qt::BrushStyle::SolidPattern},
     {"Dense1Pattern", Qt::BrushStyle::Dense1Pattern},
     {"Dense2Pattern", Qt::BrushStyle::Dense2Pattern},
     {"Dense3Pattern", Qt::BrushStyle::Dense3Pattern},
     {"Dense4Pattern", Qt::BrushStyle::Dense4Pattern},
     {"Dense5Pattern", Qt::BrushStyle::Dense5Pattern},
     {"Dense6Pattern", Qt::BrushStyle::Dense6Pattern},
     {"Dense7Pattern", Qt::BrushStyle::Dense7Pattern},
     {"HorPattern", Qt::BrushStyle::HorPattern},
     {"VerPattern", Qt::BrushStyle::VerPattern},
     {"CrossPattern", Qt::BrushStyle::CrossPattern},
     {"BDiagPattern", Qt::BrushStyle::BDiagPattern},
     {"FDiagPattern", Qt::BrushStyle::FDiagPattern},
     {"DiagCrossPattern", Qt::BrushStyle::DiagCrossPattern},
     {"LinearGradientPattern", Qt::BrushStyle::LinearGradientPattern},
     {"RadialGradientPattern", Qt::BrushStyle::RadialGradientPattern},
     {"ConicalGradientPattern", Qt::BrushStyle::ConicalGradientPattern},
     {"TexturePattern", Qt::BrushStyle::TexturePattern}});

static const std::unordered_map<std::string, GM::ShapeType> strToShapeType(
    {{"Line", GM::ShapeType::Line},
     {"Polyline", GM::ShapeType::Polyline},
     {"Polygon", GM::ShapeType::Polygon},
     {"Rectangle", GM::ShapeType::Rectangle},
     {"Square", GM::ShapeType::Square},
     {"Ellipse", GM::ShapeType::Ellipse},
     {"Circle", GM::ShapeType::Circle}});

namespace Debug {
void log(const std::string &msg);
}  // namespace Debug

namespace Parser {
std::size_t parseHashKey(const std::string &raw);
void parseShapes(std::vector<std::unique_ptr<Shape>> &shapes);
void deduceSpecifics(
    std::vector<std::unique_ptr<Shape>> &shapes, std::fstream &fin, const std::string &id,
    const std::string &type, const int &index);
void deduceFields(
    std::vector<std::unique_ptr<Shape>> &shapes, std::fstream &fin,
    const std::string &type, const int &index);
}  // namespace Parser

namespace Login {
bool isValid(const std::size_t &hash);
}
}  // namespace Utility
