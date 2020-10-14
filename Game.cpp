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

char nullChars[1024] = {'\0'}; // max input length

void invokeInvalidInput()
{
	cout << "Invalid input! Please try again: ";
}

int valIntInput(char * inChars, int length)
{
	for (int i = 0; i < length; i++){
		if ((inChars[i] >= 33 && inChars[i] <= 47) || (inChars[i] >= 58 && inChars[i] <= 126)) {return 0;}
	}
	return 1;
}

Game::Game()
{
	cout << "Welcome to Pokipet!\nPlease enter your choice: \n";
	cout << "0. Load existing pet\n"; // load exitsing pet from save file
	cout << "1. Create a dog!\n";
	cout << "2. Create a cat!\n";
	cout << "3. Surprise me!\n";
	char * roundChoiceChars = nullChars; 
	int roundChoice = -1;
	while (1) {
		roundChoiceChars = nullChars;
		cin >> roundChoiceChars;
		roundChoice = atoi(roundChoiceChars);
		if (valIntInput(roundChoiceChars, 1024) == 1 && roundChoice >= 0 && roundChoice < 4) {break;}
		invokeInvalidInput();
	}
	string nameChoice;
	switch (roundChoice) {
		case 0:
			break;
		case 1:
			cout << "Name your dog!\n";
			cin >> nameChoice;
			currentPetPtr = new Dog(nameChoice, 0);
			break;
		case 2:
			cout << "Name your cat!\n";
			cin >> nameChoice;
			currentPetPtr = new Cat(nameChoice, 0);
			break;
		case 3:
			break;
	}
}

void Game::play()
{
	if (roundCount == 0) {currentPetPtr->greet();}
	currentPetPtr->printInteractionOptions();
	char * roundChoiceChars = nullChars; 
	int roundChoice = -1;
	while (1) {
		roundChoiceChars = nullChars;
		cin >> roundChoiceChars;
		roundChoice = atoi(roundChoiceChars);
		if (valIntInput(roundChoiceChars, 1024) == 1 && roundChoice >= 0 && roundChoice < currentPetPtr->getInteractionRange()) {
			currentPetPtr->interact(roundChoice);
			roundCount++;
			break;
		}
		invokeInvalidInput();
	}

}

Game::~Game()
{
	delete currentPetPtr;
}
