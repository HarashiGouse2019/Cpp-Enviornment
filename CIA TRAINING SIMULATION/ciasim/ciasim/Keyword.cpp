///CIA TRAINING SIMULATION APPLICATION => Keyword (64 - Bit)

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char** argv[]) {

	bool isProgramRunning = true; //This will be used for our program loop
	int chances = 3; //We are now given 3 tries to type the unscambled word correctly.
	srand(static_cast<unsigned int>(time(0)));
	

	//We introduce the user to Word Jumble, as well as some commands to use as the program runs
	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n";

	//Program Loop
	do {
		//This is used to set a random seed or number for jumbling our words.

		for (int i = 0; i < 3; i++) {

			enum fields {
				WORD, //The word
				HINT, //The hint that goes to that word
				NUM_FIELDS //The number of fields
			};

			const int NUM_WORDS = 10; //We set this to 10 since we need a total of ten words for this program

			const string WORDS[NUM_WORDS][NUM_FIELDS] = {
				{"ejection", "The act of escaping when being minutes away from a crash!"},
				{"hydration", "It's what you get when you get water!"},
				{"keyboard", "Something you need to do your assignments in front of a screen."},
				{"wilderness", "Another way of saying nature."},
				{"abugida", "A kind of writing system"},
				{"observation", "The act of analyzing... with your eyes..."},
				{"language", "A communication tool that the entire human race uses!"},
				{"console", "Similar to a computer or a monitor"},
				{"technology", "The reason why we're all here!"},
				{"anthromorphism", "Something that takes a human shape"}
			};

			//the integar choice, in simple terms, will have a random number between 1 and 10
			int choice = (rand() % NUM_WORDS);

			string theWord = WORDS[choice][WORD]; //This takes a word from our enumerator field
			string theHint = WORDS[choice][HINT]; //This also grabs the hint from the enumerator field

			//Jumbling the Word

			string jumble = theWord; //Our jumbled up word will be assign to this variable.

			int length = jumble.size(); //We calculate the size of the given word that'll be jumbled.

			for (int i = 0; i < length; ++i) {
				int index1 = (rand() % length); //index1 is given a random number
				int index2 = (rand() % length); //index2 is given a random number

				char temp = jumble[index1]; //temporary character will be given the value of the first index
				jumble[index1] = jumble[index2]; //We then begin to swap (for both these lines)
				jumble[index2] = temp;
			}

			//It'll go to each letter of a given word using "length" to return how long the selected word is.
			//It'll then switch them by a random value from index1 and index2 until it reached the last letter to shuffle.

			//Gameplay
			chances = 3;
			cout << "\nThe jumble is: " << jumble; //Give the jumbled word

			string guess; //This string will be used to store input from the user
			cout << "\n\nYour guess: ";
			cin >> guess; //Grabbing input from the user

			while ((guess != theWord) && (guess != "quit") && chances != 0) { //Meaning if what we type isn't the give word, or if it's not
															  //equal to one of the valid commands, we'll go through the 
															  //following block of code.

				//If instead the user asked for a hint, the program will provide it.
				//Otherwise, the player has guessed the word wrong
				if (guess == "hint") {
					cout << theHint; //We give the user a hint
				}
				else {
					cout << "Sorry, that's not it.";
					chances--; //The amount of chances that the user has decreases
				}
				if (chances != 0) {
					//We ask for another guess again
					cout << "\nYou have " << chances << " more chances.";
					cout << "\n\nYour guess: ";
					cin >> guess; //Grab input from the user.
				}
				else {
					//It'll tell us what the word is if we run out of chances
					cout << "\nThe correct answer was: \n" << theWord << "\n";
				}
			}

			//If the player got it right, or if they decided to quit
			if (guess == theWord) {
				cout << "\nThat's it! You guessed it!\n"; //Tell the user that he/she got it right.
			}
		}

		//We are asked if we want to play again.
		cout << "\n\nWould you like to play again? (Y/N)" << endl;
		char yourChoice = NULL; //We'll store user input into this variable, which was given a null value.

		cin >> yourChoice; //We get user input

		switch (toupper(yourChoice)) {
			//If the user inputs a yes!

		case 'Y':
			chances = 3; //Chances are restored!!!
			continue; //We continue the while loop
			break; //Break out of the switch case

			//If the user inputs a no.
		case 'N':
			isProgramRunning = !isProgramRunning; //This will have our boolean false, which will end the program.
			break; //Break out of thw switch case
		}

	} while (isProgramRunning == true);
}