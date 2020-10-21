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
#include "Cat.h"
using namespace std;

Cat::Cat() : Pet()
{
	this->setType("Cat");
	this->setFood("Fish");
	this->setToy("Laser");
}

Cat::Cat(string pName, int pAge) : Pet(2, pName, "Fish", "Laser", pAge)
{
}

void Cat::art_purr()
{
	// using raw string literal
	cout << "\n" << R"(                                                            
                                                                                                                     (%%%%%#(//***                                                                      
                                                        ,#######,                                   ,(######*                                                                                           
                                                       (##(///(#####/           ....            /#####(////##(                                                                                          
                                                       ###/**//////####(/##################/.(####///////,/###                                                                                          
                                                       ###/,,**//////####(/////////////////####////////,*,/###                                                                                          
                                                       (##/*,,,,*/###//////////////////////////###(//,,,,,/###                                                                                          
                                                       /##(*,,,,,*//////////////////////////////////,,,,,,/##(                                                                                          
                                            ..    ,    ,##(*,,,,*////////////////////////////////////,,,,,(##,   .,                                                                                     
                                      *//   //.  ,//    ###*,,,////////,//////////////////,///////////*,,*###    //.   //   ///                                                                         
                                      //  *//   .//*    *##/*////////../*.//////////////.,(,.///////////*/##/    //*   .//,  */*                                                                        
                                         ,//   //*      ###////////////.*/.*///////////.//.*//////////////###/     //*  .//.                                                                            
                                         *.   .//     .###/////////////////////////////////////////////////####.   .//    */*                                                                           
                                            *///.     ###/////#########////////////////////#########(////////####   *//,                                                                                
                                                     (##//////////////(###(////////////(###(///////////////////####.  .*,                                                                               
                                                    *##(/////////////////(#////////////##/////////////////////////####,                                                                                 
                                                    ###//////*****///////////((####(/////////////////////////////////#####(.                                                                            
                                                   /##(//////////////*..*,**##/,,,,(##/,,,*...*//////////////////////////(#####(.                                                                       
                                                  .###//////...,,,,,..,,,,,,,*######/,,,,,,**,.......,/////////////////////(#########*                                                                  
                                                  ,##(////////////////*,,,,,,,*,###,,,,,,,,,*//////////////////////////////####////#######*                                                             
                                                  (##///////////////////####(####/##%((####///////////////////////////////####(////#####/#####(.                                                        
                                                  ###////////////////////////////////////////////////////////////////////####(////#####////#######(                                                     
                                                 .###//////////////////////////////////////////////////////////////////(####/////#####/////####//(####*                                                 
                                                 .###/////////////////////////////////////////////////////////////////(###//////#####/////####(//////####.                                              
                                                 .###/////////////////////////////////////////////////////////////////////////######/////####(/////////(###*                                            
                                                  ###//////////////////////////*,,,,,,,*/////////////////////////////////////#####/////(####//////////////###,                                          
                                                 .###//////////////////////*,,*,,,,,,,,,,,**//////////////////////////////////////////####(/////////////////###                                         
                                                  ###/////////////////////,,,,,,,,,,,,,,,,,,,,///////////////////////////////////////////////////////////////###.                                       
                                                  /##////////////////////,,,,,,,,,,,,,,,,,,,,,,*//////////////////////////////////////////////////////////////###                                       
                                                  .###//////////////////,*,,,,,,,,,,,,,,,,,,,,,,*/////////////////////////////////////////////////////////////(##/                                      
                                                   ###//////////////////,,,,,,,,,,,,,,,,,,,,,,,,,//////////////////////////////////////////////////////////////###                                      
                                                   /##(/////////////////,,,,,,,,,,,,,,,,,,,,,,,,,//////////////////////////////////////////////////////////////(##,                                     
                                                    ###/////////////////,,,,,,,,,,,,,,,,,,,,,,,,,*/////////////////////////////////////////////////////////////(##,                                     
                                                    *##(////////////////*,,,,,,,,,,,,,,,,,,,,,,,**///////////////////////////////////////////////////////(#(///###.                                     
                                                     ###/////////////////,*,,,,,,,,,,,,,,,,,,,,,,*//////////////////////////////////////////////////////##(////###                                      
                                                     .###/////////////////,,,,,,,,,,,,,,,,,,,,,,,//////////////////////////////////////////////////////##/////###.                                      
                                                      .###/////////////////,*,,,,,,,,,,,,,,,,,*,*///////////////////////////////////////////////////###//////(##*                                       
                                                       .###//////////////(#(,,,,,,,,,,,,,,,,,,,*(#(//////////////(///////////////////////////////###(///////###*                                        
                                                         ###(/////////////##(*,,,,,,,,,,,,,,,,*(#(/////////////##////////////////////////////####//////////###,                                         
                                                          *###/////////////(##*,,,,,,,,,,,,,,,##/////////////(##//////////((((#############(/////////////####                                           
                                                            (###////////////,##/,,,,,,,,,,,,###*////////////##/////####/*,,,,,*////////////////////////####.                                            
                                                              (###,*////*,,,,,/##,*,,,,,,,/##,,,*/////////##(////(#(,*,,,,,,,////////////////////////####                                               
                                                    ..,*********(####,,*,,,,,,,,##*,,**,*##/,*,,,,*,*,,###///////##,*,,,,,,,,////////////////////(####/*******,.                                        
                                                 ,*****************(####/,,,,,*,*#########*,,,,,,,,*################*,,,,,,,,,//////////////(#####(*,**************                                     
                                                    ,,****************/(###########/***##############/************/######/******,/(##########(/****************,.                                       
                                                              ...,,,******,*,,***********/((((((/,********************/((#########(((/*,,*******,,,,,.                                                  
                                                                                                  ...............     .                                                                                                                                                                                                                                                                                                                
	)" << "\n";
}

void Cat::speak()
{
	cout << "Meow~\n";
	srand(time(0));
	cout << "(Translation: " << memory[rand() % (memorySize)] << "?)\n";
}

void Cat::printDetails()
{
	this->Pet::printDetails();
}

int Cat::interact(int pInt)
{
	if (this->checkGameover() != 0) {
		this->gameover(this->checkGameover());
		return 1;
		}
	else {
		switch (pInt) {
			case 0: {
				this->save();
			}
			break;
			case 1: {
				int numFoods = 4;
				string * availableFoods = getRandomFoods(numFoods, this->getFood());
				cout << "What would you like to feed me with?\n";
				for (int i = 0; i < numFoods+1; i++) {
					if (i == 0) {cout << "0. Return to previous menu\n";}
					else {cout << i << ". " << availableFoods[i-1] << "\n";}
				}
				char tempChoiceChars[1024] = {'\0'}; // input validation.
				int tempChoice = -1;
				while (1) {
					nullCharArray(tempChoiceChars, 1024);
					cin >> tempChoiceChars;
					tempChoice = atoi(tempChoiceChars);
					if (valIntInput(tempChoiceChars, 1024) == 1 && tempChoice >= 0 && tempChoice < numFoods+1) {break;}
					invokeInvalidInput();
				} // input validation.
				if (tempChoice == 0) {break;}
				else if (this->getHunger() > 2) {
					if (availableFoods[tempChoice-1].compare(this->getFood()) == 0) {
						srand(time(0));
						hunger = rand()%3;
						if (upsettedness > 0) {upsettedness--;}
						if (boredness > 0) {boredness--;}
						cout << "Yum yum!\n";
					}
					else {
						if (upsettedness < 15) {upsettedness++;}
						cout << "Yuck!!! Why would you feed me this?!\n";
					}
				}
				else {cout << this->getName() << " the " << this->getType() << " is not hungry and has gracefully rejected your feeding attempt.\n";}
				delete[] availableFoods;
				this->progressAttributes();
			}
			break;
			case 2: {
				if (this->getUpsettedness() >= 12) {
					cout << "Go away!!! I'm still hating you for what you did!\n";
					srand(time(0));
					if ((rand() % 10) < 2) {
						cout << "Your pet " << this->getType() << " swatted on and scratched your petting hand a little too hard and you had to go to the ER.\n";
						this->gameover(3);
						return 1;
					}
				}
				else if (this->getUpsettedness() >= 4 && this->getUpsettedness() < 12){
					if (rand() % 10 < 5) {
						cout << "I'm still a little mad about what you did, but thank you for petting me, I guess - -\n";
						upsettedness -= 2;
						if (boredness > 2) {boredness -= 3;}
					}
					else {
						cout << "Meh\n";
					}
				}
				else {
					cout << "Thank you for petting me~~~\n";
					if (upsettedness > 1) {upsettedness--;}
					if (boredness > 2) {boredness -= 3;}
				}
				this->progressAttributes();
			}
			break;
			case 3: {
				int numToys = 4;
				string * availableToys = getRandomToys(numToys, this->getToy());
				cout << "How would you like to play with me?\n";
				for (int i = 0; i < numToys+1; i++) {
					if (i == 0) {cout << "0. Return to previous menu\n";}
					else {cout << i << ". " << availableToys[i-1] << "\n";}
				}
				char tempChoiceChars[1024] = {'\0'}; // input validation.
				int tempChoice = -1;
				while (1) {
					nullCharArray(tempChoiceChars, 1024);
					cin >> tempChoiceChars;
					tempChoice = atoi(tempChoiceChars);
					if (valIntInput(tempChoiceChars, 1024) == 1 && tempChoice >= 0 && tempChoice < numToys+1) {break;}
					invokeInvalidInput();
				} // input validation.
				if (tempChoice == 0) {break;}
				else if (availableToys[tempChoice-1].compare("Throw") == 0) {
					cout << "Why the heck would you throw me??\n";
					if (upsettedness == 14) {upsettedness++;}
					else if (upsettedness < 14) {upsettedness += 2;}
				}
				else if (boredness > 2) {
					if (availableToys[tempChoice-1].compare(this->getToy()) == 0) {
						double tempBoredness = (double)boredness;
						boredness = floor(tempBoredness/2);
						if (upsettedness > 0) {upsettedness--;}
						cout << "Thank you for playing with me~~~\n";
					}
					else {
						cout << "Meh\n";
					}
				}
				else {
					cout << this->getName() << " the " << this->getType() << " is too preoccupied with something else and has gracefully ignored your playing attempt.\n";
				}
				delete[] availableToys;
				this->progressAttributes();
			}
			break;
			case 4: {
				this->talkTo();
				this->progressAttributes();
			}
			break;
			case 5: {
				srand(time(0));
				int randomChoice = rand()%2;
				switch (randomChoice) {
					case 0: {
						cout << "You are doing your OOP project and ignoring your pet " << this->getType() << ", " << this->getName() << ". \n";
						if (hunger >= 12) {cout << "You notice your pet " << this->getType() << " " << this->getName() << " scratching at the window screen. It seems it's up to something...\n";}
						else {
							if (upsettedness < 4 && boredness >= 6) {
								if (rand()%10 < 5) {
									cout << "Your pet " << this->getType() << " " << this->getName() << " comes snuggling up against you and sits on your keyboard. Purrr~~\n";
									this->art_purr();
								}
								if (memorySize > 0) {
									cout << "Your pet " << this->getType() << " " << this->getName() << " says: ";
									this->speak();
								}
							}
						}
					}
					break;
					case 1: {
						cout << "You are eating a meal and ignoring your pet " << this->getType() << ", " << this->getName() << ". \n";
						if (hunger >= 12) {cout << "You notice your pet " << this->getType() << " " << this->getName() << " scratching at the window screen. It seems it's up to something...\n";}
						else if (upsettedness < 6) {
							double hungerRatio = (double)hunger/15.0*100.0;
							srand(time(0));
							if (rand()%100 < hungerRatio) {
								cout << "Your pet " << this->getType() << " " << this->getName() << " walks next to you and meows loudly. It seems it wants something.\n";
							}
						}
						else {cout << this->getName() << " does not seem to care.\n";}
					}
					break;
				}
				this->progressAttributes();
			}
			break;
		}
		return 0;
	}
}

void Cat::greet()
{
	if (this->getAge() == 0) {cout << "MEOW~~~ Greetings to you my dear owner, please take good care of me!\n";}
	else {cout << "MEOW~~~ Greetings to you my dear owner, nice to see you again~\n";}
}

void Cat::gameover_hunger()
{
	cout << "Weeeeee... I'm starving to death, you irrsponsible owner!!! But don't worry, an exact replica of myself down to the molecules has been created so you can try again.\n";
}

void Cat::gameover_boredness()
{
	cout << this->getName() << " the " << this->getType() << " is not responding. Rebooting...\n";
}
	
void Cat::gameover_upsettedness()
{
	cout << "MEEEEEOOOOOWWW!!! That does it!!! *Proceeds to scratch your eyes right out and you're now blind.*\n";
}

Cat::~Cat()
{
	delete[] memory;
}
