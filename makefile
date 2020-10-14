STD = -std=c++17
COMP = g++

all: main.cpp Game.o Pet.o Dog.o Cat.o
	$(COMP) $(STD) -o prog Game.o Pet.o Dog.o Cat.o main.cpp

Game.o: Game.cpp
	$(COMP) $(STD) -c Game.cpp

Pet.o: Pet.cpp
	$(COMP) $(STD) -c Pet.cpp

Dog.o: Dog.cpp
	$(COMP) $(STD) -c Dog.cpp
	
Cat.o: Cat.cpp
	$(COMP) $(STD) -c Cat.cpp

test:
	./prog < input.txt
	
clean:
	rm *.o prog *.stackdump
