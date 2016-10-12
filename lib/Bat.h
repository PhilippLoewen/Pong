//
// Created by loewi on 9/4/16.
//

#ifndef PONG_BAT_H
#define PONG_BAT_H
#include <SFML/Graphics.hpp>

class Bat {
private:
    sf::Vector2f position;

    // A RectangleShape object
    sf::RectangleShape batShape;

    float batSpeed = .3f;

public:
    Bat(float startX, float startY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    void moveLeft(float d);

    void moveRight(float d);

    void update();
};


#endif //PONG_BAT_H
