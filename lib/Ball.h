//
// Created by loewi on 9/4/16.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H


#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::Vector2f position;

    sf::RectangleShape ballShape;

    sf::Vector2f velocity {.2f,.2f};

public:
    Ball(float startX, float starty);
    Ball(sf::Vector2f position);

    sf::FloatRect getPosition();
    sf::RectangleShape getShape();

    float getXVelocity();

    void reboundSides();

    void reboundBatOrTop();

    void hitBottom();

    void update(float elapsedFrameTime);
};


#endif //PONG_BALL_H
