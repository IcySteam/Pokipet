#ifndef DOG_H
#define DOG_H

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

class Dog : public Pet
{
	protected:
		virtual void setNull();
	public:
		Dog();
		Dog(string, int);
		virtual void save();
		virtual void printDetails();
		void art_wagTail();
		virtual void speak();
		virtual void interact(int);
		virtual void greet();
		virtual void gameover_hunger();
		virtual void gameover_upsettedness();
		virtual void gameover_boredness();
		~Dog();
};

#endif
