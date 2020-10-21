#ifndef CAT_H
#define CAT_H

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

class Cat : public Pet
{
	private:
		void art_purr();
	protected:
		virtual void speak();
		virtual void gameover_hunger();
		virtual void gameover_boredness();
		virtual void gameover_upsettedness();
	public:
		Cat();
		Cat(string, int);
		virtual void printDetails();
		virtual int interact(int);
		virtual void greet();
		virtual ~Cat();
};

#endif
