#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

#define BREAKLINE cout << "==================================================" << endl;

int main() {

	int searchGridHighNumber = 64, searchGridLowNumber = 1, targetLocationPredictionCounter = 1, targetLocationPrediction, enemyLocation = rand() % searchGridHighNumber - searchGridLowNumber;
	
	bool isTargetFound = false;

	srand(time(0));

	cout << "HK Software" << endl;
	//This is the key algorithm we will use. It is called Binary Search.
	cout << "Generate Randome enemy location on 8x8 grid..." << endl;
	cout << "The enemy is located at location #" << enemyLocation << " on 8x8 grid with 1-64 sectors." << endl;
	cout << "Skynet HK-Aerial Initializing software....." << endl;

	BREAKLINE;
	
	//Keeping this blank for now.
	while (isTargetFound == false) {
		
		

		//Software selection target location predicition in flyover hunt for enemy.
		cout << "Skynet HK-Aerial Radar sending out ping #" << targetLocationPredictionCounter << endl;

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
			cout << "The target location prediction of " << targetLocationPrediction << " was higher than the actual enemy location of " << enemyLocation << endl;
			searchGridHighNumber = targetLocationPrediction - 1;
			cout << "searchGridHighNumber: " << searchGridHighNumber << endl;
			targetLocationPredictionCounter++; //targetLocationPredictionCounter = targetLocationPredictionCounter + 1;

			BREAKLINE;

		}
		else if (targetLocationPrediction < enemyLocation) {
			//The target Location  Prediction was Lower than the enemyLocation
			//no need to search anymore at or below the target location prediction
			//We add 1 because we don't need to search the number guessed.
			cout << "The target location prediction of " << targetLocationPrediction << " was lower than the actual enemy location of " << enemyLocation << endl;
			searchGridLowNumber = targetLocationPrediction + 1;
			cout << "searchGridLowNumber: " << searchGridLowNumber << endl;
			targetLocationPredictionCounter++; //targetLocationPredictionCounter = targetLocationPredictionCounter + 1;

			BREAKLINE;

		}
		else {
			cout << "Enemy was hiding at Sector #" << enemyLocation << endl;
			cout << "Target was found at Sector #" << enemyLocation << endl;
			cout << "Skynet took " << targetLocationPredictionCounter << " predictions to find the enemy location on a grid size of 8x8 (64)" << endl;
			isTargetFound = true;
		}
	}

	system("pause");

	return 0;

	}