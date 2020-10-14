#ifndef CAT_H
#define CAT_H

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

class Cat : public Pet
{
	protected:
		virtual void setNullExtra();
	public:
		Cat();
		Cat(string, int);
		void art_purr();
		virtual void speak();
		virtual void printDetailsExtra();
		virtual void saveExtra();
		virtual void interact(int);
		virtual void greet();
		virtual void gameover_hunger();
		virtual void gameover_upsettedness();
		virtual void gameover_boredness();
		~Cat();
};

#endif
