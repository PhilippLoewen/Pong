#include "lib/Bat.h"
#include "lib/Ball.h"
#include "lib/States/DirectRenderingGameStateManager.h"
#include "lib/States/PlayingGameState.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <memory>

using namespace States;


int main() {
    const float dt = 0.01;
    std::shared_ptr<DirectRenderingGameStateManager> gameStateManager = std::make_shared<DirectRenderingGameStateManager>();

    gameStateManager->Push(std::make_shared<PlayingGameState>(gameStateManager));
    sf::Clock clock;
    sf::Time currentTime = clock.getElapsedTime();
    float accumulator = 0.0;
    while (true) {
        float frameTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        accumulator += frameTime;
        while (accumulator >= dt) {
            gameStateManager->Update(dt);
            accumulator -= dt;
        }
        gameStateManager->Draw(1.0f);
    }

}

//int main() {
//    int windowWidth = 1024;
//    int windowHeight = 768;
//
//    // Make a window that is 1024 by 768 pixels
//    // And has the title "Pong"
//    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");
//    window.setFramerateLimit(800);
//
//    int score = 0;
//    int lives = 3;
//
//    // create a bat
//    Bat bat (windowWidth / 2, windowHeight - 20);
//
//    // create a ball
//    Ball ball(windowWidth / 2, 1);
//
//    // Create a "Text" object called "message". Weird but we will learn about objects soon
//    sf::Text hud;
//
//    // We need to choose a font
//    sf::Font font;
//    // http://www.dafont.com/theme.php?cat=302
//    font.loadFromFile("DS-DIGIT.TTF");
//
//    // Set the font to our message
//    hud.setFont(font);
//
//    // Make it really big
//    hud.setCharacterSize(75);
//
//    // Choose a color
//    hud.setColor(sf::Color::White);
//
//    sf::Clock clock;
//
//    // This "while" loop goes round and round- perhaps forever
//    while (window.isOpen())
//    {
//
//        /*
//            Handle the player input
//            *********************************************************************
//            *********************************************************************
//            *********************************************************************
//        */
//
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                // Someone closed the window- bye
//                window.close();
//        }
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//        {
//            // move left...
//            bat.moveLeft(0);
//        }
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//        {
//            // move right...
//            bat.moveRight(0);
//        }
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//        {
//            // quit...
//            // Someone closed the window- bye
//            window.close();
//        }
//
//
//        if (ball.getPosition().top > windowHeight)
//        {
//            ball.hitBottom();
//            lives--;
//            if(lives <= 0)
//            {
//                lives = 3;
//                score = 0;
//            }
//        }
//        if (ball.getPosition().top < 0)
//        {
//            ball.reboundBatOrTop();
//            score++;
//        }
//        if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > windowWidth)
//        {
//            ball.reboundSides();
//        }
//        if(ball.getPosition().intersects(bat.getPosition()))
//        {
//            ball.reboundBatOrTop();
//            score++;
//        }
//
//        ball.update();
//        bat.update();
//
//        std::stringstream ss;
//        ss << "Score: " << score << "    Lives: " << lives;
//        hud.setString(ss.str());
//
//        /*
//           Draw the frame
//           *********************************************************************
//           *********************************************************************
//           *********************************************************************
//       */
//
//        // Clear everything from the last frame
//        window.clear(sf::Color(26, 128, 182,255));
//
//        window.draw(bat.getShape());
//
//        window.draw(ball.getShape());
//
//        // Draw our score
//        window.draw(hud);
//
//        // Show everything we just drew
//        window.display();
//    }// This is the end of the "while" loop
//    return 0;
//}