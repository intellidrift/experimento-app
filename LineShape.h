#ifndef EXPERIMENTO_APP_LINESHAPE_H
#define EXPERIMENTO_APP_LINESHAPE_H

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;
using namespace std;

class LineShape : public RectangleShape {

    RectangleShape shape;

    void draw(RenderTarget &target, RenderStates states) const override;
public:
    LineShape(const Vector2f &start, const Vector2f &end, float thickness, Color c);
};

#endif // EXPERIMENTO_APP_LINESHAPE_H
