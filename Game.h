#ifndef GAME_H
#define GAME_H

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
#include "Dog.h"
#include "Cat.h"
using namespace std;

class Game
{
	private:
		int roundCount;
		Pet * currentPetPtr;
	public:
		Game();
		void play(int);
		~Game();
};

#endif
