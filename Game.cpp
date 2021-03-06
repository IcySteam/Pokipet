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

void Game::art_logo()
{
	// using raw string literal
	cout << "\n" << R"(                                                            
                                                                       .,,*****,,.                             .,*/(######(/,..                                                                         
                                                             .,/#%#%%##%%#####%####%%##%%##(*,.      .,/##%####%##%#%#####%%###%%####/..                                                                
                                                         ./#%%%%#%%%##%%######%%##%%###%#####%#%%###%%%######%########%###%########%#%#%%#/,                                                            
                                                      .(#%##%###########################################################################%%%%%#*                                                         
                                                    *#######%%###########################################################################%%####%#,                                                      
                                                  *##%#################%#########%%###########################%####%%########%###%##%%#############*                                                    
                                                ,###%#%##############%%##///////(####%###%%###################%##%%#(/////*/(##%%###################%,                                                  
                                               *%%##%#%#############(*,***************(#%#%###################%(*,**,***,,***,,**(###%##############%%/                                                 
                                              /%#############%####*,,*******,***,***,****##%############%#%%(*,,,*,,,***,***,****,,/#%%############%%#%(                                                
                                             /%#%#############%#********,*************,**,/##############%#*,,,,,,********,,,*,*,,**,/%##############%#%#                                               
                                            *%#%#############%#/,,**************,********,**#%#%##########******,***************,*****/####%#############/                                              
                                           ,####%#############/**,*********************,,***/%#%#%#######/**,*******************,******(%###%#############,                                             
                                        ,/#%#%################**,*,*****,*******,*******,****###%########*******,*******,*******,******/#%#%##############(*                                            
                                    *(#%#%####################**,**,*************************(%#%#######(,**********************,******/###%#############%%###/.                                        
                                 /%###%#######################(*,***************,************##%#########*,*,***,***************,******(###%#############%#%#%###(.                                     
                             ./#%#%####%###%%##%%############%#/,*,*******************,*****/#%########%#/,*************************,,/#%######################%##%#/.                                  
                           *#%#%%%%##%#%#####%#%##############%#/*,*,*,*,*,*,*,*,*,*,***,*,/%%#%%######%%#****,*,*,*,*,*,*,*,*,*,*,,*(%%#%%%%##################%#####%(,                                
                         /####%%#%%#%#%##/********(########%##%%%#/**,**,,***,********,***/%##%##%#########/****,**,******,,**,**,,/#%##%%%%#%%%%%#%#######%%###%%#%#####*                              
                       ,####%%#%#%%##*,,**,*********,,*(#%#%###%%#%#/***,*****,**,,***,*(#%#%%%%#%#########%#/**,***********,****(%#%%##%%#%###(*,*,****,***,,*(#%#%#%#%###,                            
                      /###%#%#%#%#(**,****,**********,,*,*#%#%%#######%#/***********/(#%%###%%%###############%#(/***********(##%####%####%#/*,*,,*****,,,****,*,*(%#####%#%/                           
                     *#%######%%#*,*,***,*******,*******,**/##############%%%%###%%%##########################%##%%#%%###%###%%#######%%##/*,***,*******,******,**,*###%%##%#(.                         
                    .###%#######*,*,*******************,*,,*/############%%%%#################################%#####%%%%%%%#############%/*********************,*****#%#%%#%##(                         
                    *###%######/,**,************,******,*****(%##%#####################################################################%/*,*,***,***************,*****#%%##%###/                        
                    /##########**,*********************,******#%#%#####################################################################(,***********************,*****/%#%####%(                        
                    ,##%#######*,**,****,***,***,***,***,***,*#%#%#%###################################################################(*,**,***,***,***,***,***,***,,/#%#%##%#(                        
                     (#%%######/****,******************,**,,*/%#%##%%##%%##%%##%%####%%%##%%############%%##%#%##########%%###%%#######(*,**********************,****,(##%%%%##,                        
                     ,##########**,*************,**********,,#%####%##%#(/**,***,******,*(#################(/******,,*******/(#%########********,***************,****/#%####%%/                         
                      *%##%#%##%#/*,*******************,*,*,(%#%%%%#(****,******************/##%%#%#%#%#(*,*,,***************,,*/#%#%%#%(*,**********************,*,/#%####%%(.                         
                       ,######%##%#/,***,,******,*******,,*#%#%#%#/*************,*******,*****,(#%%###/,,**,,***,*******,********,*(%###%#*,****,*******,*******,**(###%###%(                           
                        ,(%##%#%#%###(*,*****************#%#%###(***,,*****************,*,***,***#%%(,*,****,*******************,**,/##%#%%/****,****************#%%###%###,                            
                          *#%#%######%%%#(/***,**,**/(#%%####%#(*,,*************,************,,*,,/**,**********,****************,**,*#%%##%%#/*,********,***/#####%##%#%#.                             
                           .(#%######%#%%#%##%%###%%##%#####%##****,***************************,,***,,,*************************,*,***/%###%##%##%###((####%########%%#(.                               
                             .(#%##%###########################*,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,**,*/#########################%##%%#.                                 
                               .(%#############################*,*******************************,*******************************,***,*/##%##%###################%#%(.                                   
                                 .(%###%##%###################%/,*,*************,***************,***************,****************,****(##%###############%#%#####/                                      
                                    ,#%######################%##********************************,*******************************,,**,/#####################%#%#*                                        
                                      /#%#####################%##*,*****,*******,*******,*******,*******,*******,*******,***********/####################%###*                                          
                                       ##%####################%###/*,,**************************,*******************************,**/#%####################%%,                                           
                                        #####################%#%##%(*,*,,*******,***************,***************,***************,*###%#####################.                                            
                                        .#######%###################%(*,,*****,,****************,**************************,**,*(##################%#%####.                                             
                                         ,#%%%%#####################%##/,*****,*,***,***,***,***,***,***,***,***,***,***,*****#%######################%#(                                               
                                          .#########################%#%%#(*,********************,**************************/###%#######################*                                                
                                           .(%##############################**,*,****,**********,*************,******,**/#%##%#####################%#%,                                                 
                                             /%%##########################%#%%#**,**,***********,**************,**,,*(#%##%#########################(                                                   
                                              ,####%#%%#########################%#(****,********,***,,**,*******/(############################%%#%#,                                                    
                                                (#%#%%###############################%##(**,*,,,****,,,**,*(##%###%#############################%*                                                      
                                                 .(#%%###########################%%#%%%####%%%########%%#%###%%%###%%########################%%/                                                        
                                                   ./%#%#%%#%#########################################################################%###%%#*                                                          
                                                      ,(#%#%##########################################################################%###(.                                                            
                                                         ./%%####%####%%##%%%%%####%%%%%%%##%###%%%%###%####%%###########%######%#%%%##*.                                                               
                                                              ,/#%%%%##%##%###%#########%%%%#%%%%########%%#%%%%#%%%%%%%####%%###(*.                                                                    
                                                                       ..,**/////**,,..                       ..,,****,,..                                                                                                                                                                                                                                                                                                            
	)" << "\n";
}

Game::Game()
{
	system("clear");
	cout << "Welcome to Pokipet!\n";
	this->art_logo();
	cout << "Please enter your choice: \n";
	cout << "0. Load existing pet\n"; // load exitsing pet from save file
	cout << "1. Adopt a dog!\n";
	cout << "2. Adopt a cat!\n";
	cout << "3. Surprise me!\n"; // create random pet
	int numChoices = 4;
	char roundChoiceChars[1024] = {'\0'}; // input validation.
	int roundChoice = -1;
	while (1) {
		nullCharArray(roundChoiceChars, 1024);
		cin >> roundChoiceChars;
		roundChoice = atoi(roundChoiceChars);
		if (valIntInput(roundChoiceChars, 1024) == 1 && roundChoice >= 0 && roundChoice < numChoices) {break;}
		invokeInvalidInput();
	} // input validation.
	string nameChoice;
	if (roundChoice == numChoices-1) {
		srand(time(0));
		roundChoice = (rand() % 2) + 1;
	}
	switch (roundChoice) {
		case 0: { // loads pet from savefile
			ifstream savefile;
			while (1) {
				cout << "Please input your file name: \n";
				nameChoice = "";
				cin >> nameChoice;
				savefile.open(nameChoice);
				if (savefile.fail()) {cout << "Failed to open file!\n";}
				else {break;}
			}
			int inID, inAge, inHunger, inBoredness, inUpsettedness, inMemoryCapacity, inMemorySize;
			string inType, inName, inFood, inToy;
			string * inMemory;
			string line;
			int iter = 0;
			while (getline(savefile, line)) { // goes line by line and overwrite acquired attributes to new pet object later
				if (iter == 0) {
					inID = stoi(line);
					if (inID == 1) {currentPetPtr = new Dog();}
					else if (inID == 2) {currentPetPtr = new Cat();}
				}
				else if (iter == 1) {inAge = stoi(line);}
				else if (iter == 2) {
					if (!line.empty() && line[line.length()-1] == '\n') {line.erase(line.length()-1);}; // truncates string if ending ith newline
					inType = line;
				}
				else if (iter == 3) {
					if (!line.empty() && line[line.length()-1] == '\n') {line.erase(line.length()-1);};
					inName = line;
				}
				else if (iter == 4) {
					if (!line.empty() && line[line.length()-1] == '\n') {line.erase(line.length()-1);};
					inFood = line;
				}
				else if (iter == 5) {
					if (!line.empty() && line[line.length()-1] == '\n') {line.erase(line.length()-1);};
					inToy = line;
				}
				else if (iter == 6) {inHunger = stoi(line);}
				else if (iter == 7) {inBoredness = stoi(line);}
				else if (iter == 8) {inUpsettedness = stoi(line);}
				else if (iter == 9) {
					inMemoryCapacity = stoi(line);
					inMemory = new string[inMemoryCapacity];
					}
				else if (iter == 10) {inMemorySize = stoi(line);}
				else {
					if (!line.empty() && line[line.length()-1] == '\n') {line.erase(line.length()-1);};
					inMemory[iter-11] = line; 
					}
				iter++;
			}
			currentPetPtr->overwrite(inID, inAge, inType, inName, inFood, inToy, inHunger, inBoredness, inUpsettedness, inMemoryCapacity, inMemorySize, inMemory);
			cout << currentPetPtr->getName() << " the " << currentPetPtr->getType() << " has been successfully loaded!\n";
			savefile.close();
		}
		break;
		case 1: {
			cout << "Name your dog!\n";
			cin >> nameChoice;
			currentPetPtr = new Dog(nameChoice, 0);
		}
		break;
		case 2: {
			cout << "Name your cat!\n";
			cin >> nameChoice;
			currentPetPtr = new Cat(nameChoice, 0);
		}
		break;
	}
}

int Game::play()
{
	if (roundCount == 0) {currentPetPtr->greet();}
	currentPetPtr->printInteractionOptions();
	char roundChoiceChars[1024] = {'\0'}; // input validation.
	int roundChoice = -1;
	int output = 0;
	while (1) {
		nullCharArray(roundChoiceChars, 1024);
		cin >> roundChoiceChars;
		roundChoice = atoi(roundChoiceChars);
		if (valIntInput(roundChoiceChars, 1024) == 1 && roundChoice >= 0 && roundChoice < currentPetPtr->getInteractionRange()) {
			output = currentPetPtr->interact(roundChoice);
			roundCount++;
			break;
		}
		invokeInvalidInput();
	} // input validation.
	return output;
}

Game::~Game()
{
	delete currentPetPtr;
}
