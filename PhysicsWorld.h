#ifndef EXPERIMENTO_APP_PHYSICALWORLD_H
#define EXPERIMENTO_APP_PHYSICALWORLD_H

#include <iostream>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


using namespace sf;
using namespace std;

class PhysicsWorld
{
    VideoMode mode;
    RenderWindow window;

    Clock clock;
    View camera;

    float dt = 0;

    vector<unique_ptr<Shape>> bodies;

    void tick();
public:
    PhysicsWorld();
    void execute();
    virtual ~PhysicsWorld() = default;
};

#endif //EXPERIMENTO_APP_PHYSICALWORLD_H
