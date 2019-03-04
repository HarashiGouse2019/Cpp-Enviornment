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

using namespace std;

int main(int argc, char** argv[]) {
	//setup
	const int MAX_WRONG = 8; //maximum number of incorrect guesses allowed

	vector<string> words; //collection of possible words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0]; //word to quess
	int incorrectCount = 0; //number of incorrect guesses
	string soFar(THE_WORD.size(), '-');

	string used = ""; // Letters already guessed

	cout << "WELCOME TO HANGMAN DESU!!! GANBARO ZE!\n";

	//Main Loop begins here

	while ((incorrectCount < MAX_WRONG) && (soFar != THE_WORD)) {
		cout << "\n\n You have " << (MAX_WRONG - incorrectCount);
		cout << " incorrect guesses left.\n";
		cout << "\n You've used the following letter:\n" << used << endl;
		cout << "\nSo far, the word is: \n" << soFar << endl;
	}

	//Getting the player to guess the word.
	char guess;
	cout << "\n\nEnter your guess: ";
	cin >> guess;

	guess = toupper(guess); //make uppercase since secret word in uppercase

	//Create a loop that'll check if the Player has already guessed a certain level
	while (used.find(guess) != string::npos) {
		cout << "\nYou've already guessed " << guess << endl;
		cout << "Enter your guess: ";
			cin >> guess;
		guess = toupper(guess);
	}

	used += guess;

	if (THE_WORD.find(guess) != string::npos) {
		cout << "That's right! "
			<< guess << " is in the word.\n"; //Update soFar to include newly guessed letter

		for (int i = 0; i < THE_WORD.length(); ++i) {
			if (THE_WORD[i] == guess) {
				soFar[i] = guess;
			}
		}
	}
	else
	{
		cout << "Sorry, " << guess << " isn't in the word.\n";
		++incorrectCount;
	}

	//Ending the game

	//Shut Down

	if (incorrectCount == MAX_WRONG) {
		cout << "\nYou've been hanged!";
	}
	else {
		cout << "\n You guessed it!";
	}

	cout << "\nThe word was " << THE_WORD << endl;

	return 0;

	//END OF PROGRAM!!!

}