///Skynet Radar User Defined Scan(64-Bit)
/*This program will allow the user to choose which kind of search to
run.
You are allowed to define a sector size of your choosing*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

//I used a #define preprocessor just so I can do the lines without always holding the "=" key
//and they can always be a constant amount. Using preprocessors are so much better!!!

#define BREAKLINE cout << "==================================================" << endl;
#define WAIT cout << "(......)" << endl;
#define NEWLINE cout << "\n" << endl;

int main() {

	//We'll add some flair into this good! We'll define a grid inputted by the user that is greater or equal to 8 squared
	//So they can have a bigger sector to learn for the enemy, and I find that very interesting!!!
	
	//So from here, we'll create a new variable (and we'll simply call it defineSectorSize)
	bool isProgramRunning = true;

	while (isProgramRunning) {
		int defineSectorSize,
			sectorArea,
			searchGridHighNumber,
			searchGridLowNumber,
			targetLocationPrediction,
			targetLocationPredictionCounter,
			enemyLocation,
			varContinue;
		int searchPattern = NULL;

		bool isTargetFoundBinary = false,
			isTargetFoundLinear = false,
			isTargetFoundRandom = false,
			isTargetFoundHuman = false,


			srand(time(0));



		varContinue = 0;
		searchPattern = NULL;

		cout << "HK Software" << endl;

		//We'll initialize some of the other variables here!
		//But first, we'll ask the user to input a number to define the area of the sector.

		cout << "What search pattern will you use? \n"
			<< "1 - Binary \n"
			<< "2 - Linear \n"
			<< "3 - Random \n"
			<< "4 - Human \n"
			<< endl;

		cin >> searchPattern;

		//Binary Search Selected
		if (searchPattern == 1) {

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
				sectorArea = defineSectorSize * defineSectorSize;

				//searchGridHighNumber will be the Sector Size squared. If the user so happened to put in 8, searchGridHighNumber would be 64.
				searchGridHighNumber = defineSectorSize * defineSectorSize,
					searchGridLowNumber = 1,
					//searchGridLowNumber while always equal to 1 no matter what!!!

					targetLocationPredictionCounter = 1,
					targetLocationPrediction,
					enemyLocation = rand() % searchGridHighNumber - searchGridLowNumber;

				//This is the key algorithm we will use. It is called Binary Search.
				cout << "Search by Binary Search Algorithm" << endl;

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
				while (isTargetFoundBinary == false) {



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

						isTargetFoundBinary = true;

					}
				}
			}
		}

		/*Linear Search*/
		else if (searchPattern == 2) {

		getSectorSize1:
			cout << "Define the size of the sector (Sector size can not be smaller than four)" << endl;
			cin >> defineSectorSize;

			//We'll then check if the input was a valid one using an if statement
			if (defineSectorSize < 4) {
				cout << "The Sector size that you have entered is invalid..." << endl;
				goto getSectorSize1;

				/*They say that using a goto statement to jump to one code to another is considered to be bad code,
				but for this example I feel like I should use it since it's the quickest, despite the reputation it has.*/
			}
			else {
				//Starting the Linear Search: The search will start at one, and it will run all the way through 
				//the max sector size until it locates the enemy spot.

				//We'll save the area of the sector in a seperate variable
				sectorArea = defineSectorSize * defineSectorSize;

				//searchGridHighNumber will be the Sector Size squared. If the user so happened to put in 8, searchGridHighNumber would be 64.
				searchGridHighNumber = defineSectorSize * defineSectorSize,
					searchGridLowNumber = 1,
					//searchGridLowNumber while always equal to 1 no matter what!!!

					targetLocationPredictionCounter = 1,
					targetLocationPrediction,

					//I still want the enemy location to be random, so we'll be keeping this.
					enemyLocation = rand() % searchGridHighNumber - searchGridLowNumber;

				//This is the key algorithm we will use. It is called Binary Search.
				cout << "Search by Linear Search Algorithm" << endl;

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
				while (isTargetFoundLinear == false) {



					//Software selection target location predicition in flyover hunt for enemy.
					cout << "Skynet HK-Aerial Radar sending out ping #"
						<< targetLocationPredictionCounter
						<< endl;

					// Radar Ping of enemy location

					targetLocationPrediction = searchGridLowNumber++;


					// This simulation will be a bit different
					// The AI will be counting in increments until it hits the enemy location

					if (targetLocationPrediction == enemyLocation) {
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

						isTargetFoundLinear = true;
					}
					else {
						targetLocationPredictionCounter++;
						WAIT;
					}
				}
			}
		}

		/*Random Search*/
		else if (searchPattern == 3) {
		getSectorSize2:
			cout << "Define the size of the sector (Sector size can not be smaller than four)" << endl;
			cin >> defineSectorSize;

			//We'll then check if the input was a valid one using an if statement
			if (defineSectorSize < 4) {
				cout << "The Sector size that you have entered is invalid..." << endl;
				goto getSectorSize2;

				/*They say that using a goto statement to jump to one code to another is considered to be bad code,
				but for this example I feel like I should use it since it's the quickest, despite the reputation it has.*/
			}
			else {
				//Starting the Linear Search: The search will start at one, and it will run all the way through 
				//the max sector size until it locates the enemy spot.

				//We'll save the area of the sector in a seperate variable
				sectorArea = defineSectorSize * defineSectorSize;

				//searchGridHighNumber will be the Sector Size squared. If the user so happened to put in 8, searchGridHighNumber would be 64.
				searchGridHighNumber = defineSectorSize * defineSectorSize,
					searchGridLowNumber = 1,
					//searchGridLowNumber while always equal to 1 no matter what!!!

					targetLocationPredictionCounter = 1,
					targetLocationPrediction = rand() % searchGridHighNumber - searchGridLowNumber,



					//I still want the enemy location to be random, so we'll be keeping this.
					enemyLocation = rand() % searchGridHighNumber - searchGridLowNumber;

				//This is the key algorithm we will use. It is called Binary Search.
				cout << "Search by Random Search Algorithm" << endl;

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
				while (isTargetFoundRandom == false) {



					//Software selection target location predicition in flyover hunt for enemy.
					cout << "Skynet HK-Aerial Radar sending out ping #"
						<< targetLocationPredictionCounter
						<< endl;

					// Radar Ping of enemy location

					targetLocationPrediction = rand() % searchGridHighNumber - searchGridLowNumber;
					if (targetLocationPrediction > enemyLocation) {
						//The target Location  Prediction was Lower than the enemyLocation
						//no need to search anymore at or below the target location prediction
						//We add 1 because we don't need to search the number guessed.
						cout << "The target location prediction of "
							<< targetLocationPrediction
							<< " was higher than the actual enemy location of "
							<< enemyLocation
							<< endl;

						targetLocationPredictionCounter++; //targetLocationPredictionCounter = targetLocationPredictionCounter + 1;
						WAIT;
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

						targetLocationPredictionCounter++; //targetLocationPredictionCounter = targetLocationPredictionCounter + 1;
						WAIT;
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

						isTargetFoundRandom = true;
					}
				}
			}
		}

		/*Human Search*/
		else if (searchPattern == 4) {

		getSectorSize3:
			cout << "Define the size of the sector (Sector size can not be smaller than four)" << endl;
			cin >> defineSectorSize;

			//We'll then check if the input was a valid one using an if statement
			if (defineSectorSize < 4) {
				cout << "The Sector size that you have entered is invalid..." << endl;
				goto getSectorSize3;

				/*They say that using a goto statement to jump to one code to another is considered to be bad code,
				but for this example I feel like I should use it since it's the quickest, despite the reputation it has.*/
			}
			else {
				//Starting the Linear Search: The search will start at one, and it will run all the way through 
				//the max sector size until it locates the enemy spot.

				//We'll save the area of the sector in a seperate variable
				sectorArea = defineSectorSize * defineSectorSize;

				//searchGridHighNumber will be the Sector Size squared. If the user so happened to put in 8, searchGridHighNumber would be 64.
				searchGridHighNumber = defineSectorSize * defineSectorSize,
					searchGridLowNumber = 1,
					//searchGridLowNumber while always equal to 1 no matter what!!!

					targetLocationPredictionCounter = 1,
					targetLocationPrediction = rand() % searchGridHighNumber - searchGridLowNumber,



					//I still want the enemy location to be random, so we'll be keeping this.
					enemyLocation = rand() % searchGridHighNumber - searchGridLowNumber;

				//This is the key algorithm we will use. It is called Binary Search.
				cout << "Search by User Input" << endl;

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
				while (isTargetFoundHuman == false) {



					//Software selection target location predicition in flyover hunt for enemy.
					cout << "Skynet HK-Aerial Radar sending out ping #"
						<< targetLocationPredictionCounter
						<< endl;

					// Radar Ping of enemy location

					cout << "Insert a number that is within the given sector." << endl;
					cin >> targetLocationPrediction;
					if (targetLocationPrediction > enemyLocation) {
						//The target Location  Prediction was Lower than the enemyLocation
						//no need to search anymore at or below the target location prediction
						//We add 1 because we don't need to search the number guessed.
						cout << "The target location prediction of "
							<< targetLocationPrediction
							<< " was higher than the actual enemy location of "
							<< enemyLocation
							<< endl;

						targetLocationPredictionCounter++; //targetLocationPredictionCounter = targetLocationPredictionCounter + 1;
						WAIT;
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

						targetLocationPredictionCounter++; //targetLocationPredictionCounter = targetLocationPredictionCounter + 1;
						WAIT;
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

						isTargetFoundHuman = true;
					}
				}
			}
		}

		/*cout << "Through a Binary Search, " << binaryCount << " predications has been made" << endl;
		cout << "Through a Linear Search, " << linearCount << " predications has been made" << endl;
		cout << "Through a Random Search, " << randomCount << " predications has been made" << endl;
		cout << "Through a Human Search, " << humanCount << " predications has been made" << endl;*/

		NEWLINE;

		cout << "Continue Search? \n"
			<< "1 - Yes \n"
			<< "2 - No \n"
			<< endl;
		cin >> varContinue;
		if (varContinue == 1) { NEWLINE; continue; }
		else { isProgramRunning = false; }
	}

	system("pause");
	return 0;

}

	//I broke up the cout functions the way they are because I find them going outside of the editor field
	//so doing this, no one has to scroll horizontally just to see the string.
	//It's been compressed every time << is used.
	//Honestly the code shouldn't be 171 lines long, but because I wanted everything
	//to show in one area instead of out of bounds, that's what happened.