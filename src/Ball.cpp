//
// Created by loewi on 9/4/16.
//

#include "../lib/Ball.h"

Ball::Ball(float startX, float startY) : position{startX, startY} {
    ballShape.setSize(sf::Vector2f(10,10));
    ballShape.setPosition(position);
}

Ball::Ball(sf::Vector2f position) : position { position } {
    ballShape.setSize(sf::Vector2f(10,10));
    ballShape.setPosition(position);
}

sf::FloatRect Ball::getPosition() {
    return ballShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape() {
    return ballShape;
}

float Ball::getXVelocity() {
    return velocity.x;
}

void Ball::reboundSides() {
    velocity.x = -velocity.x;
}

void Ball::reboundBatOrTop() {
    position.y -= (velocity.y * 30);
    velocity.y = -velocity.y;
}

void Ball::hitBottom() {
    position.y = 1;
    position.x = 500;
}

void Ball::update() {
    position.x += velocity.x;
    position.y += velocity.y;

    ballShape.setPosition(position);
}

