#include "LineShape.h"

LineShape::LineShape(const Vector2f &start, const Vector2f &end, float thickness, const Color c) {
    const Vector2f direction = end - start;

    float length = direction.length();
    shape.setSize({length, thickness});
    shape.setOrigin({0, thickness / 2.f});
    shape.setPosition(start);
    shape.setFillColor(c);

    const float angle = atan2(direction.y, direction.x) * 180.f / M_PI;

    shape.setRotation(degrees(angle));
}

void LineShape::draw(RenderTarget &target, RenderStates states) const {
    target.draw(shape);
}

