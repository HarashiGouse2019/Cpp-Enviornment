#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

//Man-Made Header!
#include "WProcessMain.h" //Calling WProcessMain header
#include "WProcessIO.h" //Calling WProcessIO header

using namespace std;

fstream tempFile; //Create a file stream of the identifier tempFile.

//Input temporary data
void TempIO(string * name, string * console_text) {
	
	tempFile.open(*name, ofstream::app); //This function will be called every new line. We set the file in append mode.

	//If something goes wrong, or the file can't be opened, give us an error log
	if (tempFile.fail()) {
		cerr << "tempFile wasn't created. Sorry 0 - 0";
	}
	//Otherwise...
	else {
		tempFile << *console_text << endl; //Take our line and place it in our temporary file
		tempFile.close(); //Close our file
	}
	Start(); //Continue the word processor
}

//Saving the file
void SaveIO(string * filename) {
	cout << "\nSave as: "; cin >> *filename; //Prompt the user for a name
	ofstream file; //The name is sorted, then we create an output stream file
	file.open(*filename + ".txt"); //We create a txt file

	//If we can't create this files, give us an error
	if (file.fail()) {
		cerr << "File wasn't created. Sorry 0 - 0";
	}
	//Otherwise...
	else {
		//Iterate the .twp file until at the end of the file, 
		// taking each line and storing it in the created .txt file
		int count = 0;
		while (!tempFile.eof()) {
			tempFile.get();
			count++;
		}
		file.close(); //Close the file
	}
}

//void LoadIO(string * filename) {
//
//}
