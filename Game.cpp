#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <limits>
#include <vector>
#include "Game.h"
#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
using namespace std;

Game::Game()
{
	cout << "Welcome to Pokipet!\nPlease enter your choice: \n";
	cout << "0. Load existing pet\n";
	cout << "1. Create a dog!\n";
	cout << "2. Create a cat!\n";
	cout << "3. Surprise me!\n";
	int roundChoice;
	cin >> roundChoice;
	cout << "Name your pet!\n";
	string nameChoice;
	cin >> nameChoice;
	switch (roundChoice) {
		case 0:
			break;
		case 1:
			currentPetPtr = new Dog(nameChoice, 0);
			break;
		case 2:
			currentPetPtr = new Cat(nameChoice, 0);
			break;
		case 3:
			break;
	}
}

void Game::play(int inInt)
{
	currentPetPtr->interact(inInt);
}

Game::~Game()
{
	delete currentPetPtr;
}
