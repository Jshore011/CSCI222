

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include "Hangman.h"
#include <fstream>
#include <string>
#define MAX_GUESS 7



using namespace std;


char Hangman::getUserGuess() //takes in usr guess
{
	cout << "Enter guess: ";
	cin >> guess;
	return guess;

}

void Hangman::printOut() {
	for (int i = 0; i < strlen(key); i++)
		cout << *(currentGuesses + i) << " ";
	cout << endl;
	cout << "number guesses left: " << guessLeft << endl;

}

bool Hangman::gameOver() //gameover method
{
	if (guessLeft == 0) {
		cout << endl << "You lost!"<< endl;
		cout << "The word was " << key << endl;
		return true;
	}
	for (int i = 0; i < strlen(key); i++) {
		if (*(currentGuesses + i) == '_') {
			return false;
		}
	}
	cout << endl << "You Win!";
	return true;
}

void Hangman::checkGuess() { //checks guesses
	for (int i = 0; i < strlen(key); i++) {
		if (guess == *(key + i)) {
			currentGuesses[i] = guess;
			return;
		}
	}
	for (int j = 0; j < MAX_GUESS; j++) { //error checking if user inputs the same leter
		if (guess == saveGuesses[j]) {
			cout << "choose another letter" << endl;
			return;
		}
		if ('_' == saveGuesses[j]) {
			cout << "bad guess" << endl;
			saveGuesses[j] = guess;
			guessLeft--;
			return;
		}
	}
}



void Hangman::getWord(char* filename) { //get's the word from file
	
	ifstream myfile (filename);
	srand(time(NULL));
	string line;
	getline(myfile, line);
	int rnum = rand() % stoi(line);
	for (int i = 0; i <= rnum; i++) {
		getline(myfile, line);
	}
	rnum = line.length();
	key = new char[rnum + 1];
	strcpy(key, line.c_str());
	currentGuesses= new char[strlen(key)+1];
	memset(currentGuesses, '_', strlen(key));
	currentGuesses[rnum] = '\0';
	key[rnum] = '\0';
	myfile.close();
}

Hangman::~Hangman() //deconstructor
{
	delete[] key, saveGuesses, currentGuesses;
	
}

Hangman::Hangman(char* filename)
{
	getWord(filename);
	saveGuesses = new char[MAX_GUESS];
	memset(saveGuesses, '_', MAX_GUESS);
	guessLeft = MAX_GUESS;
}

Hangman::Hangman() : Hangman((char*) "dictionary.txt") {}

int main(int args, char* argsv[]) { //plays hangman game
	Hangman* myGame;
	
	if (args == 1)
		myGame = new Hangman();
	else
		myGame = new Hangman(argsv[1]);

	cout << "----------Welcome to Hangman!----------" << endl;

	while (!myGame->gameOver()) {
		myGame->printOut();
		myGame->getUserGuess();
		myGame->checkGuess();
	}
	return 0;
}


