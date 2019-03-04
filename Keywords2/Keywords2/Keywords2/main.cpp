//Hangman
//The classic game of Hangman

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>

using namespace std;

int main(int argc, char** argv[]) {
	//setup
	fstream myFile; //Create myFile
	string userId; //The User Identification
	string userPasscode; //The User's Passcode
	myFile.open("loginInfo.txt"); //Normally you'd never save login info in a txt file. Now that's just evil.

	//Collect Information
	cout << "User ID: ";
	cin >> userId; //Grab userId
	myFile << userId; //Writes the input into loginInfo.txt

	cout << "User Passcode: ";
	cin >> userPasscode; //Grab userPasscode
	myFile << userPasscode; //Writes the input into loginInfo.txt

	//Closes files
	myFile.close();

	cout << "Information saved!!!"; //INFORMATION SAVED!!!

	bool isProgramRunning = true; //True if the program is running
	
	cout << "\n\nWELCOME TO HANGMAN DESU!!! GANBARO ZE, " << userId << " !\n"; //INTRODUCTION

	//Main Loop begins here
	while (isProgramRunning == true) {

		const int MAX_WRONG = 8; //maximum number of incorrect guesses allowed

		vector<string> words; //collection of possible words to guess
		words.push_back("HYPOTHESIZE"); //Adds to our vector
		words.push_back("INFULTRATION"); //Adds to our vector
		words.push_back("COUPDETATE"); //Adds to our vector
		words.push_back("INTERROGATION"); //Adds to our vector
		words.push_back("DETAIN"); //Adds to our vector
		words.push_back("CLASSIFIED"); //Adds to our vector
		words.push_back("RENDEZVOUS"); //Adds to our vector
		words.push_back("SPY"); //Adds to our vector
		words.push_back("FBI"); //Adds to our vector
		words.push_back("CIA"); //Adds to our vector

		srand(static_cast<unsigned int>(time(0))); //Sets a random value
		random_shuffle(words.begin(), words.end()); //Shuffle our list of words

		const string THE_WORD = words[0]; //word to quess
		int incorrectCount = 0; //number of incorrect guesses
		string soFar(THE_WORD.size(), '-');

		string used = ""; // Letters already guessed

		//This is the main game loop inside the programs main loop
		while ((incorrectCount < MAX_WRONG) && (soFar != THE_WORD)) {
			cout << "\n\n You have " << (MAX_WRONG - incorrectCount);
			cout << " incorrect guesses left.\n";
			cout << "\n You've used the following letter:\n" << used << endl;
			cout << "\nSo far, the word is: \n" << soFar << endl;


			//Getting the player to guess the word.
			char guess; //A letter is represented here
			cout << "\n\nEnter your guess: ";
			cin >> guess; //Input a guess

			guess = toupper(guess); //make uppercase since secret word in uppercase

			//Create a loop that'll check if the Player has already guessed a certain letter
			while (used.find(guess) != string::npos) {
				cout << "\nYou've already guessed " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			used += guess; //Tells you how many times you've guessed a letter.

			if (THE_WORD.find(guess) != string::npos) {
				cout << "That's right! "
					<< guess << " is in the word.\n"; //Update soFar to include newly guessed letter

				//It'll go through the entire word, and if a guessed letter matches a letter in the given word, it displays it.
				for (int i = 0; i < THE_WORD.length(); ++i) {
					if (THE_WORD[i] == guess) {
						soFar[i] = guess;
					}
				}
			}
			else
			{
				cout << "Sorry, " << guess << " isn't in the word.\n";
				++incorrectCount; //How many times you got your guesses wrong!!!!
			}

			//If you run out of guesses, it prints "You've been hanged", otherwise, it'll congratulate you.
			if (incorrectCount == MAX_WRONG) {
				cout << "\nYou've been hanged!";
				
			}
			else if (incorrectCount != MAX_WRONG && soFar == THE_WORD) {
				cout << "\n You guessed it!";
			}
			//Shut Down
		}
		//Ending the game
		cout << "\nThe word was " << THE_WORD << endl;

		cout << "\n Continue the investigation?" << endl;

		string choice; //This is to get a choice from the recruit

		cin >> choice; //Ask for an "Yes" or "No" answer

		//If it's any varient of "yes", the loop will continue, otherwise, the program will indirectly salut you!
		if (choice == "YES" || choice == "yes" || choice == "Yes") {
			incorrectCount = 0;
			continue;
		}
		else {
			cout << "\n See you later commrade!!!" << endl;
			isProgramRunning = false;
		}

		system("pause"); //Pause the program

		return 0; //Return a value of 0, meaning that the program ran into no errors!!!

		//END OF PROGRAM!!!
	}
}