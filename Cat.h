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
		
	public:
		Cat();
		Cat(string, int);
		void purr();
		virtual void speak();
		virtual void setNullExtra();
		virtual void printDetailsExtra();
		virtual void saveExtra();
		virtual void interact(int);
		~Cat();
};

#endif
