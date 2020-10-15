#ifndef PET_H
#define PET_H

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
using namespace std;

// common functions
extern bool intPresent(int pInt, int * pIntArray, int size);

extern bool stringPresent(string pString, string * pStringArray, int size);

extern void invokeInvalidInput();

extern int valIntInput(char * inChars, int length);

extern void nullCharArray(char *, int);
// common functions

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
		int upsettedness;
		void progressAttributes();
		string * memory;
		void setType(string);
		void setName(string);
		void setFood(string);
		void setToy(string);
		void setID(int);
		void setAge(int);
		void setHunger(int);
		void setBoredness(int);
		void setUpsettedness(int);
		virtual void setNull() = 0;
		int checkGameover();
		void gameover(int);
		virtual void gameover_hunger() = 0;
		virtual void gameover_upsettedness() = 0;
		virtual void gameover_boredness() = 0;
	public:
		Pet();
		Pet(int, string, string, string, int);
		string getType();
		string getName();
		string getFood();
		string getToy();
		int getID();
		int getAge();
		int getHunger();
		int getBoredness();
		int getUpsettedness();
		virtual void speak() = 0;
		virtual void printDetails() = 0;
		virtual void save() = 0;
		int getInteractionRange();
		void printInteractionOptions();
		string * getRandomFoods(int, string);
		virtual int interact(int) = 0;
		virtual void greet() = 0;
		virtual ~Pet(); // Make destructor VIRTUAL for abstract classes
};

#endif
