#ifndef EXPERIMENTO_APP_PHYSICSWORLD_H
#define EXPERIMENTO_APP_PHYSICSWORLD_H

#include "Body.h"

#include <iostream>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;
using namespace std;

class PhysicsWorld {
    VideoMode mode;
    RenderWindow window;
    Clock clock;
    View camera;
    float dt = 0;

    vector<shared_ptr<Body>> bodies;

    void tick();
    void tickBodies() const;
    void resolveCollision() const;
    void drawGrid();
public:
    PhysicsWorld();
    void execute();
    virtual ~PhysicsWorld() = default;
};

#endif // EXPERIMENTO_APP_PHYSICSWORLD_H
