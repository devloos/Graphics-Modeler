#include "utility.h"

namespace Utility {
namespace Debug {
void log(const std::string &msg) {
  std::cout << msg << "\n";
}
}  // namespace Debug

namespace QT {
void getline(QTextStream &fin, std::string &value) {
  value = fin.readLine().toStdString();
}
}  // namespace QT

namespace Parser {
std::size_t parseHashKey(const std::string &raw) {
  std::string clean = raw.substr(raw.find(":") + 2);
  return std::hash<std::string>{}(clean);
}

void deduceSpecifics(
    std::vector<std::unique_ptr<Shape>> &shapes, QTextStream &fin, const std::string &id,
    const std::string &type, const int &index) {
  std::string cursor;

  QT::getline(fin, cursor);
  cursor = cursor.substr(cursor.find(':') + 2);
  std::stringstream sstream(cursor);

  auto parse = [](std::string &raw) { return raw.substr(raw.find(':') + 2); };

  auto nXY = [&]() {
    while (!sstream.eof()) {
      QPoint point;
      std::string x;
      std::string y;

      std::getline(sstream, x, ',');
      std::getline(sstream, y, ',');

      point.setX(std::stoi(x));
      point.setY(std::stoi(y));
      shapes[index]->pushPoint(point);
    }
  };

  auto setXY = [&]() {
    QPoint point;
    std::string x;
    std::string y;

    std::getline(sstream, x, ',');
    std::getline(sstream, y, ',');

    point.setX(std::stoi(x));
    point.setY(std::stoi(y));
    shapes[index]->pushPoint(point);
  };

  switch (strToShapeType.at(type)) {
    case GM::ShapeType::Line: {
      shapes.push_back(std::make_unique<Line>());
      nXY();
      break;
    }
    case GM::ShapeType::Polyline: {
      shapes.push_back(std::make_unique<Polyline>());
      nXY();
      break;
    }
    case GM::ShapeType::Polygon: {
      shapes.push_back(std::make_unique<Polygon>());
      nXY();
      break;
    }
    case GM::ShapeType::Rectangle: {
      shapes.push_back(std::make_unique<Rectangle>());

      Rectangle* rec = (Rectangle*)(shapes[index].get());

      setXY();

      std::getline(sstream, cursor, ',');
      rec->setLength(std::stoi(cursor));

      std::getline(sstream, cursor);
      rec->setWidth(std::stoi(cursor));

      break;
    }
    case GM::ShapeType::Square: {
      shapes.push_back(std::make_unique<Square>());

      Square* sqr = (Square*)(shapes[index].get());

      setXY();

      std::getline(sstream, cursor);
      sqr->setLength(std::stoi(cursor));

      break;
    }
    case GM::ShapeType::Ellipse: {
      shapes.push_back(std::make_unique<Ellipse>());

      Ellipse* ellipse = (Ellipse*)(shapes[index].get());

      setXY();

      std::getline(sstream, cursor, ',');
      ellipse->setMajorAxis(std::stoi(cursor));

      std::getline(sstream, cursor);
      ellipse->setMinorAxis(std::stoi(cursor));

      break;
    }
    case GM::ShapeType::Circle: {
      shapes.push_back(std::make_unique<Circle>());

      Circle* circle = (Circle*)(shapes[index].get());

      setXY();

      std::getline(sstream, cursor);
      circle->setRadius(std::stoi(cursor));

      break;
    }
    case GM::ShapeType::Text: {
      shapes.push_back(std::make_unique<Text>());

      Text* text = (Text*)(shapes[index].get());

      setXY();

      std::getline(sstream, cursor, ',');
      text->setLength(std::stoi(cursor));

      std::getline(sstream, cursor);
      text->setWidth(std::stoi(cursor));

      QT::getline(fin, cursor);
      cursor = parse(cursor);
      text->setText(cursor.c_str());

      QT::getline(fin, cursor);
      cursor = parse(cursor);
      text->setColor(cursor);

      QT::getline(fin, cursor);
      cursor = parse(cursor);
      text->setTextAlignment(strToTextAlignment.at(cursor));

      QT::getline(fin, cursor);
      cursor = parse(cursor);
      text->setFontSize(std::stoi(cursor));

      QT::getline(fin, cursor);
      cursor = parse(cursor);
      text->setFontFamily(cursor);

      QT::getline(fin, cursor);
      cursor = parse(cursor);
      text->setFontStyle(strToFontStyle.at(cursor));

      QT::getline(fin, cursor);
      cursor = parse(cursor);
      text->setFontWeight(strToFontWeight.at(cursor));

      break;
    }
    default: {
      Debug::log("Shape type invalid.");
      break;
    }
  }

  shapes[index]->setShapeName(type.c_str());
  shapes[index]->setShapeId(std::stoi(id));
}

void deduceFields(
    std::vector<std::unique_ptr<Shape>> &shapes, QTextStream &fin,
    const std::string &type, const int &index) {
  std::string cursor;
  auto parse = [](std::string &raw) { return raw.substr(raw.find(':') + 2); };

  QT::getline(fin, cursor);
  cursor = parse(cursor);
  shapes[index]->setPenColor(QColor(cursor.c_str()));

  QT::getline(fin, cursor);
  cursor = parse(cursor);
  shapes[index]->setPenWidth(std::stoi(cursor));

  QT::getline(fin, cursor);
  cursor = parse(cursor);
  shapes[index]->setPenStyle(strToPenStyle.at(cursor));

  QT::getline(fin, cursor);
  cursor = parse(cursor);
  shapes[index]->setPenCap(strToPenCapStyle.at(cursor));

  QT::getline(fin, cursor);
  cursor = parse(cursor);
  shapes[index]->setPenJoin(strToPenJoinStyle.at(cursor));

  if (strToShapeType.at(type) != GM::ShapeType::Line &&
      strToShapeType.at(type) != GM::ShapeType::Polyline) {
    QBrush brush;

    QT::getline(fin, cursor);
    cursor = parse(cursor);
    brush.setColor(QColor(cursor.c_str()));

    QT::getline(fin, cursor);
    cursor = parse(cursor);
    brush.setStyle(strToBrushStyle.at(cursor));

    shapes[index]->setPenBrush(brush);
  }
}

void parseShapes(std::vector<std::unique_ptr<Shape>> &shapes) {
  QFile file(":shapes.db");

  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    Debug::log("File was not able to be opened.");
    return;
  }

  QTextStream fin(&file);

  std::string id;
  std::string type;
  int index = 0;
  auto parse = [](std::string &raw) { return raw.substr(raw.find(':') + 2); };

  while (!fin.atEnd()) {
    QT::getline(fin, id);
    id = parse(id);

    QT::getline(fin, type);
    type = parse(type);

    // TODO: read text specifics
    deduceSpecifics(shapes, fin, id, type, index);
    if (strToShapeType.at(type) != GM::ShapeType::Text) {
      deduceFields(shapes, fin, type, index);
    }

    fin.skipWhiteSpace();

    ++index;
  }

  file.close();
}
}  // namespace Parser

namespace Login {
bool isValid(const std::size_t &hash) {
  QFile file(":users.db");

  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    Debug::log("File was not able to be opened.");
    return false;
  }

  QTextStream in(&file);

  in.readLine();
  std::string key = in.readLine().toStdString();

  file.close();

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
