#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const string MAIN_DIALOGUE1 = "You wake up and find yourself inside an alien starship. There's a number pad on the door.";
const string MAIN_DIALOGUE2 = "You need to escape but to do so you need to guess the correct code.";
const string MAIN_DIALOGUE3 = "The number pad has instructions on it.";
const string MAIN_DIALOGUE3_TIP1 = " - The code is 3 numbers long";
const string MAIN_DIALOGUE3_TIP2 = " - They add up to: ";
const string MAIN_DIALOGUE3_TIP3 = " - Their product is: ";
const string PLAYER_CODE_GUESS_HEADER = "Enter your guess (separated by space): ";
const string PLAYER_GUESS_CORRECT = "YES! You guessed it right. he door opens and you can move to room number ";
const string PLAYER_GUESS_INCORRECT = "OH NO, you guessed it wrong! The number pad says you have ";
const string PLAYER_GUESS_INCORRECT_CONT = " tries left. Be careful or you might trigger the alarm.";
const string GAME_END_WIN = "THAT'S IT! You escaped the ship! Now you can find your way home.";
const string GAME_END_LOOSE = "OH NO! THE ALARM! The aliens found you trying to escape on room number ";
const string WRONG_INPUT = "The ship detected a wrong input. It changed the code!";
const int PLAYER_TRIES = 3;

void PrintIntro();
void PlayGame(int& PlayerTries, int& Start);



int main() {
	srand(time(NULL)); //random sequence based on time of day
	int StartRoom = 1;
	int FinishRoom = 4; //represents the number of rooms to escape
	int PlayerTries = PLAYER_TRIES;

	PrintIntro();


	while (StartRoom <= FinishRoom) {

		if (PlayerTries == 0) {
			return 0;
		}

		PlayGame(PlayerTries, StartRoom);
		cin.clear();
		cin.ignore();

	}

	cout << GAME_END_WIN << endl;

	return 0;
}


void PrintIntro() {
	cout << MAIN_DIALOGUE1 << endl << endl;
	cout << MAIN_DIALOGUE2 << endl << endl;
	cout << MAIN_DIALOGUE3 << endl << endl;

}


void PlayGame(int& PlayerTries, int& Start) {


	int CodeA = rand() % Start + Start; //increase difficulty
	int CodeB = rand() % Start + Start;
	int CodeC = rand() % Start + Start;


	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;

	cout << MAIN_DIALOGUE3_TIP1 << endl;
	cout << MAIN_DIALOGUE3_TIP2 << CodeSum << endl;
	cout << MAIN_DIALOGUE3_TIP3 << CodeProduct << endl << endl;

	int PlayerGuessA, PlayerGuessB, PlayerGuessC;
	cout << PLAYER_CODE_GUESS_HEADER << endl;
	cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;

	int PlayerGuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
	int PlayerGuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;

	if (PlayerGuessSum == CodeSum && PlayerGuessProduct == CodeProduct) {
		++Start; //increments start -> moves to next room
		cout << endl << PLAYER_GUESS_CORRECT << Start << endl << endl;;
		PlayerTries = PLAYER_TRIES; //reset PlayerTries for next door.
	}
	else {
		--PlayerTries;
		if (PlayerTries == 0) {
			cout << endl << GAME_END_LOOSE << Start << endl;
		}
		else {
			cout << endl << PLAYER_GUESS_INCORRECT << PlayerTries << PLAYER_GUESS_INCORRECT_CONT << endl << endl;
			cout << WRONG_INPUT << endl << endl;
		}

	}
}