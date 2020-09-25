# TEST MAKEFILE

make-a: main.cpp Game.o Pet.o Dog.o Cat.o
	g++ -std=c++11 -o a Game.o Pet.o Dog.o Cat.o main.cpp

make-Game.o: Game.cpp
	g++ -c Game.cpp

make-Pet.o: Pet.cpp
	g++ -c Pet.cpp

make-Dog.o: Dog.cpp
	g++ -c Dog.cpp
	
make-Cat.o: Cat.cpp
	g++ -c Cat.cpp

test:
	./a.out # < your_input.txt
