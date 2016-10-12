//
// Created by loewi on 9/10/16.
//

#ifndef PONG_DRAWABLE_H
#define PONG_DRAWABLE_H


class Drawable {

    /// <summary>Destroys the drawable object</summary>
public: virtual ~Drawable() {}

    /// <summary>Called when the game state should draw itself</summary>
    /// <param name="elapsedFrameTime">Time elapsed since the last frame</param>
    /// <remarks>
    ///   In this call, the game state can either draw itself to the screen outright or
    ///   update the rendering engine's scene graph.
    /// </remarks>
public: virtual void Draw(float elapsedFrameTime) = 0;

};


#endif //PONG_DRAWABLE_H
