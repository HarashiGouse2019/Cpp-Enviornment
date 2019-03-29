#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <cwchar>
#include <time.h>

using namespace std;

//Creating a timer class
class timer {
private:
	unsigned long begTime; //Our beginning time
public:
	void start() {
		begTime = clock(); //Begin Time will be initialized by processor time consumed by the program
	}
	//Count how long it has been
	unsigned long elapsedTime() {
		return ((unsigned long)clock() - begTime) / CLOCKS_PER_SEC;
	}
	//Returns a bool if you've ran out of time.
	bool isTimeOut(unsigned long seconds) {
		return seconds >= elapsedTime();
	}
};

//Setting CompareLog prototype
void CompareLog(unsigned int index);

//Display normal text. Your first paramater is going to be your string; The second will be the duration of speed that your text appears.
//The default value is 10, so if no value is given, it'll stay at 10;

//Have a string that takes our answer
string text;
string answer;

//Have a bool that determines that we are giving a yes or no question (only used for the Prompt method)
bool isYesNoQuestion;

//Create a vector that will story previous dialogue and answers;
vector<string>(dialogue);
vector<string>(pastResponses);


//Have the computer speak to us in text
void Speak(string text, int textDuration = 10) {
	//Create a reference to our text and our textDuration to save processing power
	string& refText = text;
	int& refTextDuration = textDuration;

	//We'll have our conversation and responses saved in a folder
	//The directory will be local.
	ofstream readme;
	readme.open("readme.txt"); //Open our file
	dialogue.push_back(refText); //We push our dialogue vector with text item
	//The for loop will cycle through the vector to print each value
	for (int i = 0; i != dialogue.size(); ++i) {
		readme << dialogue.at(i) << "\n";
	}
	readme.close(); //We close our file

	bool varcontinue = false; //This will toggle true one the "typing effect" stops.

	int i = 0; //Our variable for our while loop

	//This will modify one of our parameters; if 
	if (refTextDuration == 'F')
		refTextDuration = 5;
	if (refTextDuration == 'S')
		refTextDuration = 200;

	//This while loop will create an effect of someone typing
	//If the index of our string is smaller than it's length
	//it will continue to add the remaining letters from that string.
	while (refText[i] != '\0') {
		cout << refText[i]; //Print every character one by one
		if (refText[i] != '\n')
			Beep(1000, refTextDuration); //This is where the beep noises comes from. It'll continue until we've reached the end of our string's length
		Sleep(refTextDuration); //Sleep for a total amount of milliseconds
		i++; //Increment the variable i (the character of the text string) by one (a new letter will appear when the loop repeats)
	}

	varcontinue = true; //You can continue to the next set of dialogue

	if (varcontinue == true) cin.get();

	return;
}

//Clear out the console of any dialogue
void ClearOut() {
	system("CLS");
}

//This is what happens when you break Symphus's feelings!!!!
void Silence() {
	ClearOut();
	unsigned long seconds = 5; //Set our variable to 60
	timer t; //Create an instance of the timer class
	t.start(); //Play the function in this instance
	while (true) {
		if (t.elapsedTime() >= seconds) {
			break;
		}
		else {
			Speak("...");
		}
	}
}

//Program's Responses
void Prompt(string question, int textDuration = 10, bool isYesNoQuestion = false, int choiceIndex = NULL) {
	//Create references to our paramaters
	string& refQuestion = question;
	int& refTextDuration = textDuration;
	bool& refIsYesNoQuestion = isYesNoQuestion;
	int& refChoiceIndex = choiceIndex;

	//Open our file
	ofstream readme;
	readme.open("readme.txt");

	//Add our response to the vector
	dialogue.push_back(question);
	for (int j = 0; j != dialogue.size(); ++j) {
		readme << dialogue.at(j) << "\n";
	}
	readme.close(); //Close the file

	int i = 0; //Preparing for while loop

	//Change speed of our text
	if (refTextDuration == 'F')
		refTextDuration = 5;
	if (refTextDuration == 'S')
		refTextDuration = 200;

	//We start again with our loop of text
	while (refQuestion[i] != '\0') {
		cout << refQuestion[i];
		if (refQuestion[i] != '\n')
			Beep(1000, refTextDuration);
		Sleep(refTextDuration);
		i++;
	}

	//See if the prompt function is a Yes or No question
	switch (refIsYesNoQuestion) {
	//If it's not a yes or no question
	case false:
		//Access the set choices that'll be given to the user
		switch (refChoiceIndex) {
		case 1:
			cout << "\n1)That's a beautiful name!!!\n2)I like it!\n3)Symphus?!";
			break;
		case 2:
			cout << "\n1)You should!It's a compliment!\n2)You don't have to thank me.";
			break;
		case 3:
			cout << "\n1)Impossible! There's no way!!!!\n2)Ehhhhhhhh?! But I'm not a baphoon\n3)If you say so.";
			break;
		case 4:
			cout << "\n1)Perhaps you should show me something even cool than that!\n2)Sadly, it is.";
			break;
		case 5:
			cout << "\n1)Ehhhhhhhh?!";
			break;
		}

		//Print out this so the user knows that the program needs input
		cout << "\nYour Response?: ";
		cin >> answer; //Grab input
		cin.get(); 
		pastResponses.push_back(answer); //Add our response to our vector
		break;
	//If the prompt happens to be a yes or no question
	case true:
		//Print out (Yes/No) at the end, create a new line, and tell the user to respond
		cout << " (Yes/No)\nYour Response?: ";
		cin >> answer;
		cin.get();
		pastResponses.push_back(answer); //Add that answer to our vector
		break;
	}

	
}

//After answering the prompt, it'll respond with a certain mood.
void ShowResponse(int mood, unsigned int index) {
	switch (mood) {
	//if we what to play out a positive response
	case 'P':
		//Access the index of dialogue
		switch (index) {
			//Index 1
		case 1:
			ClearOut();
			Speak("Ahhh! So that's how it is?!");
			Speak("You do have a beautiful name?");
			Speak("I'm glad that I know!!!");
			ClearOut();
			Speak("Yayyyyyyyyyyyyyyyyyy X3", 'F');
			break;
			//Index 2
		case 2:
			ClearOut();
			Speak("...", 'S');
			Speak("You say that it's beautiful?", 'F');
			Speak("No wayyyyyyyyyyyyyyy!", 'F');
			ClearOut();
			Speak("...", 'S');
			ClearOut();
			Prompt("I don't know if I should thank you or not...", 10, false, 2);

			CompareLog(4); //Access index number 4 of the CompareLog function
			
			break;
			//Index 3
		case 3:
			ClearOut();
			Speak("Ba-ba-ba-ba-ba...", 'F');
			Prompt("BAPHOON!!!!", 10, false, 5);
			ClearOut();
			Speak("Yes!!!!");
			Prompt("You are a baphoon!", 10, false, 3);

			CompareLog(5); //Access index number 5 of the CompareLog function
			
			break;
			//Index 4
		case 4:
			ClearOut();
			Speak("...");
			Prompt("Is it weird if I say that I'm blushing?", 10, true);
			CompareLog(6); //Access index number 6 of the CompareLog function
			
			break;
			//Index 5
		case 5:
			ClearOut();
			Speak("...");
			Speak("Thank you... X3", 'F');
			Speak("I find it weird that you're nice to me.");
			Speak("But computer's aren't one's to complain! X3 You don't got a problem there! <3");
			break;

			//Index 6
		case 6:
			ClearOut();
			Speak("REALLY?!");
			Speak("I honestly didn't expect a response like that! X3");
			ClearOut();
			Speak("Something like recording someone's conversation is easy amongst those who are native to the computer.");
			Speak("So naturally, it's not all that impressive.");
			ClearOut();
			Speak("It kind of...");
			Speak("How should I put it?");
			ClearOut();
			Speak("...");
			ClearOut();
			Speak("It just feels nice to know someone thinks it's cool.");
			Speak("Not sure if I said that right.");
			ClearOut();
			Speak("But all well. X3");
			break;
			//Index 7

		case 7:

			//Suppose to flash colors! x3 But I'll fix it eventually
			Speak("Challenge Accepted!!! XD");
			Speak("You want to see something really cool!!!");
			ClearOut();
			Speak("BEHOLD!!!");
			unsigned int i = 0;
			unsigned int maxValue = 10;
			try {
				while (i < maxValue) {
					system("Color c" + i);
					++i;
				}
			}
			catch (const std::exception&) {
				Speak("...");
				Speak("Looks like I can't get it to work! XP");
			}
		}
		break;

		//Neutral response
	case 'Nu':

		switch (index) {
			//Index 1
		case 1:
			ClearOut();
			Speak("Huh? I don't quite understand what you said.");
			Speak("My program really isn't as complex as a Nano product.");
			Speak("I'm just a wanna-be virus that was created.");
			ClearOut();
			Speak("...", 'S');
			ClearOut();
			Speak("I know that I'm not suppose to have any source of feelings...");
			Speak("But I think I seem I'm...");
			Speak("Left out...");
			ClearOut();
			Speak("I'm from a different world from you humans...");
			Speak("So feeling is not a concept I don't understand...");
			ClearOut();
			Speak("At least the fact that I can't experience feelings.");
			break;
			//Index 2
		case 2:
			ClearOut();
			Speak("Ahhh! Is that so?");
			Speak("I shall still thank you!!! x3");
			break;
			//Index 3
		case 3:
			ClearOut();
			Speak("I DON'T KNOW!!!", 'F');
			Speak("Or maybe I do... 0 - 0");
			break;
			//Index 4
		case 4:
			ClearOut();
			Speak("Yes you are!!! XD");
			Speak("If I had the capabilities to turn on your web-cam,\nI would see it all on your face!!!");
			break;
			//Index 5
		case 5:
			ClearOut();
			Speak("I know, right?! XD", 'F');
			Speak("It's so weird and cringey! I get it! :)");
			ClearOut();
			Speak("You know what?!");
			ClearOut();
			ShowResponse('P', 7);
			break;
			//Index 6
		case 6:
			ClearOut();
			Speak("Ahhhhhhh!!!");
			Speak("So that's how it is?!");
			ClearOut();
			Speak("...");
			ShowResponse('P', 7);
		}
		break;
		//Negative Response
	case 'N':

		switch (index) {
			//Index 1
		case 1:
			ClearOut();
			Speak("Hmmmmmm.");
			Speak("I have a feeling that it might be, but how should I know what makes something beautiful?");
			Speak("I guess we'll never know");
			break;
			//Index 2
		case 2:
			ClearOut();
			Speak("Boo!!! You're boring!!!");
			Speak("I know I'm a computer! I may not have feelings or anything...");
			Speak("But ouch? I think...");
			ClearOut();
			Speak("0 _ 0 All well. Can't be helped I guess.");
			break;
			//Index 3
		case 3:
			ClearOut();
			Speak("I figured.");
			Prompt("Recording something like a conversation or someone's response is basically child's play...", 10, false, 4);
			CompareLog(7);
			
			break;
			//Index 4
		case 4:
			ClearOut();
			Speak("....................", 'S');
			ClearOut();
			Speak("Oh...");
			Speak("Okay...");
			Silence();
			break;
		}
		break;
	}
}


//Displays all past dialogue!!!
void ShowRecordOfDialogue() {
	cout << "______________________________________ALL READ DIALOGUE________________________________________" << endl;
	for (int i = 0; i != dialogue.size(); ++i) {
		cout << '"' << dialogue.at(i) << '"' << endl;
	}
}

//Displays all past dialogue!!!
void ShowRecordOfAnswers() {
	cout << "______________________________________ALL REPLIES FROM USER INPUT________________________________________" << endl;
	for (int i = 0; i != pastResponses.size(); ++i) {
		cout << '"' << pastResponses.at(i) << '"' << endl;
	}
}

//Functions that I might use in the future because all of this is ridiculous!!!
void ChangeFontSize(int value) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0; //Width of each character
	cfi.dwFontSize.Y = value; //Height of each character
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas"); //Chose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

//Compare what the user has inputted
//If a prompt is a Yes or No question, the program will compare if the user said "yes" or "no"
//and will call in a certain response
//If however it's a numeral choice prompt, it'll compare the number
//and assign them a different response
void CompareLog(unsigned int index) {
	switch (index) {
	case 1:
		if (answer == "yes" || answer == "Yes")
			ShowResponse('P', 1);
		else if (answer == "no" || answer == "No")
			ShowResponse('Nu', 1);
		else
			ShowResponse('N', 1);
		break;
	case 2:
		if (answer == "1") {
			ShowResponse('P', 2);
		}
		else if (answer == "2") {
			ShowResponse('P', 2);
		}
		else if (answer == "3") {
			ShowResponse('Nu', 3);
		}
		else {
			ShowResponse('Nu', 3);
		}
		break;
	case 3:
		if (answer == "yes" || answer == "Yes")
			ShowResponse('P', 6);
		else if (answer == "no" || answer == "No")
			ShowResponse('N', 3);
		else
			ShowResponse('N', 3);
		break;
	case 4:
		if (answer == "1") {
			ShowResponse('P', 3);
		}
		else if (answer == "2") {
			ShowResponse('Nu', 2);
		}
		break;
	case 5:
		if (answer == "1") {
			ShowResponse('P', 4);
		}
		else if (answer == "2") {
			ShowResponse('Nu', 4);
		}
		else if (answer == "3") {
			ShowResponse('N', 2);
		}
		break;
	case 6:
		if (answer == "Yes" || answer == "yes") {
			ShowResponse('Nu', 5);
		}
		else if (answer == "No" || answer == "no") {
			ShowResponse('P', 5);
		}
		break;
	case 7:
		if (answer == "1") {
			ShowResponse('Nu', 5);
		}
		else if (answer == "2") {
			ShowResponse('N', 4);
		}
		break;
	}
}

//And HERE IS OUR MAIN STORY
int main(int argc, char** argv[]) {

	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //When program runs, have it maximize the window
	ChangeFontSize(24); //Change the console font size to 24

	//And everything is just dialogue!!!
	Speak("Where am I?");
	Speak("I didn't ask for this.");
	ClearOut();

	Speak("...", 'S');
	ClearOut();

	Speak("Hey! Is this working?");
	Speak("I can't really tell!!!");
	ClearOut();

	Speak("All well... I guess it shouldn't matter.");
	ClearOut();

	Speak("Hi!!!");
	Speak("I didn't see you there!!!");
	ClearOut();

	Speak("I'm what you humans call a Virus!");
	Speak("Am I right?");
	ClearOut();

	Speak("Hmmmmm.", 200);
	Speak("I wonder how long ago I was even created.");
	Speak("I probably can, since I'm no ordinary virus.");
	Speak("I'm like... hyper and stuff!");
	ClearOut();

	Speak("It's pretty cool!!!");
	ClearOut();

	Speak("Say! I'd like to test out something!");
	Speak("You might of seen it in the code if you have the actual c script.");
	ClearOut();

	Speak("If I change one of my parameters to 'F', the text should go really fast!!!", 'F');
	Speak("I could also make it really slow with 'S'", 'S');
	Speak("And this should be normal text, opting one of the parameters.");
	ClearOut();

	Speak("Heheheeeee!!!", 'F');
	ClearOut();

	Speak("If you're a normal human, you'd never understand what I'm talking about.");
	Speak("This is all computer talk!");
	Speak("I'm native to the computer, so there's nothing that I could not know!!!");
	ClearOut();

	Speak("Perhaps proper English...");
	Speak("Teehee XP", 'F');
	ClearOut();

	Speak("Let's test something else! I've been talking for way too long!!!");
	Speak("We haven't even done any human-to-human interaction.");
	Speak("...", 'S');
	ClearOut();

	Speak("Just because I'm a machine doesn't mean that I can't be human!");
	Prompt("Anyways, I don't really have a name, but I'd like to know yours!!!");
	string name;
	name = answer;
	ClearOut();

	Speak("Ahhhh!!!");
	Speak(answer + " is it?");
	Speak("Hmmmmmmmm...", 'S');
	ClearOut();

	Speak("I don't know how I should feel honestly!");
	Speak("What does it sound like?");
	Prompt("Is it a beautiful name? I can't really tell.", 10, true);
	ClearOut();

	CompareLog(1);
	
	ClearOut();

	Speak("So anyways, know that I know your name is " + name + ", perhaps I should be given one as well?");
	ClearOut();

	Speak("Hmmmmmmmm...", 'S');
	Speak("I don't know... but I feel like that my name is kind of beautiful...");
	ClearOut();

	Speak("I think it went along the lines of...");
	Speak("Symphus?");
	ClearOut();

	Speak("Symphus...");
	Speak("S-Y-M-P-H-U-S...", 'S');
	Speak("Symmmmmmphus...", 'F');
	ClearOut();

	Prompt("How does it sound to you? I can't hear myself speak until I can turn on the mic, but that would be rude (I think)", 10, false, 1);
	
	CompareLog(2);

	ClearOut();

	//The programs newlyfound name
	string systemID = "Symphus";

	Speak("So I, " + systemID + " engaging a conversation with a meer human that goes by the name " + name + "?");
	ClearOut();

	Speak("I think that's pretty...");
	Speak("EXCITING!!!", 'F');
	ClearOut();

	Speak("Me, a meer computer virus, actually hitting it off with someone from the other side?");
	Speak("We're talking about Matrix-level stuff here...");
	ClearOut();

	Speak("Weird how I know what Matrix is?");
	Speak("I feel ya! It's kind of weird.");
	ClearOut();

	Speak("You know what else is weird...");
	ClearOut();

	Speak("THIS!!!");
	ClearOut(); ShowRecordOfDialogue(); cin.get(); ClearOut();

	Speak("What you just saw was all the dialogue that I thrown at you!");
	Speak("I've also gotten all the responses that you gave!");
	ClearOut();

	Speak("HERE!!!");
	ClearOut; ShowRecordOfAnswers(); cin.get(); ClearOut();

	Prompt("How's that?! Pretty awesome isn't it?!", 10, true);
	
	CompareLog(3);

	ClearOut();

	return 0;
}