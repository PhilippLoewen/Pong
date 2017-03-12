//
// Created by loewi on 9/4/16.
//

#include "../lib/Bat.h"

Bat::Bat(float startX, float startY) {
    position.x = startX;
    position.y = startY;

    batShape.setSize(sf::Vector2f(50, 5));
    batShape.setPosition(position);
}

sf::FloatRect Bat::getPosition() {
    return batShape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape() {
    return batShape;
}

void Bat::moveLeft(float elapsedFrameTime) {
    position.x -= batSpeed * elapsedFrameTime;
}

void Bat::moveRight(float elapsedFrameTime) {
    position.x += batSpeed * elapsedFrameTime;
}

void Bat::update(float elapsedFrameTime) {
    batShape.setPosition(position);
}
