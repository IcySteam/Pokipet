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
#include "Dog.h"
using namespace std;

Dog::Dog() : Pet()
{
	type = "Dog";
	food = "Bone";
	toy = "Ball";
}

Dog::Dog(string pName, int pAge) : Pet(1, pName, "Bone", "Ball", pAge)
{
	
}

void Dog::art_wagTail()
{
	// using raw string literal
	cout << "\n" << R"(                                                            
                                                                           /         /                                                                                                                      
                                                                         //.       ///,                                                                                                                 
                                                                           ///////////////////////////////                                                                                              
                                                                               /////////////////////////////                                                                                            
                                                                              ///////////////////////////////                                                                                           
                                                                            @@@@ @####@@@@@######///////##///                                                                                           
                                                          .@@@@@@@@@@@@@@@@@@  .@@@##@   @@@######/////####//                                                                                           
                                                       @@&&&&&&&&&&&&@@@@@@@@@@@@@(((@@@@@@@#(/////////####//,                                                                                          
                                                      @&&&&&&&&&&@@@@@@@@@@@@@@///////////////////////(#####//                                                                                          
                                                      @@&&&&&&@@@@@@@@@@@@@@@@////////////////////////######///                                                                                         
                                                       @@&&&&@@@@@@@@@@@@@@@@/////////////////////////#######//                                                                                         
                                                        @@&&@@@@@@@@@@@@@@@//////////////////////////########(/                                                                                         
                                                         (@@@@@@@@@@@@@@/////////////////////////////#########                           (########*,                                                    
                                                          //@@@@@@@@@////////////////////////////////#########(                             ##########**                                                
                                                           //////////////////////////////////////////##########                               ###########,.                                             
                                                             *//////////////////////////((((/////////##########                                ############,,                                           
                                                                        /////////(((((((((((((///////(#######,                                  ############,,                                          
                                                                                  (((((((((((//////////(#*                                    ##############,,,,                                        
                                                                                  (((((((((///////(#######                                      /###########,,,,, ,,                                    
                                                                                ##########################                                        .#########(,,,,,,,,                                   
                                                                                #########################                                           #########,,,,,,,,,                                  
                                                                                (((((///////////////////                                            #########,,,,,,,,*                                  
                                                                               ((((////*,,,,,,//////////////                                       ######,###,,,,,,,,,                                  
                                                                              ((((////*,,,,,,,,,//////////////                                     #######/,,,,,,,,*,                                   
                                                                             ((//////,,,,,,,,,,,,///////////////,                                 #########,,,,,,,*.                                    
                                                                            /////,,,,,,,,,,,,,,,,/////////////////                               (#########,,,,,,*                                      
                                                                           //////,,,,,,,,,,,,,,,,*//////////////////                            *########(,,,,,,                                        
                                                                           /////,,,,,,,,,,,,,,,,,,///////////////////                         ##########,,,,,*,                                         
                                                                          /////,,,,,,,,,,,,,,,,,,,///////////////////*                  ##############,,,,,,*                                           
                                                                          /////,,,,,,,,,,,,,,,,,,,*///////////////////        *#####################,,,,,,,,,,,*                                        
                                                                          /////,,,,,,,,,,,,,,,,,,,,////////////////////,(#######################*,,,,,,,,,,,,,                                          
                                                                          ////,,,,,,,,,,,,,,,,,,,//////////////////////*,,,,*################,,,,,,,,,,,,,*                                             
                                                                          /////*,,,,,,,,,,,,,,,,,*//////////////////////  ,,*,,,,,#######(,,,,,,,,,,,,.                                                 
                                                                          /////,,,,,,,,,,,,,,,,,,,*//////////////#####/////                                                                             
                                                                         (#####,,,,,,,,,,,,,,,,,,,,,,*//////////(######/*                                                                               
                                                                      //########,,,,,,,,,,,,,,,,,,,,########////////*                                                                                   
                                                                          (##(  ,*         .*,,,,,,,########                                                                                                                                
	)" << "\n";
}

void Dog::speak()
{
	cout << "Woof woof!\n";
}

void Dog::setNull()
{
	type = "?";
	name = "?";
	food = "?";
	toy = "?";
	ID = -1;
	age = -1;
	hunger = -1;
	boredness = -1;
	upsettedness = -1;
	type = "Dog";
	food = "Bone";
	toy = "Ball";
}

void Dog::printDetails()
{
	cout << name << " the " << age << "-day old " << type << " with type ID " << ID << "\n";
	cout << "Food: " << food << ", Toy: " << toy << "\n";
	this->speak();
	this->art_wagTail();
}

void Dog::save()
{
	
}

void Dog::interact(int pInt)
{
	if (this->checkGameover() != 0) {this->gameover(this->checkGameover());}
	else {
		switch (pInt) {
			case 0: {
				this->save();
				cout << this->getName() << " the " << this->getType() << " has been successully saved.\n";
			}
			break;
			case 1: {
				string * availableFoods = getRandomFoods(4, "Bone");
				cout << "What would you like to feed me with?\n";
				for (int i = 0; i < 4; i++) {
					cout << i << ". " << availableFoods[i] << "\n";
				}
				char * tempChoiceChars = nullChars; 
				int tempChoice = -1;
				while (1) {
					tempChoiceChars = nullChars;
					cin >> tempChoiceChars;
					tempChoice = atoi(tempChoiceChars);
					if (valIntInput(tempChoiceChars, 1024) == 1 && tempChoice >= 0 && tempChoice < 4) {break;}
					invokeInvalidInput();
				}
				if (availableFoods[tempChoice].compare(food) == 0) {
					if (hunger > 0) {hunger--;}
					if (upsettedness > 0) {upsettedness--;}
					if (boredness > 0) {boredness--;}
					cout << "Yum yum!\n";
				}
				else {
					if (upsettedness < 15) {upsettedness++;}
					cout << "Yuck!\n";
				}
				delete[] availableFoods;
			}
			break;
			case 2: {
				
			}
			break;
			case 3: {
				
			}
			break;
			case 4: {
				
			}
			break;
			case 5: {
				
			}
			break;
		}
		if (hunger < 15) {hunger++;}
		if (boredness < 15) {boredness++;}
		age++;
	}
}

void Dog::greet()
{
	cout << "WOOF~~~ Greetings to you my dear owner, please take good care of me!\n";
}

void Dog::gameover_hunger()
{
	
}
	
void Dog::gameover_upsettedness()
{
	
}
void Dog::gameover_boredness()
{
	
}

Dog::~Dog()
{
	
}
