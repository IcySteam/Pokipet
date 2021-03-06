STD = -std=c++17
COMP = g++

all: main.cpp Game.o Pet.o Dog.o Cat.o
	$(COMP) $(STD) -o pokipet Game.o Pet.o Dog.o Cat.o main.cpp

Game.o: Game.cpp
	$(COMP) $(STD) -c Game.cpp

Pet.o: Pet.cpp
	$(COMP) $(STD) -c Pet.cpp

Dog.o: Dog.cpp
	$(COMP) $(STD) -c Dog.cpp
	
Cat.o: Cat.cpp
	$(COMP) $(STD) -c Cat.cpp

test:
	./pokipet < input.txt

test-Dog:
	./pokipet < input-Dog.txt

test-Cat:
	./pokipet < input-Cat.txt
	
pokipet-unitTest: test-unitTest.cpp Game.o Pet.o Dog.o Cat.o
	$(COMP) $(STD) -o pokipet-unitTest Game.o Pet.o Dog.o Cat.o test-unitTest.cpp
	
test-unitTest:
	./pokipet-unitTest | diff - output-unitTest.txt
	
clean:
	rm *.o pokipet* *.stackdump
