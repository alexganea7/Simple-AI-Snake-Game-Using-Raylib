#include "game.h"

Game::Game(){
    allowMove = 0;
    pause = 0;
    aiPlaying = 1;
    snakeSpeed = 7; // low = fast
    score = 0;
    highScore = 0;
    player = Snake();
    food = Food(player.getSnakeBody());
}

void Game::draw(){ 
    for(int i = 0; i<screenWidth/cellSize; i++){
        for(int j = 0; j<screenWidth/cellSize; j++){
            if((i+j)%2)
                DrawRectangle(cellSize*i, cellSize*j, cellSize, cellSize, tile1Color);
            else
                DrawRectangle(cellSize*i, cellSize*j, cellSize, cellSize, tile2Color);
        }
    }
    food.draw();
    player.draw();
    DrawText(TextFormat("Score: %i", score), 20, 20, 40, BLACK);
    DrawText(TextFormat("High Score: %i", highScore), 20, 60, 40, BLACK);
    if (pause) DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, RAYWHITE); // from raylib example
}
void Game::checkFoodCollision(){
    if(player.getSnakeHead().x == food.getFoodPos().x && player.getSnakeHead().y == food.getFoodPos().y){
        food.setFoodPos(player.getSnakeBody());
        player.setGrow(1);
        score++;
    }
}

void Game::checkEdgeCollision(){
    Vector2 head = player.getSnakeHead();
    if(head.x == cellsCount || head.x == -1 || head.y == -1 || head.y == cellsCount)
        gameOver();
}
void Game::checkTailCollision(){
    std::deque<Vector2> body = player.getSnakeBody();
    Vector2 head = player.getSnakeHead();
    body.pop_front();
    for(unsigned int i=0; i<body.size(); i++){
        if(head.x == body[i].x && head.y == body[i].y)
            gameOver();  
    }
}
void Game::gameOver(){
    player = Snake();
    if(highScore<score){
        highScore = score;
    }
    score = 0;
}
void Game::update(int framesCounter){
    if(IsKeyPressed('C'))
        snakeSpeed = 7;
    if(IsKeyPressed('V'))
        snakeSpeed = 1;
    if(IsKeyPressed('P'))
        pause = !pause;
    if(IsKeyPressed('X'))
        aiPlaying = !aiPlaying;
    if(pause == 0){
        if(aiPlaying)
            player.ai(food.getFoodPos());
        checkEdgeCollision();
        checkTailCollision();
        if(framesCounter%snakeSpeed==0){
            player.update();
            checkFoodCollision();
            allowMove = 1;
        }
        if(IsKeyPressed(KEY_RIGHT) && (player.getSpeed().x == 0) && allowMove){ // can't move from left to right
            player.setSpeed({gameSpeed,0});
            player.setDir(RIGHT);
            allowMove = 0;
        }
        if(IsKeyPressed(KEY_LEFT) && (player.getSpeed().x == 0) && allowMove){
            player.setSpeed({-gameSpeed,0});
            player.setDir(LEFT);
            allowMove = 0;
        }
        if(IsKeyPressed(KEY_UP) && (player.getSpeed().y == 0) && allowMove){
            player.setSpeed({0,-gameSpeed});
            player.setDir(UP);
            allowMove = 0;
        }
        if(IsKeyPressed(KEY_DOWN) && (player.getSpeed().y == 0) && allowMove){
            player.setDir(DOWN);
            player.setSpeed({0,gameSpeed});
            allowMove = 0;
        }
    }
}


