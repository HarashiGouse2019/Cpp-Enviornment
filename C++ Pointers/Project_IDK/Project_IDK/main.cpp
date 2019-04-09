/****************************************************************************************************************************************************************
*														WELCOME TO THE GAME OF PURSUIT!!!!																		*
*																																								*
*										This is the first program where I've actually used pointers in my code.													*
*										I honestly didn't know what I should write a program of at first, until													*
*										this idea happened.																										*
*																																								*	
*										Putting together my current knowledge of C++, I created a simple console												*
*										where you are given a coordinate, and you go to it based on sound.														*
*																																								*
*										It actually get's harder when you get closer, for you can barely hear													*
*										anything. With that, you have to take smaller steps.																	*
*																																								*
*										You can play this game for as long as you like until you are satisfied.													*
****************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <algorithm>

using namespace std;

//Creates a line
#define BREAK cout << "-----------------------------------------------------------------------------------------------------------" << endl;
#define KEY_UP 0x48 //ASCII CODE (72) FOR THE UP KEY
#define KEY_DOWN 0x50 //ASCII CODE (80) FOR THE DOWN KEY
#define KEY_LEFT 0x4B //ASCII CODE (75) FOR THE LEFT KEY
#define KEY_RIGHT 0x4D //ASCII CODE (77) FOR THE RIGHT KEY
#define SPACE 0x20 //ASCII CODE (32) FOR THE SPACE BAR
#define RETURN 0x0D //ASCII CODE (13) FOR THE ENTER/RETURN KEY
#define ALT_UNIT Beep(0x03E8, 0x32); Beep(0x03E8, 0x32); //BEEPS TWO TIMES WITH A FREQUENCY OF 1000 AND A DURATION OF 50 MILLISECONDS
#define SHOW_POS Beep(0x1F4, 0x32); Beep(0x1F4, 0x32); //BEEPS TWOS TIME WITH A FREQUENCY OF 500 AND A DURATION OF 50 MILLISECONDS
#define MATCH Beep(0x7D0, 0xC8); //BEEPS ONE TIME WITH A FREQUENCY OF 2000 AND A DURATION OF 200 MILLISECONDS


//Create a class called Sector
class Sector {
public:
	unsigned int sectorSize = 10; //The Default Sector Size
	const unsigned int height = sectorSize; //The height of the sector
	const unsigned int width = sectorSize; //The width of the sector
};

//Create a class known as Enemy
class Enemy {
public:
	Sector sector; //Create a instance of our Sector class
	int coord_x = rand()%sector.sectorSize; //Give the enemy a random x coordinate based from the sectorSize
	int coord_y = rand()%sector.sectorSize; //Give the enemy a random y coordinate based from the sectorSize
};

//Set up prototypes
void GetPosition(int& x, int& y); //Get's the position of either my position or the enemy position
void GiveTutorial(); //Print out how to play the game
string DisplayText(string text); //Print out text
int ChangeUnitSize(int unit); //Change the amount of units you move

//Our Main Function
int main(int argc, char** argv[]) {

	Sector sector; //Create an instance of our Sector class

	int unitSize = 1; //Initialize unitSize, and give it a value of 1;

	srand(time(NULL)); //Create our random seed;

	DisplayText("Welcome Comrade!!!");
	DisplayText("There has been an enemy sighted nearby.");

	Enemy enemy; //Create an instance of our Enemy class

	DisplayText("The enemy is sighted at: "); /*Grab the enemy's coordinate. This will only be displayed once*/ GetPosition(enemy.coord_x, enemy.coord_y);

	GiveTutorial(); //Print out our tutorial
	
	//Our person spawns at the center of our sector
	int coord_x = sector.height/2;
	int coord_y = sector.width/2;

	//Then we create pointers to our coordinate!
	int * ptrx = &coord_x;
	int * ptry = &coord_y;

	bool MATCH_X = false; //Set a boolean to check if our x coordinates match
	bool MATCH_Y = false; //Set a boolean to check if our y coordinates match

	//The Actual Movement Begins
	int c = 0; //Initialize c to toggle from 0 to 1 when we send input
	while (1)
	{
		c = 0;
		//We set if the input value is true through a switch...case statement
		switch ((c = _getch())) {
		case KEY_UP:
			MATCH_Y = false;
			system("CLS"); //Clear the console
			cout << "--- CURRENTLY IN PURSUIT---" << endl; //Print out CURRENTLY IN PURSUIT
			*ptry += unitSize; //MoveUp
			Beep(((max(*ptry, enemy.coord_y) - min(*ptry, enemy.coord_y)) % 0x7FFF), 0x64); //Send a sound to let us know that we are getting closer
			break;

		case KEY_DOWN:
			MATCH_Y = false;
			system("CLS"); //Clear the console
			cout << "--- CURRENTLY IN PURSUIT---" << endl; //Print out CURRENTLY IN PURSUIT
			*ptry -= unitSize; //MoveDown
			Beep(((max(*ptry, enemy.coord_y) - min(*ptry, enemy.coord_y)) % 0x7FFF), 0x64); //Send a sound to let us know that we are getting closer
			break;

		case KEY_LEFT:
			MATCH_X = false;
			system("CLS"); //Clear the console
			cout << "--- CURRENTLY IN PURSUIT---" << endl; //Print out CURRENTLY IN PURSUIT
			*ptrx -= unitSize; //MoveLeft
			Beep(((max(*ptrx, enemy.coord_x) - min(*ptrx, enemy.coord_x)) % 0x7FFF), 0x64); //Send a sound to let us know that we are getting closer
			break;

		case KEY_RIGHT:
			MATCH_X = false;
			system("CLS"); //Clear the console
			cout << "--- CURRENTLY IN PURSUIT---" << endl; //Print out CURRENTLY IN PURSUIT
			*ptrx += unitSize; //MoveRight
			Beep(((max(*ptrx, enemy.coord_x) - min(*ptrx, enemy.coord_x)) % 0x7FFF), 0x64); //Send a sound to let us know that we are getting closer
			break;

		case SPACE:
			system("CLS");
			SHOW_POS; //Beep 2 times to get our current position
			cout << "\nCurrent Position: "; //Print out
			GetPosition(*ptrx, *ptry);      //our current position
			break;

		case RETURN:
			system("CLS"); //Clear Console
			ALT_UNIT; //Beep 2 time to allow us to change our unit
			unitSize = ChangeUnitSize(unitSize); //Gather input
			break;

		default:
			cout << endl << "\b" << endl;  //Backspace
			break;

		}

		//If the x coordinates match
		if (MATCH_X == false) {
			if (*ptrx == enemy.coord_x) {
				MATCH; //Make a noise
				MATCH_X = true; //Set MATCH_X to TRUE
			}
			else {
				MATCH_X = false; //Set MATCH_X to FALSE
			}
		}

		//If the y coordinates match
		if (MATCH_Y == false) {
			if (*ptry == enemy.coord_y) {
				MATCH; //Make a noise
				MATCH_Y = true; //SET MATCH_Y to TRUE
			}
			else {
				MATCH_Y = false; //SET MATCH_Y to FALSE
			}
		}

		//If both x and y coordinates are matching
		if (*ptrx == enemy.coord_x && *ptry == enemy.coord_y) {
			MATCH; MATCH_X = false; MATCH_Y = false; //Make a noise and set both MATCH_X, and MATCH_Y to FALSE
			sector.sectorSize *= 10;
			enemy.coord_x = rand() % sector.sectorSize; //Regenerate a new location on the x coordinate
			enemy.coord_y = rand() % sector.sectorSize; //Regenerate a new location on the y coordinate
			DisplayText("You've encountered the enemy, but he got away!"); //A message to use
			DisplayText("The enemy's new position is: "); GetPosition(enemy.coord_x, enemy.coord_y); //Give us the enemy's new position
		}

	}
	
	system("pause");
	return 0;
}

//Gets the position of a certain object (whether it'd be me, or the enemy)
void GetPosition(int& x, int& y) {
	cout << "(" << x << "," << y << ")" << endl;
}

//Show Directions
void GiveTutorial() {
	BREAK;
	cout << "Move will arrow keys" << endl;
	cout << "Print your current position with <Space>" << endl;
	cout << "If you feel like it'll take long, you can change the amount of steps with <Return>... \nThe default is always 1 unit" << endl;
	cout << "\n You will only be given the enemy's location at the start of the pursuit." << endl;
	cout << "The enemy himself will be moving as well, making this a bit harder." << endl;
	cout << "Rely on the sounds given to you, however if you ever get closer to the enemy, the sound's frequency will lower, \nalso adding in the difficulty." << endl;
	cout << "Have fun, and good luck!!!" << endl;
	BREAK;
}

//Displays Text on the Console
string DisplayText(string text) {
	string * ptrText = &text; //Create a pointer for our text
	cout << *ptrText << endl; //Print our parameter to the console
	return *ptrText; //Return our pointer
}

int ChangeUnitSize(int unit) {
	int * ptr_unit = &unit; //Create a pointer for our unit
	int oldUnit, newUnit; //Create 2 variables, our old unit, and our new unit
	cout << "\nChange unit size: " << *ptr_unit << " >> "; /*Gather input*/cin >> newUnit;

	//If our input is not an integer, we give our unit our default value of 1
	if (cin.fail()) {
		cerr << "!!!INVALID INPUT!!!" << endl;
		newUnit = 1;
	}

	cin.clear(); cin.ignore(INT_MAX, '\n'); //Clear cin's stream buffer, and ignore any other stuff.
	oldUnit = *ptr_unit; //We assign our current unit to the oldUnit variable before updating our unit value
	*ptr_unit = newUnit; //Update our unit through our pointer
	cout << "\nYou set unit size from " << oldUnit << " >> " << newUnit; //Print out our changes
	return *ptr_unit; //Return our pointer

}