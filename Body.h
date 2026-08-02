#ifndef EXPERIMENTO_APP_BODY_H
#define EXPERIMENTO_APP_BODY_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Body {
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;

    float mass;
    float invMass;
    float restitutition;

    shared_ptr<Shape> shape;

public:
    auto getShape() const { return shape; }

    explicit Body(const shared_ptr<Shape> &shape, const Vector2f &vel = {0, 0}, float m = 1);
    virtual ~Body() = default;
    void update(float dt);
    void applyForce(const Vector2f &force);
};

#endif // EXPERIMENTO_APP_BODY_H
