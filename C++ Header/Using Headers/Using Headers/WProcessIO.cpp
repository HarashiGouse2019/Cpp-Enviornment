#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

//Man-Made Header!
#include "WProcessIO.h"

using namespace std;

fstream tempFile;

string TempIO(string * name, string * console_text) {
	tempFile.open(*name);
	tempFile << *console_text;
	tempFile.close();
	return *name, *console_text;
}

string SaveIO(string * filename) {
	cout << "\nSave as: "; cin >> *filename;
	ofstream file;
	file.open(*filename + ".txt");
	int count = 0;
	while (!tempFile.eof()) {
		tempFile.get();
		count++;
	}
	file.close();
	return *filename;
}

string LoadIO(string * filename) {

	return *filename;
}
