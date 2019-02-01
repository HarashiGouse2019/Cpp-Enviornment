#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

//I used a #define preprocessor just so I can do the lines without always holding the "=" key
//and they can always be a constant amount. Using preprocessors are so much better!!!

#define BREAKLINE cout << "==================================================" << endl;

int main() {

	//We'll add some flair into this good! We'll define a grid inputted by the user that is greater or equal to 8 squared
	//So they can have a bigger sector to learn for the enemy, and I find that very interesting!!!
	
	//So from here, we'll create a new variable (and we'll simply call it defineSectorSize)

	int defineSectorSize;
	int searchPattern;
	
	bool isTargetFound = false;

	srand(time(0));

	cout << "HK Software" << endl;

	//We'll initialize some of the other variables here!
	//But first, we'll ask the user to input a number to define the area of the sector.

	getSearchPattern:
	cout << "Select what search pattern you'd wish to use? \n" 
		<< "1 - Binary \n"
		<< "2 - Linear \n"
		<< "3 - Random \n"
		<< "4 - Human  \n"
		<< endl;
	cin >> searchPattern;
	if (searchPattern == NULL) {
		cout << "A blank entry is invalid." << endl; 
		goto getSearchPattern;
	}
	else if (searchPattern != 1 || searchPattern != 2 || searchPattern != 3 || searchPattern != 4) {
		cout << "This is not an existing pattern." << endl;
		goto getSearchPattern;
	}
	else {

	getSectorSize:
		cout << "Define the size of the sector (Sector size can not be smaller than four)" << endl;
		cin >> defineSectorSize;

		//We'll then check if the input was a valid one using an if statement
		if (defineSectorSize < 4) {
			cout << "The Sector size that you have entered is invalid..." << endl;
			goto getSectorSize;

			/*They say that using a goto statement to jump to one code to another is considered to be bad code,
			but for this example I feel like I should use it since it's the quickest, despite the reputation it has.*/
		}
		else {


			//We'll save the area of the sector in a seperate variable
			int sectorArea = defineSectorSize * defineSectorSize;

			//searchGridHighNumber will be the Sector Size squared. If the user so happened to put in 8, searchGridHighNumber would be 64.
			int searchGridHighNumber = defineSectorSize * defineSectorSize,
				searchGridLowNumber = 1,
				//searchGridLowNumber while always equal to 1 no matter what!!!

				targetLocationPredictionCounter = 1,
				targetLocationPrediction,
				enemyLocation = rand() % searchGridHighNumber - searchGridLowNumber;

			//This is the key algorithm we will use. It is called Binary Search.
			cout << "Generate Randome enemy location on "
				<< defineSectorSize
				<< "x"
				<< defineSectorSize
				<< " grid..."
				<< endl;

			cout << "The enemy is located at location #"
				<< enemyLocation
				<< " on "
				<< defineSectorSize
				<< "x"
				<< defineSectorSize
				<< " grid with 1-"
				<< sectorArea
				<< " sectors."
				<< endl;

			cout << "Skynet HK-Aerial Initializing software....."
				<< endl;

			BREAKLINE;

			//Keeping this blank for now.
			while (isTargetFound == false) {



				//Software selection target location predicition in flyover hunt for enemy.
				cout << "Skynet HK-Aerial Radar sending out ping #"
					<< targetLocationPredictionCounter
					<< endl;

				// Radar Ping of enemy location

				targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

				// In this simulation the ping tells us
				// if the target location is higher or lower or right on the enem location.
				// I starget location prediction higher than enemy location

				if (targetLocationPrediction > enemyLocation) {
					//The target Location Prediction was higher than the enemyLocation
					//no need to search anymore at or above target location prediction
					//reset the searchGridHighNumber of the search Grid.
					//We subtract 1 because we don't need to search the number guessed.
					cout << "The target location prediction of "
						<< targetLocationPrediction
						<< " was higher than the actual enemy location of "
						<< enemyLocation
						<< endl;

					searchGridHighNumber = targetLocationPrediction - 1;

					cout << "searchGridHighNumber: "
						<< searchGridHighNumber
						<< endl;

					targetLocationPredictionCounter++; //targetLocationPredictionCounter = targetLocationPredictionCounter + 1;

					BREAKLINE;

				}
				else if (targetLocationPrediction < enemyLocation) {
					//The target Location  Prediction was Lower than the enemyLocation
					//no need to search anymore at or below the target location prediction
					//We add 1 because we don't need to search the number guessed.
					cout << "The target location prediction of "
						<< targetLocationPrediction
						<< " was lower than the actual enemy location of "
						<< enemyLocation
						<< endl;

					searchGridLowNumber = targetLocationPrediction + 1;

					cout << "searchGridLowNumber: "
						<< searchGridLowNumber
						<< endl;

					targetLocationPredictionCounter++; //targetLocationPredictionCounter = targetLocationPredictionCounter + 1;

					BREAKLINE;

				}
				else {
					cout << "Enemy was hiding at Sector #"
						<< enemyLocation
						<< endl;

					cout << "Target was found at Sector #"
						<< enemyLocation
						<< endl;

					cout << "Skynet took "
						<< targetLocationPredictionCounter
						<< " predictions to find the enemy location on a grid size of "
						<< defineSectorSize
						<< "x"
						<< defineSectorSize
						<< "("
						<< sectorArea
						<< ")"
						<< endl;

					isTargetFound = true;

				}
			}

			system("pause");

		}
	}

	return 0;

}

	//I broke up the cout functions the way they are because I find them going outside of the editor field
	//so doing this, no one has to scroll horizontally just to see the string.
	//It's been compressed every time << is used.
	//Honestly the code shouldn't be 171 lines long, but because I wanted everything
	//to show in one area instead of out of bounds, that's what happened.