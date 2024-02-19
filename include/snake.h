#pragma once
#include "raylib.h"
#include "raymath.h"
#include "constants.h"
#include <deque>

class Snake{ 
public:
    Snake();
    void draw();
    void update();
    void setSpeed(Vector2 speed);
    Vector2 getSpeed();
    Vector2 getSnakeHead();
    std::deque<Vector2> getSnakeBody();
    void setGrow(bool ok);
    void setDir(int direction);
    void turnLeft();
    void turnRight();
    int manhattanDistance(int x1, int y1, int x2, int y2);
    int heuristic(int tryMove, Vector2 foodPos);
    void ai(Vector2 foodPos);
private:
    std::deque<Vector2> body;
    Vector2 speed;
    bool grow;
    int direction;
};