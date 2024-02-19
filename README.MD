# Simple reward based AI Snake using raylib

A classic snake game with a simple reward-based AI, written in C++ using the raylib library. 


## Build

```console
make
```
 or run the following
```
 g++ -o game.exe main.cpp src/constants.cpp src/snake.cpp src/food.cpp src/game.cpp -O1 -Wall -std=c++17 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
```

## Run

```console
.\game.exe
```

## Controls

- `arrows` movement
- `p` pause
- `x` activate/disable AI
- `c` set speed to normal
- `v` set speed to very fast (not playable for humans)
