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
#include "Game.h"
using namespace std;

int main()
{
	Game * myGame = new Game();
	int gameReturn = 0; 
	while (1) { // keep playing until game over
		gameReturn = myGame->play();
		if (gameReturn == 1) {break;}
	}
	return 0;
	exit(0);
}