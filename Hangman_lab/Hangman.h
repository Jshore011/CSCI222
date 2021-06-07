/*Programmer: jessica Shore
CSCI 222
Hangman Lab                */

#define _CRT_SECURE_NO_WARNINGS

#pragma once


class Hangman
{
private:
	char* key;		
	int guessLeft;
	char guess;
	char *saveGuesses;	
	char* currentGuesses;
	void getWord(char* filename);

public:
	Hangman();
	Hangman(char* filename);
	~Hangman();
	char getUserGuess();
	void printOut();
	bool gameOver();
	void checkGuess();
};

