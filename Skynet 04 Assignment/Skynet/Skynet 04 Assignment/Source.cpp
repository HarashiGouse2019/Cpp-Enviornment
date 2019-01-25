#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int searchGridHighNumber = 64, searchGridLowNumber = 1;

	int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
	targetLocationPrediction++; //targetLocationPredictionCounter = targetLocationPredictionCounter + 1;

	cout << "HK Software" << endl;
	//This is the key algorithm we will use. It is called Binary Search.

	bool isTargetFound = false;

	//Keeping this blank for now.
	while (!isTargetFound) {
		//Software selection target location predicition in flyover hunt for enemy.


		// Radar Ping of enemy location
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

		// In this simulation the ping tells us
		// if the target location is higher or lower or right on the enem location.
		// I starget location prediction higher than enemy location

		if (targetLocationPrediction > enemyLocation) {
			//The target Location Prediction was higher than the enemyLocation
			//no need to search anymore at or above target location prediction
			//reset the searchGridHighNumber of the search Grid.
			//We subtract 1 because we don't need to search the number guessed.
			searchGridHighNumber = targetLocationPrediction - 1;



		}
		else if (targetLocationPrediction < enemyLocation)
			//The target Location  Prediction was Lower than the enemyLocation
			//no need to search anymore at or below the target location prediction
			//We add 1 because we don't need to search the number guessed.
			searchGridHighNumber = targetLocationPrediction + 1;



		}

	}
	
	

	//Search Grid High #64
	//Search Grid Low #1

	return 0;
}