#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>

//Man-Made Header!
#include "WProcessMain.h"
#include "WProcessIO.h"

#define ENTER 13
#define SAVE 83
#define LOAD 79

using namespace std;

void Start() {
	string defaultName = "Untitled.wtmp";
	string field;
	
	int c = 0;
	while (1) {
		c = 0;
		switch ((c = _getch())) {
		case ENTER:
			TempIO(&defaultName, &field);
			break;
		case SAVE:
			string promptFileName;
			SaveIO(&promptFileName);
		}
	}
}