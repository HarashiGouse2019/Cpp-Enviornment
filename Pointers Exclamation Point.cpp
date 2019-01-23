//Using pointers
#include <iostream>

using namespace std;

//This is probably all that we're going to need to get used to using pointers.

int main() {
	
	//first we'll create a variable. I haven't included the string header file for this, so just for simplicity
	//we'll give it a simple number
	
	int number = 100;
	
	//We're going to initialize a int* pointer
	int *ip;
	
	//For a pointer, you first need to assign the address of a variable to it.
	//Or something like that.
	
	ip = &number; //ip has already been declared as a pointer to the address of the variable "number"
	
	//Now let's print some stuff.
	
	//Printing onto the console the actual value of the variable "number"
	cout << "The actual value of the variable \"number\":	" << number << endl;

	//Now we will know the memory address of this variable
	cout << "The memory address of the given variable:	" << ip << endl;
	
	//Now we use the pointer (which should return the value of what it's pointing. ip is pointing at number, therefore it'll return the value of number)
	cout << "The pointer \"ip\" returns the value of the given variable:	" << *ip << "	address(" << ip << ")" << endl;
	
	return 0;
}
