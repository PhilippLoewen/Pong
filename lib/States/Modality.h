//
// Created by loewi on 9/10/16.
//

#ifndef PONG_MODALITY_H
#define PONG_MODALITY_H


namespace States {

    // ------------------------------------------------------------------------------------------- //

    namespace Modality {

        /// <summary>
        ///   Possible behaviors of a game state in respect to the states below it on the stack
        /// </summary>
        enum Enum {

            /// <summary>
            ///   The game state takes exclusive ownership of the screen does not require the state
            ///   below it in the stack to be updated as long as it's active.
            /// </summary>
                    Exclusive,

            /// <summary>
            ///   The game state sits on top of the state below it in the stack, but does
            ///   not completely obscure it or requires it to continue being updated.
            /// </summary>
                    Popup

        };

    } // namespace Modality

    // ------------------------------------------------------------------------------------------- //

}


#endif //PONG_MODALITY_H
