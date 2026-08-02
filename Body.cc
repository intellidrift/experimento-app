#include "Body.h"

Body::Body(const shared_ptr<Shape> &shape, const Vector2f &vel, const float m)
    :  velocity(vel), mass(m), shape(shape) {
        restitutition = 0.7f;
        position = shape->getPosition();
        invMass = m > 0.f ? 1.f / m : 0.f;
}

void Body::update(const float dt) {
    if (invMass == 0.0f) {
        return;
    }
    position += velocity * dt;
    velocity += acceleration;
    shape->setPosition(position);
    acceleration = {0, 0};
}

void Body::applyForce(const Vector2f &force) {
    if (invMass == 0.0f) {
        return;
    }
    acceleration += force * invMass;
}