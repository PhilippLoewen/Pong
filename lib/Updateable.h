//
// Created by loewi on 9/10/16.
//

#ifndef PONG_UPDATEABLE_H
#define PONG_UPDATEABLE_H


class Updateable {

    /// <summary>Destroys the updateable object</summary>
    public: virtual ~Updateable() {}

    /// <summary>Called when the game state should advance its simulation state</summary>
    /// <param name="elapsedTime">Time by which to advance the simulation</param>
    /// <remarks>
    ///   In this call, the game state should advance its own simulation according to
    ///   the amount of passed time. It is generally useful to manage the game's state
    ///   independent of its scene graph so game servers can run the game purely calling
    ///   this method without rendering and game clients can run the Update() cycle threaded
    ///   while rendering the most recent scene graph to the screen.
    /// </remarks>
    public: virtual void Update(float elapsedTime) = 0;

};

#endif //PONG_UPDATEABLE_H
