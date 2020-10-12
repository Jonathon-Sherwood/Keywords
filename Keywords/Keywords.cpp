/*
	Jonathon Sherwood
	10/11/2020
	Keywords: Practice in Arrays and Strings
*/


#include <iostream> //Used to display messages to the console
#include <string> //Allows for strings to be used as variables
#include <cstdlib> //Used for number randomizing
#include <ctime> //Uses time for the seed in randomizing


using std::cout; //Global declaration to shorten the cout command namespace throughout the code

using std::cin; //Global declaration to shorten the cin command namespace throughout the code

using std::endl; //Global declaration to shorten the endl command namespace throughout the code

using std::string; //Global declaration to shorten the string command namespace throughout the code


int main() //Starting function containig our code found in every C++ file 
{
	bool gameBegin = false; //Holds the bool of playing or not
	char playerResponse; //Holds the response from the player to play again or not

	do //Holds entire gameplay loop 
	{
		gameBegin = false; //Stops the game from exiting prematurely

		int correctGuess = 0; //Holds the amount of correct guesses
		int wrongGuesses = 0; //

		cout << "\t\t Begin Code Breaking\n\n";
		cout << "Think sharp, recruit! The enemy has scrambled their intel!\n";
		cout << "It's up to you to unscramble it and save our world!\n";
		cout << "There are 3 scrambled words you must get through to pass.\n";
		cout << "Type 'hint' for a hint! Use this sparingly.\n";
		cout << "Type 'quit' to give up and be fired.\n\n";

		do {//Creates human-readable words for accessing the array
			enum fields { WORD, HINT, NUM_FIELDS };

			//Declares max number of words
			const int NUM_WORDS = 10;

			//Creates 2 dimensional array of words and hints
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				{"red", "The color of firetrucks."},
				{"mouse", "Eats cheese and points at your computer."},
				{"pillow", "Rests your head after a long day."},
				{"world", "We're all livin' in it."},
				{"jazz", "The coffee of music."},
				{"keyboard", "You're typing on it right now!"},
				{"ring", "Pick up the phone!"},
				{"fan", "I'm your biggest."},
				{"pen", "It's mightier than the sword."},
				{"sword", "It's mightier than the pen."},
			};

			srand(time(NULL)); //Uses computer time for random seed
			int choice = (rand() % NUM_WORDS); //Makes a variable that is randomized from word list
			string theWord = WORDS[choice][WORD]; //Chooses the word to guess
			string theHint = WORDS[choice][HINT]; //Gets the hint for the chosen word

			string jumble = theWord; //Holds the jumble-able word without editting the const string
			int length = jumble.size(); //Gets the length of the word to be jumbled

			for (int i = 0; i < length; ++i) //Repeats as many times as there are letters in the word
			{
				int index1 = (rand() % length); //Picks random letter in word
				int index2 = (rand() % length); //Picks second random letter in word
				char temp = jumble[index1]; //Assigns variable to randomized letter
				jumble[index1] = jumble[index2]; //Places random letter in other letter's place
				jumble[index2] = temp; //Replaces swapped letter with first randomly chosen one
			}

			cout << "Word #" << correctGuess + 1 << " is: " << jumble;

			string guess; //Holds player guess
			cout << "\nYour guess: ";
			cin >> guess; //Takes in player guess

			while ((guess != theWord) && (guess != "quit")) //Plays game until player wrongGuesses correctly or quits
			{
				if (guess == "hint")  //Gives the player a hint when requested
				{
					cout << "\n'" << theHint << "'";
					cout << "\nThe word was: " << jumble;
				}
				else
				{
					cout << "\nWrong! Don't forget, you can type 'hint' for help!";
					cout << "\nThe word was: " << jumble;
					wrongGuesses++; //Adds up attempted wrongGuesses
				}

				cout << "\nYour Guess: ";
				cin >> guess;
			}

			if (guess == "quit") //Exits program if guess is 'quit'
			{
				exit(0);
			}

			if (guess == theWord) //Adds one point each correct guess
			{
				cout << "\n\nYep! You guessed it!\n";
				correctGuess++;
			}
		} while (correctGuess < 3); //Continues loop until 3 correct guesses

		if (wrongGuesses == 0) //Unique message for perfect score
		{
			cout << "\nI don't believe it! You got every guess right!\n";
			cout << "Excellent work, rookie. You're ready for the real thing!\n\n";
		}
		else if (wrongGuesses < 10 && wrongGuesses != 0)  //Unique message for low wrong guesses
		{
			cout << "\nWow! And you only missed " << wrongGuesses << " guesses!\n";
			cout << "Excellent work, rookie. You're ready for the real thing!\n\n";
		}
		else //Unique message for high wrong guesses
		{
			cout << "\nYou need to do better. You got " << wrongGuesses << " guesses wrong...\n";
			cout << "Maybe you should try again?\n\n";
		}

		cout << "Do you want to try again? Y/N: ";
		cin >> playerResponse;

		if (playerResponse == 'y') //Resets game on user input
		{
			system("CLS"); //Clears screen
			gameBegin = true;
		}
		else if (playerResponse == 'n') //Exits game on user input
		{
			exit(0);
		}
	} while (gameBegin); //Continues the game until user exits

	return 0;
}