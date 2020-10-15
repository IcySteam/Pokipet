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
#include "Game.h"
using namespace std;

int main()
{
	Game myGame;
	int gameReturn = 0; 
	while (gameReturn == 0) {
		gameReturn = myGame.play();
	}
	return 0;
}