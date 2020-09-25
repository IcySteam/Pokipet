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
#include "Pet.h"
using namespace std;

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

void Pet::setNull()
{
	type = "?";
	name = "?";
	food = "?";
	toy = "?";
	ID = -1;
	age = -1;
	hunger = -1;
	boredness = -1;
}

void Pet::printDetails()
{
	cout << name << " the " << age << "-year old " << type << " with ID " << ID << "\n";
	cout << "Food: " << food << ", Toy: " << toy << "\n";
	this->speak();
}

void Pet::save()
{
	
}

Pet::~Pet()
{
	
}
