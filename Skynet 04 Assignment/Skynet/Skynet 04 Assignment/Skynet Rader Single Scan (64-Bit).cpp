///Skynet Radar Single Scan (64-Bit)
/*This program will take on a single scan and return all the total predictions
made with each scan.

However you are still allowed to defined a sector size of your choosing 
before the entire scan initiates.*/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>

using namespace std;

//I used a #define preprocessor just so I can do the lines without always holding the "=" key
//and they can always be a constant amount. Using preprocessors are so much better!!!

#define BREAKLINE cout << "==================================================" << endl; //Prints out lines to divide 
																						//the words displayed on the
																						//console without me holding
																						//the same key for a long time.
#define WAIT cout << "(......)" << endl; //This is used for the random search scan;
										//I could of used the BREAKLINE preprocessor for this
										//but I ended up making two seperate cpp files
#define NEWLINE cout << "\n" << endl; //Prints me a new line for me;

#define BINARY cout << "Binary Search Initializing..." << endl; 
#define LINEAR cout << "Linear Search Initializing..." << endl;
#define RANDOM cout << "Random Search Initializing..." << endl;
#define HUMAN cout << "Human Search Initializing..." << endl;

//Each time before it enters a new while loop, some of these defined identifiers will be typed into this
//code, telling you which one is 

int main() {

	//We'll add some flair into this good! We'll define a grid inputted by the user that is greater or equal to 8 squared
	//So they can have a bigger sector to learn for the enemy, and I find that very interesting!!!

	//This single variable will be used for our while loop. After the program ask
	//whether we want to continue or not, if we say no, it'll turn this boolean false,
	//meaing we jump out of the while loop.
	bool isProgramRunning = true;

	while (isProgramRunning) {

		int defineSectorSize /*Used for the user to type in the size of the sector (8 x 8 or 16 x 16) */,

			sectorArea /*This variable will store the defined sector size and muliplies itself to get the area*/,

			searchGridHighNumber /*This will be set to equal the area of the sector*/,

			searchGridLowNumber /* This however will always be 1*/,

			targetLocationPrediction /*We'll store certain numbers based on the kind of search we are doing.
									 Depending on the search, this variable may have to reset.*/,

			targetLocationPredictionCounter /*This records how many predictions a give search has made.
											this variable with reset itself before we enter another while loop.
											After every loop, we'll take this variable and store it in another
											variable that has a global scope, so that it may be used to display
											the amount of predictions each search pattern made.*/,

			enemyLocation /*Everytime you start/continue the program, this will be assigned to a new random number
						  between one and the sector area*/,

			varContinue = 0 /*After the whole program runs, we'll be asked to run it again. This is used to decide
						rather the user would like to continue the simulation or not*/,

			binaryCount = 0 /*After the while loop for the Binary Search, the amount of predictions made during the
							simulation will be stored here.*/,

			linearCount = 0 /*After the while loop for the Linear Search, the amount of predictions made during the
							simulation will be stored here.*/,

			randomCount = 0 /*After the while loop for the Random Search, the amount of predictions made during the
							simulation will be stored here.*/,

			humanCount = 0 /*After the while loop for a Human Defined Search, the amount of predictions made during the
							simulation will be stored here.*/;

		bool isTargetFoundBinary = false,
			isTargetFoundLinear = false,
			isTargetFoundRandom = false,
			isTargetFoundHuman = false;

		cout << "HK Software" << endl;

		NEWLINE;

		//We'll initialize some of the other variables here!
		//But first, we'll ask the user to input a number to define the area of the sector.

	getSectorSize:
		cout << "Define the size of the sector (Sector size can not be smaller than four)" << endl;
		cin >> defineSectorSize; //We get input from the user of the desired sector size

		//We'll then check if the input was a valid one using an if statement
		if (defineSectorSize < 4) {
			cout << "The Sector size that you have entered is invalid..." << endl;
			goto getSectorSize;

			/*They say that using a goto statement to jump to one code to another is considered to be bad code,
			but for this example I feel like I should use it since it's the quickest, despite the reputation it has.*/
		}
		else {

			srand(time(0)); //This will help us generate a random number for our simulation

			NEWLINE;

			cout << "Initializing Single Scan" << endl;

			//We print a new line, and we begin our Binary Search
			NEWLINE; BINARY;

			//We'll save the area of the sector in a seperate variable
			sectorArea = defineSectorSize * defineSectorSize;

			//searchGridHighNumber will be the Sector Size squared. If the user so happened to put in 8, searchGridHighNumber would be 64.
			searchGridHighNumber = defineSectorSize * defineSectorSize,
				searchGridLowNumber = 1,
				//searchGridLowNumber while always equal to 1 no matter what!!!

				targetLocationPredictionCounter = 1,
				targetLocationPrediction,
				enemyLocation = rand() % searchGridHighNumber - searchGridLowNumber;

			//This is then were everything is logged onto the console.

			cout << "Generate Random enemy location on "
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

			targetLocationPredictionCounter = 1; /*This will be set to one so when the number ping is displayed,
												 the value always start at one.*/

			//The Binary Search begins here!
			while (isTargetFoundBinary == false) {

				cout << "Skynet HK-Aerial Radar sending out ping #" // Radar Ping of enemy location
					<< targetLocationPredictionCounter
					<< endl;
				
				//This is the Binary Search Algorithm that we will use for this while loop.
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

					//Tell us of the results when the enemy is found!!!
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


					binaryCount = targetLocationPredictionCounter; /*binaryCount now represents how many predictions
																   this search had made.*/

					NEWLINE; BREAKLINE; NEWLINE;

				}
			}
			
			//We now begin our Linear Search
			LINEAR;

			cout << "Generate Random enemy location on "
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

			//We'll save the area of the sector in a seperate variable
			sectorArea = defineSectorSize * defineSectorSize;

			//searchGridHighNumber will be the Sector Size squared. If the user so happened to put in 8, searchGridHighNumber would be 64.
			searchGridHighNumber = defineSectorSize * defineSectorSize,
				searchGridLowNumber = 1,
				//searchGridLowNumber while always equal to 1 no matter what!!!

			targetLocationPredictionCounter = 1; //The amount of predictions is reset back to one in prep for the next loop.

			while (isTargetFoundLinear == false) {
				
				//Software selection target location predicition in flyover hunt for enemy.
				cout << "Skynet HK-Aerial Radar sending out ping #"
					<< targetLocationPredictionCounter
					<< endl;

				// Radar Ping of enemy location

				targetLocationPrediction = searchGridLowNumber++; //Since it's linear, we'll be going increments of one.
																//I know the low number is always 1, so I used that for this
																//expression.


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

					linearCount = targetLocationPredictionCounter; /*This time, the amount of predictions made
																   going through a linear search is recorded here.*/

					NEWLINE; BREAKLINE; NEWLINE;

				}
				else {
					targetLocationPredictionCounter++;
					WAIT;
				}
			}
			
			//We now begin our Random Search
			RANDOM;

			cout << "Generate Random enemy location on "
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
			//We'll save the area of the sector in a seperate variable
			sectorArea = defineSectorSize * defineSectorSize;

			//searchGridHighNumber will be the Sector Size squared. If the user so happened to put in 8, searchGridHighNumber would be 64.
			searchGridHighNumber = defineSectorSize * defineSectorSize,
				searchGridLowNumber = 1,
				//searchGridLowNumber while always equal to 1 no matter what!!!

			targetLocationPredictionCounter = 1; //Again! We reset!

			while (isTargetFoundRandom == false) {
				//Software selection target location predicition in flyover hunt for enemy.
				cout << "Skynet HK-Aerial Radar sending out ping #"
					<< targetLocationPredictionCounter
					<< endl;

				// Radar Ping of enemy location

				targetLocationPrediction = rand() % searchGridHighNumber + searchGridLowNumber;
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

					randomCount = targetLocationPredictionCounter; /*The amount of predictions made with the
																   Random search is now recorded!*/

					NEWLINE; BREAKLINE; NEWLINE;

				}
			}

			//We now begin our User Defined Search
			HUMAN;

				cout << "Generate Random enemy location on "
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
				//We'll save the area of the sector in a seperate variable
				sectorArea = defineSectorSize * defineSectorSize;

				//searchGridHighNumber will be the Sector Size squared. If the user so happened to put in 8, searchGridHighNumber would be 64.
				searchGridHighNumber = defineSectorSize * defineSectorSize,
					searchGridLowNumber = 1,
					//searchGridLowNumber while always equal to 1 no matter what!!!

				targetLocationPredictionCounter = 1; //Finally, we reset our counter for the last time!!!

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

					humanCount = targetLocationPredictionCounter;

					NEWLINE; BREAKLINE; NEWLINE;

				}
			}
		}

		/*Now that the entire scan has been complete, it's time to colloct our data.
		We grab our 4 variables, and we'll have the printed on the screen.
		The program will tell and show how many predictions each search has made. */
		cout << "Through a Binary Search, " << binaryCount << " predications has been made." << endl;
				cout << "Through a Linear Search, " << linearCount << " predications has been made" << endl;
				cout << "Through a Random Search, " << randomCount << " predications has been made" << endl;
				cout << "Through a Human Search, " << humanCount << " predications has been made" << endl;

				NEWLINE; BREAKLINE; NEWLINE;

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