#include <iostream>
#include <istream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

//Man-Made Header!
#include "WProcessMain.h" //Calling WProcessMain header
#include "WProcessIO.h" //Calling WProcessIO header

using namespace std;

//Receive Input
void Start() {
	system("color F0"); //Set our console color to white
	string defaultName = "Untitled.twp"; //We started a new instance, so this will be our default file
	string * ptrdefaultName = &defaultName; //Create a pointer, because WProcessIO functions take a pointer

	string field; //The entire word document
	string * ptrfield = &field; //Create a pointer for that.

	getline(cin, *ptrfield); //Gather input of whatever the user is typing
	TempIO(ptrdefaultName, ptrfield); //After the RETURN key has been inputted, we start to create our temporary file
}

//This is our key. This will show the functions that you can do in this console based word processor.
//Sadly, none of them works.
void DisplayKey() {
	cout << "***************************************************************************************************************************************************************" << endl;
	cout << "*			" << "Save - F1 (Dysfunctional)  " << "Load - F2 (Dysfunctional)   " << "Dump/Scrap - Delete (Dysfunctional)   " << "							   *" << endl;
	cout << "*                       " << "Because of some problems, your back up will be converted to a .txt file opposed to a .twp file..." << "                         *" << endl;
	cout << "*                                                     " << "Sorry for the inconvience" << "                                                                   *" << endl;
	cout << "***************************************************************************************************************************************************************" << endl;
}


			
