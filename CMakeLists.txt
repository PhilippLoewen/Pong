cmake_minimum_required(VERSION 3.6)
project(Pong)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/Bat.cpp lib/Bat.h src/Ball.cpp lib/Ball.h lib/Drawable.h lib/Updateable.h lib/States/GameState.h lib/States/GameStateManager.h lib/States/Modality.h lib/States/DirectRenderingGameStateManager.cpp lib/States/DirectRenderingGameStateManager.h lib/States/PlayingGameState.cpp lib/States/PlayingGameState.h)
add_executable(Pong ${SOURCE_FILES})

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

configure_file("DS-DIGIT.TTF" "DS-DIGIT.TTF" COPYONLY)