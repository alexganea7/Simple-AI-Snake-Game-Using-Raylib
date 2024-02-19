#include "snake.h"

       
Snake::Snake(){
    body = {{6,9}, {5,9}, {4,9}};
    speed = {gameSpeed, 0};
    grow = 0;
    direction = RIGHT;
}

void Snake::draw(){
    DrawRectangle(body[0].x*cellSize+3, body[0].y*cellSize+3, cellSize-6, cellSize-6, BLACK);
    for(unsigned int i=1; i<body.size(); i++){
        DrawRectangle(body[i].x*cellSize+3, body[i].y*cellSize+3, cellSize-6, cellSize-6, snakeBodyColor);
    }
}
void Snake::update(){
    body.push_front({speed.x+body[0].x, speed.y+body[0].y});
    if(grow == 1)
        grow = 0;
    else
        body.pop_back();
}
void Snake::setSpeed(Vector2 speed){
    this->speed.x = speed.x;
    this->speed.y = speed.y;
}
Vector2 Snake::getSpeed(){
    return {speed.x, speed.y};
}
Vector2 Snake::getSnakeHead(){
    return body.front();
}
std::deque<Vector2> Snake::getSnakeBody(){
    return body;
}
void Snake::setGrow(bool ok){
    grow = ok;
}
void Snake::setDir(int direction){
    this->direction = direction;
}


void Snake::turnLeft(){
    if(direction == RIGHT){
        direction = UP;
        speed = {0,-gameSpeed};
    }
    else if (direction == LEFT){
        direction = DOWN;
        speed = {0,gameSpeed};
    }
    else if (direction == UP){
        direction = LEFT; 
        speed = {-gameSpeed, 0};
    }
    else{
        direction = RIGHT;
        speed = {gameSpeed, 0};
    }
}
void Snake::turnRight(){
    if(direction == RIGHT){
        direction = DOWN;
        speed = {0,gameSpeed};
    }
    else if (direction == LEFT){
        direction = UP;
        speed = {0,-gameSpeed};
    }
    else if (direction == UP){
        direction = RIGHT; 
        speed = {gameSpeed, 0};
    }
    else{
        direction = LEFT;
        speed = {-gameSpeed, 0};
    }
}

int Snake::manhattanDistance(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+abs(y1-y2);
}

int Snake::heuristic(int tryMove, Vector2 foodPos){
    int reward = 0;
    Vector2 oldPos = getSnakeHead();
    Vector2 newPos = oldPos;
    
    if(direction == LEFT){
        if(tryMove == tryForward){
            newPos.x--;
        }
        if(tryMove == tryLeft){
            newPos.y++;
        }
        if(tryMove == tryRight){
            newPos.y--;
        }
    }
    if(direction == RIGHT){
        if(tryMove == tryForward){
            newPos.x++;
        }
        if(tryMove == tryLeft){
            newPos.y--;
        }
        if(tryMove == tryRight){
            newPos.y++;
        }
    }
    if(direction == UP){
        if(tryMove == tryForward){
            newPos.y--;
        }
        if(tryMove == tryLeft){
            newPos.x--;
        }
        if(tryMove == tryRight){
            newPos.x++;
        }
    }
    if(direction == DOWN){
        if(tryMove == tryForward){
            newPos.y++;
        }
        if(tryMove == tryLeft){
            newPos.x++;
        }
        if(tryMove == tryRight){
            newPos.x--;
        }
    }

    // now we have the next position, we have to calculate different scenarios for that

    // collision with border
    if(newPos.x == cellsCount || newPos.x == -1 || newPos.y == -1 || newPos.y == cellsCount)
        reward -= 200;

    // next to food
        if(newPos.x == foodPos.x && newPos.y == foodPos.y)
        reward += 100;

    // collision with body
    std::deque<Vector2> body = getSnakeBody();
    for(unsigned int i=0; i<body.size(); i++){
        if(newPos.x == body[i].x && newPos.y == body[i].y)
            reward -= 300;
    }

    //moving towards food
    int oldDistance = manhattanDistance(oldPos.x, oldPos.y, foodPos.x, foodPos.y); 
    int newDistance = manhattanDistance(newPos.x, newPos.y, foodPos.x, foodPos.y);
    if(newDistance<oldDistance)
        reward += 50;


    return reward;
}

void Snake::ai(Vector2 foodPos){ // reward based w/o learning
// ai has 3 different moves, continue moving, turn left, turn right
    int forwardVal = heuristic(tryForward, foodPos);
    int leftVal = heuristic(tryLeft, foodPos);
    int rightVal = heuristic(tryRight, foodPos);
    if(forwardVal >= leftVal and forwardVal >= rightVal){
        //continue
    }
    else if(leftVal >= rightVal)
        turnLeft();
    else
        turnRight();
}
