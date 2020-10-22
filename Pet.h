#ifndef PET_H
#define PET_H

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
using namespace std;

// common functions
extern bool intPresent(int pInt, int * pIntArray, int size); // validates if int is in array

extern bool stringPresent(string pString, string * pStringArray, int size); // validates if string is in array

extern void invokeInvalidInput();

extern int valIntInput(char * inChars, int length); // validate if char* input consists of integers only

extern void nullCharArray(char *, int); // make passed char* all '\0'
// common functions

class Pet
{
	private:
		int ID;
		int age;
		string type;
		string name;
		string food;
		string toy;
	protected:
		int hunger;
		int boredness;
		int upsettedness;
		void progressAttributes(); // progression mechanic
		int memoryCapacity = 4;
		int memorySize = 0;
		string * memory; // holds what the owner has said
		void setType(string);
		void setName(string);
		void setFood(string);
		void setToy(string);
		void setID(int);
		void setAge(int);
		void checkAttributes(); // check status of basic needs
		int checkGameover();
		void gameover(int);
		void save(); // saves pet to savefile
		void talkTo();
		virtual void speak(); // speaks random item in memory
		string * getRandomFoods(int, string); // returns a random list of foods including passed item
		string * getRandomToys(int, string); // returns a random list of toys including passed item
		virtual void gameover_hunger() = 0;
		virtual void gameover_boredness() = 0;
		virtual void gameover_upsettedness() = 0;
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
		virtual void printDetails(); // debug only
		int getInteractionRange(); // get number of valid interaction options
		void printInteractionOptions(); // prints options for interaction
		virtual int interact(int) = 0;
		virtual void greet() = 0; // greet when creating/loading a pet
		void overwrite(int, int, string, string, string, string, int, int, int, int, int, string *); // overwrites object; used when loading savefile
		virtual ~Pet(); // Make destructor VIRTUAL for abstract classes
};

#endif
