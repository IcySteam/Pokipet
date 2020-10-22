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
	Dog myDog = Dog("woofy", 0);
	Cat myCat = Cat("meowza", 0);
	myDog.printDetails();
	myCat.printDetails();
	exit(0);
}