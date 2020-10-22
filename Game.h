#ifndef GAME_H
#define GAME_H

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
#include "Dog.h"
#include "Cat.h"
using namespace std;

class Game
{
	private:
		int roundCount = 0;
		Pet * currentPetPtr;
		void art_logo(); // displayed at program startup
	public:
		Game();
		int play();
		~Game();
};

#endif
