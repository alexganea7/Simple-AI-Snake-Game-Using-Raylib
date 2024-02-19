#pragma once
#include "raylib.h"
#include "deque"
#include "constants.h"

class Food{
public:
    Food();
    Food(std::deque<Vector2> snakeBody);
    void draw();
    bool checkPosition(Vector2 pos, std::deque<Vector2> snakeBody);
    Vector2 randomPos(std::deque<Vector2> snakeBody);
    Vector2 getFoodPos();
    void setFoodPos(std::deque<Vector2> snakeBody);
private:
    Vector2 pos;
};