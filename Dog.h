#ifndef DOG_H
#define DOG_H

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
		void art_chewBone();
		void art_enraged();
		void art_sit();
		void art_annoyed();
		void art_death();
		void art_happy();
		virtual void speak();
		virtual int interact(int);
		virtual void greet();
		virtual void gameover_hunger();
		virtual void gameover_upsettedness();
		virtual void gameover_boredness();
		~Dog();
};

#endif
