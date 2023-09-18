default:
	g++ src/main.cpp src/background/bg.cpp src/enemy/enemy.cpp src/tower/tower.cpp -o game1 -lsfml-graphics -lsfml-window -lsfml-system