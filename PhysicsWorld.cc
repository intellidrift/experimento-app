#include "PhysicsWorld.h"

PhysicsWorld::PhysicsWorld()
    : mode(VideoMode({3500, 2000})), window(mode, "hello"),
      camera(View(FloatRect({0, 0}, {3500, 2000}))) {

    CircleShape circle(50);
    circle.setFillColor(Color::Cyan);
    circle.setPosition({1000, 500});

    Body b1(make_shared<CircleShape>(circle), {20, 0}, 1);
    bodies.push_back(make_shared<Body>(b1));

    CircleShape circle1(50);
    circle1.setFillColor(Color::Cyan);
    circle1.setPosition({2500, 500});

    Body b2(make_shared<CircleShape>(circle1), {-20, 0}, 1);
    bodies.push_back(make_shared<Body>(b2));
}

void PhysicsWorld::execute() {
    while (window.isOpen()) {
        tick();
        window.setView(camera);

        while (const auto event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {
                window.close();
            }

            if (const auto *keyPressed = event->getIf<Event::KeyPressed>()) {
                if (keyPressed->code == Keyboard::Key::Escape) {
                    window.close();
                }
                if (keyPressed->code == Keyboard::Key::Space) {

                    // NOTE: Example pushing 20 force.
                    for (const auto &body : bodies) {
                        body->applyForce({100, 0});
                    }
                    cout << "pushing force..." << endl;
                }
            }
        }

        update();
        window.clear(Color(80, 80, 80));
        for (const auto &body : bodies) {

            // NOTE: dereference smart pointer.
            window.draw(*body->getShape());
        }
        window.display();
    }
}

void PhysicsWorld::update() const {
    for (const auto &body : bodies) {
        body->update(dt);
    }
}

void PhysicsWorld::tick() {
    dt = clock.restart().asSeconds();
    if (dt > 0.1f)
        dt = 0.1f;
}