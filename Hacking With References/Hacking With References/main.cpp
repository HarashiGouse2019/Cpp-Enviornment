#include <iostream> //Including the iostream header from the C++ library
#include <string> //Inlcuding the string header from the C++ library

using namespace std; //Using the standard namespace

#define HEADER cout << "Original Value\n"
#define CALL_NORMAL_ACCOUNT cout << "Calling NormalAccount()\n"
#define CALL_HACKED_ACCOUNT cout << "Calling HackedAccount()\n"

//We'll set up two prototypes,
//one will take the balance of a normal bank account
//Another one will be hacked 
void HackedAccount(float& x, float&  y);
void NormalAccount(float x, float y);
void DisplayBalances(float balance1, float balance2);

int main() {
	float myBalance = 2871.00; //The balance on my account
	float attackerBalance = 60.98; //The balance that the attacker has on his account

	//The attacker will hack into my account, and take the money that I have, giving me his balance
	//of $60.98

	//Print out the original account balances
	HEADER; //Our directive of printing out "Original Value"
	DisplayBalances(myBalance, attackerBalance);

	//Using the Normal Account
	CALL_NORMAL_ACCOUNT; //Our directive of printing out "Calling NormalAccount()"
	NormalAccount(myBalance, attackerBalance);
	
	//Display the modified and hacked balances
	DisplayBalances(myBalance, attackerBalance);

	//Using the hack account
	CALL_HACKED_ACCOUNT; //Our directive of printing out "Calling HackedAccount()"
	HackedAccount(myBalance, attackerBalance);

	//Display balances
	DisplayBalances(myBalance, attackerBalance);

	//Return a value of 0 to let the user know the program has ran successfully;
	return 0;
}

//The Normal Bank Account
void HackedAccount(float& x, float& y) {
	float temp = x; //This will equal the parameter x
	x = y; //The parameter x will equal the parameter y
	y = temp; //y will be set to temp (which was equal to the parameter value of x; making a swap effect
}

//The Hacked Bank Account
void NormalAccount(float x, float y) {
	float temp = x; //This will equal the parameter x
	x = y; //The parameter x will equal the parameter y
	y = temp; //y will be set to temp (which was equal to the parameter value of x; making a swap effect
}

//Print out the balances before or after swap
void DisplayBalances(float balance1, float balance2) {
	cout <<  "myBalance: " << showpoint << balance1 << "\n"; //Print mine out
	//Then print the attacker's balance
	cout << "attackerBalance: " << balance2 << "\n\n";
	//Throw in a system pause
	system("pause");
}