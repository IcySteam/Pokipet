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
#include "Game.h"
#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
using namespace std;

int main()
{
	Game myGame;
	while (1) {
		myGame.play();
	}
	return 0;
}