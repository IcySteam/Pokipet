#ifndef PET_H
#define PET_H

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
using namespace std;

class Pet
{
	protected:
		int ID;
		int age;
		string type;
		string name;
		string food;
		string toy;
		int hunger;
		int boredness;
	public:
		Pet();
		Pet(int, string, string, string, int);
		void setType(string);
		void setName(string);
		void setFood(string);
		void setToy(string);
		void setID(int);
		void setAge(int);
		void setHunger(int);
		void setBoredness(int);
		string getType();
		string getName();
		string getFood();
		string getToy();
		int getID();
		int getAge();
		int getHunger();
		int getBoredness();
		virtual void speak() = 0;
		void setNull();
		virtual void setNullExtra() = 0;
		void printDetails();
		virtual void printDetailsExtra() = 0;
		void save();
		virtual void saveExtra() = 0;
		virtual void interact(int) = 0;
		virtual ~Pet(); // Make destructor VIRTUAL for abstract classes
};

#endif
