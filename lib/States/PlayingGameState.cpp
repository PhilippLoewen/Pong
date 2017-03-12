//
// Created by loewi on 9/10/16.
//

#include <sstream>
#include "PlayingGameState.h"
namespace States {
    void PlayingGameState::Entered() {
        // directRenderingGameStateManager->renderWindow->setFramerateLimit(800);
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
            while (directRenderingGameStateManager->renderWindow->pollEvent(event))
            {
                    if (event.type == sf::Event::Closed)
                            // Someone closed the renderWindow- bye
                            directRenderingGameStateManager->renderWindow->close();
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
                    directRenderingGameStateManager->renderWindow->close();
            }


            if (ball.getPosition().top > directRenderingGameStateManager->renderWindow->getSize().y)
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
            if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > directRenderingGameStateManager->renderWindow->getSize().y)
            {
                    ball.reboundSides();
            }
            if(ball.getPosition().intersects(bat.getPosition()))
            {
                    ball.reboundBatOrTop();
                    score++;
            }

            ball.update(elapsedTime);
            bat.update(elapsedTime);


            ss << "Score: " << score << "    Lives: " << lives;
            hud.setString(ss.str());
    }

    void PlayingGameState::Draw(float elapsedFrameTime) {
            // Clear everything from the last frame
            directRenderingGameStateManager->renderWindow->clear(sf::Color(26, 128, 182,255));

            directRenderingGameStateManager->renderWindow->draw(bat.getShape());

            directRenderingGameStateManager->renderWindow->draw(ball.getShape());

            // Draw our score
            directRenderingGameStateManager->renderWindow->draw(hud);

            // Show everything we just drew
            directRenderingGameStateManager->renderWindow->display();
    }

    void PlayingGameState::Exiting() {

    }
}