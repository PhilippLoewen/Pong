//
// Created by loewi on 9/10/16.
//

#ifndef PONG_GAMESTATE_H
#define PONG_GAMESTATE_H

namespace States {

    class GameState {

        /// <summary>Destroys the game state</summary>
    public:
        virtual ~GameState() {}

        /// <summary>Notifies the game state it is about to be exited</summary>
        /// <remarks>
        ///   <para>
        ///     This happens when the game state is completely removed from the game state manager.
        ///     Depending on your game's design, the state may be kept somewhere (presumably some
        ///     state repository that's responsible for creating an storing states) or it may be
        ///     deleted immediately following its removal from the game state manager.
        ///   </para>
        ///   <para>
        ///     Upon receiving this notification, the game state should remove any nodes it has
        ///     added to the game's scene graph, disconnect itself from input callbacks and so
        ///     on. You may even want to destroy memory-intensive resources if the game state may
        ///     be kept alive in your game.
        ///   </para>
        /// </remarks>
    public:
        virtual void Exiting() {}

        /// <summary>Notifies the game state that it has been entered</summary>
        /// <remarks>
        ///   This call allows the game state to add any nodes it requires to the game's scene
        ///   graph or to connect to the callbacks of an input manager, etc.
        /// </remarks>
    public:
        virtual void Entered() {}

        /// <summary>
        ///   Notifies the game state that it is about to be obscured by another state
        /// </summary>
        /// <remarks>
        ///   This happens when another game state has been pushed on top of this state. A typical
        ///   scenario would be if you leave your game's main menu on the state stack during
        ///   the whole game, as soon as the game play state is entered, it would always draw over
        ///   your main menu, thus the main menu should no longer bother drawing (or even actively
        ///   remove its menu items from the game's GUI).
        /// </remarks>
    public:
        virtual void Obscuring() {}

        /// <summary>
        ///   Notifies the game state that it is no longer obscured by another state
        /// </summary>
        /// <remarks>
        ///   This notification will be issued when the game state was obscured by another state
        ///   sitting on top of it but that state has now been removed. If the revealed state
        ///   was the game's main menu, for example, it should now resume drawing or perhaps
        ///   re-add the menu items to the game's GUI in case it removed them when it was
        ///   first obscured.
        /// </remarks>
    public:
        virtual void Revealed() {}

    };
}


#endif //PONG_GAMESTATE_H
