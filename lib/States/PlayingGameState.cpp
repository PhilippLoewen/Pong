//
// Created by loewi on 9/10/16.
//

#include <sstream>
#include "PlayingGameState.h"
namespace States {
    void PlayingGameState::Entered() {
        gameStateManager->renderWindow->setFramerateLimit(800);
        font.loadFromFile("DS-DIGIT.TTF");

        // Set the font to our message
        hud.setFont(font);

        // Make it really big
        hud.setCharacterSize(75);

        // Choose a color
        hud.setColor(sf::Color::White);
    }

    void PlayingGameState::Update(float elapsedTime) {
            sf::Event event;
            while (gameStateManager->renderWindow->pollEvent(event))
            {
                    if (event.type == sf::Event::Closed)
                            // Someone closed the renderWindow- bye
                            gameStateManager->renderWindow->close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                    // move left...
                    bat.moveLeft(elapsedTime);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                    // move right...
                    bat.moveRight(elapsedTime);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                    // quit...
                    // Someone closed the renderWindow- bye
                    gameStateManager->renderWindow->close();
            }


            if (ball.getPosition().top > gameStateManager->windowHeight)
            {
                    ball.hitBottom();
                    lives--;
                    if(lives <= 0)
                    {
                            lives = 3;
                            score = 0;
                    }
            }
            if (ball.getPosition().top < 0)
            {
                    ball.reboundBatOrTop();
                    score++;
            }
            if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > gameStateManager->windowWidth)
            {
                    ball.reboundSides();
            }
            if(ball.getPosition().intersects(bat.getPosition()))
            {
                    ball.reboundBatOrTop();
                    score++;
            }

            ball.update();
            bat.update();


            ss << "Score: " << score << "    Lives: " << lives;
            hud.setString(ss.str());
    }

    void PlayingGameState::Draw(float elapsedFrameTime) {
            // Clear everything from the last frame
            gameStateManager->renderWindow->clear(sf::Color(26, 128, 182,255));

            gameStateManager->renderWindow->draw(bat.getShape());

            gameStateManager->renderWindow->draw(ball.getShape());

            // Draw our score
            gameStateManager->renderWindow->draw(hud);

            // Show everything we just drew
            gameStateManager->renderWindow->display();
    }

    void PlayingGameState::Exiting() {

    }
}