#ifndef CAT_H
#define CAT_H

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

class Cat : public Pet
{
	protected:
		virtual void setNull();
	public:
		Cat();
		Cat(string, int);
		virtual void save();
		virtual void printDetails();
		void art_purr();
		virtual void speak();
		virtual int interact(int);
		virtual void greet();
		virtual void gameover_hunger();
		virtual void gameover_upsettedness();
		virtual void gameover_boredness();
		~Cat();
};

#endif
