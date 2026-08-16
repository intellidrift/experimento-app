#ifndef EXPERIMENTO_APP_BODY_H
#define EXPERIMENTO_APP_BODY_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

struct Body {
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;

    float mass;
    float invMass;
    float restitution;

    shared_ptr<CircleShape> shape;

    explicit Body(const shared_ptr<CircleShape> &shape, const Vector2f &vel = {0, 0}, float m = 1);

    virtual ~Body() = default;
    void update(float dt);
    void applyForce(const Vector2f &force);
};

#endif // EXPERIMENTO_APP_BODY_H
