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
#include "Pet.h"
#include <vector>
using namespace std;

class Dog : public Pet
{
	protected:
		
	public:
		Dog();
		Dog(string, int);
		void wagTail();
		virtual void speak();
		virtual void setNullExtra();
		virtual void printDetailsExtra();
		virtual void saveExtra();
		virtual void interact(int);
		~Dog();
};

#endif
