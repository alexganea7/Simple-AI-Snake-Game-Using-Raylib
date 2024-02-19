#pragma once
#include "food.h"
#include "snake.h"
#include "constants.h"
#include "deque"

class Game{
public:
    Game();
    void draw();
    void checkFoodCollision();
    void checkEdgeCollision();
    void checkTailCollision();
    void gameOver();
    void update(int framesCounter);
private:
    bool allowMove;
    bool pause;
    bool aiPlaying;
    int snakeSpeed;
    int score;
    int highScore;
    Snake player;
    Food food;
};