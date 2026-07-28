#include "PhysicsWorld.h"

PhysicsWorld::PhysicsWorld()
    : mode(VideoMode({3500, 2000}))
    , window(mode, "hello")
    , camera(View(FloatRect({0, 0}, {3500, 2000})))
{
    CircleShape circle(50);
    circle.setFillColor(Color::Cyan);
    circle.setPosition({1000, 500});
    bodies.push_back(make_unique<CircleShape>(circle));

    CircleShape circle1(50);
    circle1.setFillColor(Color::Cyan);
    circle1.setPosition({2500, 500});
    bodies.push_back(make_unique<CircleShape>(circle1));
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

            if (const auto* keyPressed = event->getIf<Event::KeyPressed>()) {
                if (keyPressed->code == Keyboard::Key::Escape) {
                    window.close();
                }
            }
        }

        window.clear(Color(80, 80, 80));

        for (const auto& body : bodies) {
            window.draw(*body);
        }

        window.display();
    }
}

void PhysicsWorld::tick()
{
    dt = clock.restart().asSeconds();
}