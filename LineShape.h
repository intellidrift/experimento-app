#ifndef EXPERIMENTO_APP_LINESHAPE_H
#define EXPERIMENTO_APP_LINESHAPE_H

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;
using namespace std;

class LineShape : public RectangleShape {
    float thickness;
public:
    LineShape(const Vector2f &start, const Vector2f &end, float thickness, Color c = Color::Black);
    void computePosition(const Vector2f &start, const Vector2f &end);
};

#endif // EXPERIMENTO_APP_LINESHAPE_H
