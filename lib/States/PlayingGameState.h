//
// Created by loewi on 9/10/16.
//

#ifndef PONG_PLAYINGGAMESTATE_H
#define PONG_PLAYINGGAMESTATE_H

#include "GameState.h"
#include "../Drawable.h"
#include "../Updateable.h"
#include "DirectRenderingGameStateManager.h"
#include "../Bat.h"
#include "../Ball.h"

namespace States {
    class PlayingGameState : public GameState, public virtual Updateable, public virtual Drawable {
    public:
        void Entered();
        void Exiting();
        void Update(float elapsedTime);
        void Draw(float elapsedFrameTime);
    private:
        std::shared_ptr<DirectRenderingGameStateManager> directRenderingGameStateManager;

        Bat bat;
        Ball ball;
        sf::Text hud;
        sf::Font font;

        int score = 0;
        int lives = 3;

        std::stringstream ss;


    };
}

#endif //PONG_PLAYINGGAMESTATE_H
