/*
Ashlyn Buckley
* 22440672
* Date:27/2/23
*/
#include <stdio.h>
#include <string.h>
#include <time.h>

int rnd(int lower, int upper);

#define MAXSTRING 100

char dict[100000][MAXSTRING];
int countNum = 0; //amount of words

int main() {
	// fopen requests a file to be opened obtains a FILE pointer to access it
	FILE* file_ptr;
	fopen_s(&file_ptr, "C:\\Users\\ashly\\Downloads\\Programming\\dictionary.txt", "r"); // open for reading

	if (file_ptr == NULL)
		printf("Could not open dictionary.txt");
	else {
		char txt[MAXSTRING]; // string for reading each line into
		int lines = 0;
		while (fgets(dict[countNum], MAXSTRING - 1, file_ptr) != NULL) {
			int length = strlen(dict[countNum]);

			dict[countNum][length - 1] = '\0'; // remove the \n which has also been read into the string!
			--length;
			//printf("%s\n", txt);


			//removing words
			if (length >= 4 && length <= 7) {
				++countNum; //if valid add here
			}

		}
		printf("\ndictionary.txt has %d suitable words.\n\n", countNum);

		//get a random word
		int randi = rnd(1, countNum); //pick a random number
		char* randWord = dict[randi]; //pick a word based on the index of the array
		printf("The word: %s\n", dict[randi]); //using to check if rand is working
		int lenWord = strlen(dict[randi]);
		char guessWord[10]; //set initial size 


		for (int i = 0; i < lenWord; i++) {
			guessWord[i] = '-'; //print out the word in dashes
		}
		guessWord[lenWord] = '\0';


		//player guessing
		char theGuess;
		int guesscount = 0;
		int correctguess = lenWord;
		while (correctguess > 0)
		{
			for (int i = 0; i < lenWord; i++) {
				printf("%c", guessWord[i]);
			}
			correctguess = 0;
			printf("\nGuess a letter: ");
			scanf_s("%c", &theGuess);

			for (int k = 0; k < lenWord; k++) { //sequentially checking each character
				if (guessWord[k] == '-') {
					if (randWord[k] == theGuess) { //if the char is the guess then make the same character in the guessWord the guess to "reveal" it
						guessWord[k] = theGuess;
						guesscount++;
					}
					else
					{
						correctguess++; //increments correct guess
					}
				}
			}
		}
		printf("\nYou have uncovered the word!\n");
		printf("It took %d guesses.\n", guesscount);
	}


	fclose(file_ptr); // don't forget to close the file	
	return 0;
}

int rnd(int lower, int upper) {
	srand(time(0));
	int range = (upper - lower) + 1;
	return (rand() % range) + lower;
}

