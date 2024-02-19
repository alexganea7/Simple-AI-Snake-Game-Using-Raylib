game.exe: main.cpp src/constants.cpp src/snake.cpp src/food.cpp src/game.cpp
	g++ -o game.exe main.cpp src/constants.cpp src/snake.cpp src/food.cpp src/game.cpp -O1 -Wall -std=c++17 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

clean:
	del game.exe