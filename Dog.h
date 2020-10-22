#ifndef DOG_H
#define DOG_H

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

class Dog : public Pet
{
	private:
		void art_wagTail(); // ascii art functions
		void art_chewBone();
		void art_enraged();
		void art_sit();
		void art_annoyed();
		void art_death();
		void art_happy();
	protected:
		virtual void speak();
		virtual void gameover_hunger();
		virtual void gameover_boredness();
		virtual void gameover_upsettedness();
	public:
		Dog();
		Dog(string, int);
		virtual void printDetails();
		virtual int interact(int);
		virtual void greet();
		virtual ~Dog();
};

#endif
