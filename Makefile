hellomake: main.cpp 
	g++ -std=c++2a main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app