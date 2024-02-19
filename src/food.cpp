#include "food.h"

Food::Food(){}

Food::Food(std::deque<Vector2> snakeBody){
    pos = randomPos(snakeBody);
}
void Food::draw(){
    DrawRectangle(pos.x*cellSize+10, pos.y*cellSize+10, cellSize-20, cellSize-20, RED);
}
bool Food::checkPosition(Vector2 pos, std::deque<Vector2> snakeBody){
    for(unsigned int i=0; i<snakeBody.size(); i++){
        if(pos.x == snakeBody[i].x && pos.y == snakeBody[i].y)
            return 0;
    }
    return 1;
}
Vector2 Food::randomPos(std::deque<Vector2> snakeBody){
    Vector2 position;
    do{
    int x = GetRandomValue(0, cellsCount-1);
    int y = GetRandomValue(0, cellsCount-1);
    position = {float(x), float(y)};
    } while(checkPosition(position, snakeBody) != 1);
    return(position);
}
Vector2 Food::getFoodPos(){
    return pos;
}
void Food::setFoodPos(std::deque<Vector2> snakeBody){
    pos = randomPos(snakeBody);
}
