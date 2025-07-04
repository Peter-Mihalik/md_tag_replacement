FLAGS=-std=c++17

main: main.cpp
	g++ $(FLAGS) -o main main.cpp
	mv main notes
