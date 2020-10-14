#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <limits>
#include <vector>
#include "Pet.h"
using namespace std;

// common functions
bool intPresent(int pInt, int * pIntArray, int size)
{
	for (int i = 0; i < size; i++) {
		if (pIntArray[i] == pInt) {return true;}
	}
	return false;
}

bool stringPresent(string pString, string * pStringArray, int size)
{
	for (int i = 0; i < size; i++) {
		if (pStringArray[i].compare(pString) == 0) {return true;}
	}
	return false;
}

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

void nullCharArray(char * pCharArray, int length)
{
	for (int i = 0; i < length; i++) {
		pCharArray[i] = '\0';
	}
}
// common functions

Pet::Pet()
{
	type = "?";
	name = "?";
	food = "?";
	toy = "?";
	ID = -1;
	age = -1;
	hunger = -1;
	boredness = -1;
	upsettedness = -1;
}

Pet::Pet(int pID, string pName, string pFood, string pToy, int pAge)
{
	name = pName;
	food = pFood;
	toy = pToy;
	ID = pID;
	switch (ID) {
		case 1:
			type = "Dog";
			break;
		case 2:
			type = "Cat";
			break;
	}
	age = pAge;
	hunger = 0;
	boredness = 0;
	upsettedness = 0;
}

void Pet::setType(string pType)
{
	type = pType;
}

void Pet::setName(string pName)
{
	name = pName;
}

void Pet::setFood(string pFood)
{
	food = pFood;
}

void Pet::setToy(string pToy)
{
	toy = pToy;
}

void Pet::setID(int pID)
{
	ID = pID;
}

void Pet::setAge(int pAge)
{
	age = pAge;
}

void Pet::setHunger(int pHunger)
{
	hunger = pHunger;
}

void Pet::setBoredness(int pBoredness)
{
	boredness = pBoredness;
}

void Pet::setUpsettedness(int pUpsettedness)
{
	upsettedness = pUpsettedness;
}

string Pet::getType()
{
	return type;
}

string Pet::getName()
{
	return name;
}

string Pet::getFood()
{
	return food;
}

string Pet::getToy()
{
	return toy;
}

int Pet::getID()
{
	return ID;
}

int Pet::getAge()
{
	return age;
}

int Pet::getHunger()
{
	return hunger;
}

int Pet::getBoredness()
{
	return boredness;
}

int Pet::getUpsettedness()
{
	return upsettedness;
}

int Pet::getInteractionRange()
{
	return 6;
}

void Pet::printInteractionOptions()
{
	cout << "\nWhat would you like to do?\n";
	cout << "0. Save this pet\n"; // save exitsing pet to save file
	cout << "1. Feed\n";
	cout << "2. Pet\n";
	cout << "3. Play\n";
	cout << "4. Talk\n";
	cout << "5. Mind your own business\n";
}

string * Pet::getRandomFoods(int size, string pFood)
{
	string allFoods[10] = {"Bone", "Fish", "Blue Cheese", "Grass", "Bark", "Black Coffee", "Chili Pepper", "Stinky Tofu", "Vegemite", "Durian"};
	string * output = new string[size];
	int pick;
	srand(time(0));
	output[rand() % size] = pFood;
	for (int i = 0; i < size; i++) {
		if (output[i].compare(pFood) != 0) {
			pick = rand() % 10;
			output[i] = allFoods[pick];
		}
	}
	return output;
}

int Pet::checkGameover()
{
	if (this->getHunger() >= 15) {
		this->gameover_hunger();
		return 1;
	}
	else if (this->getUpsettedness() >= 15) {
		this->gameover_upsettedness();
		return 2;
	}
	else if (this->getBoredness() >= 15) {
		this->gameover_boredness();
		return 3;
	}
	return 0;
}

void Pet::gameover(int pInt)
{
	cout << "Game over!!! Your pet " << this->getType() << ", " << this->getName() << ", has become too ";
	switch (pInt) {
		case 1:
			cout << "hungry.";
			break;
		case 2:
			cout << "upset.";
			break;
		case 3:
			cout << "bored.";
			break;
	}
	cout << "\nA recent savefile of your pet has been created.\n";
	this->save();
	switch (pInt) {
		case 1:
			this->gameover_hunger();
			break;
		case 2:
			this->gameover_upsettedness();
			break;
		case 3:
			this->gameover_boredness();
			break;
	}
}

Pet::~Pet()
{
	
}
