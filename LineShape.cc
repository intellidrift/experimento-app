#include "LineShape.h"

LineShape::LineShape(const Vector2f &start, const Vector2f &end, const float thickness, const Color c) {
    this->thickness = thickness;
    computePosition(start, end);
    setFillColor(c);
}

void LineShape::computePosition(const Vector2f &start, const Vector2f &end) {
    const Vector2f direction = end - start;

    float length = direction.length();

    setSize({length, thickness});
    setOrigin({0, thickness / 2.f});
    setPosition(start);

    const float angle = atan2(direction.y, direction.x) * 180.f / M_PI;

    setRotation(degrees(angle));
}

