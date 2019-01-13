#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	//Uisng an 
	enum choice {
		//Mood Choice
		good = 1,
		bad = 2,
		iffy = 3
	} value;
	
	
	
	switch(value) {
		case 1: cout << "Good" << endl; break;
		case 2: cout << "Bad" << endl; break;
		case 3: cout << "Iffy" << endl; break;
		default: cout << "You typed in some code \n but nothing happened."; break;
	}
	
	return 0;
	
}
