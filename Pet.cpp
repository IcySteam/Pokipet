#include <iostream>
#include <fstream>
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
	memory = new string[memoryCapacity];
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
	memory = new string[memoryCapacity];
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
	system("read -p 'Press Enter to continue...' var"); // asks for confirmation before clearing console
	system("clear");
	cout << "It's day " << this->getAge() << ".\n";
	this->checkAttributes();
	cout << "What would you like to do?\n";
	cout << "0. Save this pet\n"; // save existing pet to save file
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

string * Pet::getRandomToys(int size, string pToy)
{
	string allToys[10] = {"Ball", "Laser", "Throw", "Chopsticks", "Team Red Gaming PC", "Google Pixel 5", "Valve Index", "Fidget Spinner", "Mirrorless Camera", "Rubik's Cube"};
	string * output = new string[size];
	int pick;
	srand(time(0));
	output[rand() % size] = pToy;
	for (int i = 0; i < size; i++) {
		if (output[i].compare(pToy) != 0) {
			pick = rand() % 10;
			output[i] = allToys[pick];
		}
	}
	return output;
}

int Pet::checkGameover()
{
	if (hunger >= 15) {
		return 1;
	}
	else if (boredness >= 15) {
		return 2;
	}
	else if (upsettedness >= 15) {
		return 3;
	}
	return 0;
}

void Pet::gameover(int pInt)
{
	cout << "Game over!!! Your pet " << this->getType() << ", " << this->getName() << ", has become too ";
	switch (pInt) {
		case 1:
			cout << "hungry.\n";
		break;
		case 2:
			cout << "bored.\n";
		break;
		case 3:
			cout << "upset.\n";
		break;
	}
	this->save(); // save when game over
	switch (pInt) {
		case 1:
			this->gameover_hunger();
		break;
		case 2:
			this->gameover_boredness();
		break;
		case 3:
			this->gameover_upsettedness();
		break;
	}
}

void Pet::progressAttributes()
{
	if (hunger < 15) {hunger++;}
	if (boredness < 15) {boredness++;}
	age++;
}

void Pet::checkAttributes()
{
	string adjective = "";
	if (hunger >= 6 && hunger < 9) {adjective = "somewhat ";}
	else if (hunger >= 9 && hunger < 12) {adjective = "";}
	else if (hunger >= 12) {adjective = "very ";}
	if (hunger >= 6) {cout << this->getName() << " the " << this->getType() << " is " << adjective << "hungry.\n";}
	
	if (boredness >= 6 && boredness < 9) {adjective = "somewhat ";}
	else if (boredness >= 9 && boredness < 12) {adjective = "";}
	else if (boredness >= 12) {adjective = "very ";}
	if (boredness >= 6) {cout << this->getName() << " the " << this->getType() << " is " << adjective << "bored.\n";}
	
	if (upsettedness >= 4 && upsettedness < 8) {adjective = "somewhat ";}
	else if (upsettedness >= 8 && upsettedness < 12) {adjective = "";}
	else if (upsettedness >= 12) {adjective = "very ";}
	if (upsettedness >= 4) {cout << this->getName() << " the " << this->getType() << " is " << adjective << "upset.\n";}
}

void Pet::printDetails()
{
	cout << this->getName() << " the " << this->getAge() << "-day old " << this->getType() << " with type ID " << this->getID() << "\n";
	cout << "Food: " << this->getFood() << ", Toy: " << this->getToy() << "\n";
	cout << "Hunger: " << hunger << ", Boredness: " << boredness << ", Upsettedness: " << upsettedness << "\n";
}

void Pet::save()
{
	srand(time(0));
	string newSaveCommand = "touch ";
	string fileName = to_string(rand());
	fileName.append(".savefile"); // generate random new savefile name
	newSaveCommand.append(fileName);
	char newSaveCommandChars[1024] = {'\0'};
	strcpy(newSaveCommandChars, newSaveCommand.c_str());
	system(newSaveCommandChars);
	ofstream savefile;
	savefile.open(fileName, ios::app); 
	savefile << this->getID() << "\n"; // saves attributes line by line
	savefile << this->getAge() << "\n";
	savefile << this->getType() << "\n";
	savefile << this->getName() << "\n";
	savefile << this->getFood() << "\n";
	savefile << this->getToy() << "\n";
	int pHunger, pBoredness, pUpsettedness;
	if (hunger > 13) {pHunger = 13;} else {pHunger = hunger;} // revive mechanic
	if (boredness > 13) {pBoredness = 13;} else {pBoredness = boredness;}
	if (upsettedness > 13) {pUpsettedness = 13;} else {pUpsettedness = upsettedness;}
	savefile << pHunger << "\n";
	savefile << pBoredness << "\n";
	savefile << pUpsettedness << "\n";
	savefile << memoryCapacity << "\n";
	savefile << memorySize << "\n";
	for (int i = 0; i < memorySize; i++) {
		savefile << memory[i] << "\n";
	}
	cout << this->getName() << " the " << this->getType() << " has been successully saved.\n";
	cout << "File name: " << fileName << "\n";
	savefile.close();
}

void Pet::talkTo()
{
	if (memorySize+1 == memoryCapacity) { // realloc
		string * temp = new string[memoryCapacity*2];
		for (int i = 0; i < memorySize; i++) {
			temp[i] = memory[i];
		}
	delete[] memory;
	memory = temp;
	memoryCapacity = memoryCapacity*2;
	}
	cout << "I'm listening: ";
	string tempStr;
	cin >> tempStr;
	memory[memorySize] = tempStr;
	cout << "I'll remember that.\n";
	memorySize++;
}

void Pet::overwrite(int pID, int pAge, string pType, string pName, string pFood, string pToy, int pHunger, int pBoredness, int pUpsettedness, int pMemoryCapacity, int pMemorySize, string * pMemory)
{
	ID = pID;
	age = pAge;
	type = pType;
	name = pName;
	food = pFood;
	toy = pToy;
	hunger = pHunger;
	boredness = pBoredness;
	upsettedness = pUpsettedness;
	memoryCapacity = pMemoryCapacity;
	memorySize = pMemorySize;
	delete[] memory;
	memory = pMemory;
}

void Pet::speak()
{
	srand(time(0));
	cout << "(Translation: " << memory[rand() % (memorySize)] << "?)\n";
}

Pet::~Pet()
{
	delete[] memory;
}
