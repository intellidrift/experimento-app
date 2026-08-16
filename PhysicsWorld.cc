#include "PhysicsWorld.h"

#include "LineShape.h"

PhysicsWorld::PhysicsWorld()
    : mode(VideoMode({3500, 2000})), window(mode, "hello"),
      camera(View(FloatRect({0, 0}, {3500, 2000}))) {

    CircleShape circle(50);
    circle.setFillColor(Color::Cyan);
    circle.setPosition({1000, 500});

    Body b1(make_shared<CircleShape>(circle), {200, 0}, 50);
    bodies.push_back(make_shared<Body>(b1));

    CircleShape circle1(50);
    circle1.setFillColor(Color::Green);
    circle1.setPosition({2500, 500});

    Body b2(make_shared<CircleShape>(circle1), {-200, 0}, 30);
    bodies.push_back(make_shared<Body>(b2));

    // LineShape line1({0, 0}, {100, 100}, 4, Color::Green);
    //
    // Body b3(make_shared<LineShape>(line1), {20, 0}, 1);
    // bodies.push_back(make_shared<Body>(b3));

    //
    // LineShape line2(b1.getPosition(), b2.getPosition(), 2, Color::Green);
    //
    // Body b4(make_shared<LineShape>(line2), {0, 0}, 1);
    // bodies.push_back(make_shared<Body>(b4));
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
                    // some action
                }
            }
        }
        tickBodies();
        window.clear(Color(80, 80, 80));
        drawGrid();
        for (const auto &body : bodies) {
            window.draw(*body->shape);
        }
        window.display();
    }
}

void PhysicsWorld::tickBodies() const {
    for (const auto &body : bodies) {
        body->update(dt);
    }
    resolveCollision();
}

void PhysicsWorld::resolveCollision() const {
    for (const auto &body : bodies) {
        // ...
    }
}

void PhysicsWorld::drawGrid() {
    float y = static_cast<float>(window.getSize().y);
    float x = static_cast<float>(window.getSize().x);
    for (float i = 0; i < window.getSize().x; i += 100) {
        LineShape linex({i, 0}, {i, y}, 1);
        LineShape liney({0, i}, {x, i}, 1);
        window.draw(linex);
        window.draw(liney);
    }
}

void PhysicsWorld::tick() {
    dt = clock.restart().asSeconds();
    if (dt > 0.1f)
        dt = 0.1f;
}