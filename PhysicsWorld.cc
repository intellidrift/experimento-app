#include "PhysicsWorld.h"

PhysicsWorld::PhysicsWorld()
    : mode(VideoMode({3500, 2000}))
    , window(mode, "hello")
    , camera(View(FloatRect({0, 0}, {3500, 2000})))
{

}

void PhysicsWorld::execute()
{
    while (window.isOpen()) {
        tick();
        window.setView(camera);

        while (const optional event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {
                window.close();
            }
        }

        window.clear(Color(80, 80, 80));
        window.display();
    }
}

void PhysicsWorld::tick()
{
    dt = clock.restart().asSeconds();
}