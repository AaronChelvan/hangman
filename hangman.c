// Aaron Chelvan
// Started on: 27/04/16
// Most recent update: 02/07/16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_WORD_LENGTH 50

void printIntro (void); 
//Prints the intro ASCII image

int checkLowercase (char *inputString); 
//Checks if a given string contains ONLY lowercase characters

void printImage (int mistakes);
//Prints an ASCII image of the stick figure being hanged

int main (int argc, char * argv[]) {
   printIntro();

   //Create an array of strings - this is the word bank
   printf("How many words in the word bank? (Enter an integer)\n");
   int numOfWords = 0;
   scanf("%d", &numOfWords);
   char wordList[numOfWords][MAX_WORD_LENGTH]; 
   printf("\n");

   //Fill the word bank with words inputted by the user
   int counter = 0;
   while (counter < numOfWords) {
      printf("What is word %d?\n", (counter + 1));
      printf("(Maximum permitted word length is 50 letters)\n");
      printf("(Lowercase letters ONLY)\n");
      char inputString[MAX_WORD_LENGTH];
      scanf("%s", inputString);

      //Check if the inputted string contains only lowercase letters
      if (checkLowercase(inputString) == TRUE) {
         //Copy the inputted string into the word bank
         int counter2 = 0;
         for (counter2 = 0; counter2 < MAX_WORD_LENGTH; counter2++) {
            wordList[counter][counter2] = inputString[counter2];
         }
         counter++;
         printf("\n");
      } else {
         printf("Invalid input. Try again.\n");
         printf("\n");
         continue;
      }
   }

   //Randomly choose a word from the list
   srand(time(NULL));
   int wordNum = rand()%numOfWords;
   char *word = &wordList[wordNum][0];

   int solvedStatus = FALSE;
   int mistakes = 0;
   
   //solvedArray contains a number for each letter in the word
   //0 = that letter has not yet been guessed by the user
   //1 = that letter has been guessed by the user
   //E.g. If the word is 'apple' and the user has guessed
   //'p' and 'a' so far, solvedArray would be: [1,1,1,0,0]
   int solvedArray[(int)strlen(word)];
   //Fill solvedArray with zeroes
   for (counter = 0; counter < strlen(word); counter++) {
      solvedArray[counter] = 0;
   }

   //checkArray contains a number for each letter in the word 
   //0 = the current letter being guessed is not this letter
   //1 = the current letter being guessed is this letter
   //E.g. If the word is 'apple' and the user has guessed
   //'a' on the previous turn but 'p' this turn, 
   //checkArray would be: [0,1,1,0,0] (only takes into account
   //the current guess)
   int checkArray[(int)strlen(word)];
   //Fill checkArray with zeroes
   for (counter = 0; counter < strlen(word); counter++) {
      checkArray[counter] = 0;
   }

   printf("Let's Start!\n");
   
   while ((solvedStatus == FALSE) && (mistakes < 7)) {
      printf("=========================================\n");
      printf("The word contains %d letters.\n", (int)strlen(word));
      printf("Enter a letter: ");
      
      char letter = NULL;
      scanf(" %c", &letter);
      
      int unsolvedLetters = 0;
      //Check if 'letter' is in 'word'
      for (counter = 0; counter < strlen(word); counter++) {
         if (word[counter] == letter) {
            checkArray[counter] = 1;
         } else {
            checkArray[counter] = 0;
            unsolvedLetters++;
         }
      }

      if (unsolvedLetters == strlen(word)) {
         mistakes++;
      }
      printf("Number of mistakes: %d\n", mistakes);
      printImage(mistakes);

      counter = 0;
      while (counter < strlen(word)) {
         if ((checkArray[counter] == 0) &&
             (solvedArray[counter] == 0)){
            solvedArray[counter] = 0;
         } else {
            solvedArray[counter] = 1;
         }
         counter++;
      }
      
      //Fill checkArray with zeroes
      for (counter = 0; counter < strlen(word); counter++) {
         checkArray[counter] = 0;
      }

      //Count how many letters have been found
      int solvedLetters = 0;  
      for (counter = 0; counter < strlen(word); counter++) {
         if (solvedArray[counter] == 1) {
            solvedLetters++;
         }
      }

      //Check if all letters have been found
      if (solvedLetters == strlen(word)) {
         solvedStatus = TRUE;
      }

      //Print out the word
      //'_' represent letters that have not yet been guessed
      for (counter = 0; counter < strlen(word); counter++) {
         if (solvedArray[counter] == 0) {
            printf("_");
         } else if (solvedArray[counter] == 1) {
            printf("%c", word[counter]);
         }
      }
      printf("\n");  
      printf("\n");   
   }

   if (mistakes == 7) {
      printf("Correct word was: %s\n", word);
      printf("YOU LOSE!\n\n");
   } else {
      printf("YOU WIN!\n\n");
   }
   
   return EXIT_SUCCESS;
}

void printIntro (void) {
   printf("=========================================\n");
   printf("|  |  __         ___            __          \n");
   printf("|__| |  | |\\  | |     |\\    /| |  | |\\  |\n");
   printf("|  | |__| | \\ | | __  | \\  / | |__| | \\ |\n");
   printf("|  | |  | |  \\| |___| |  \\/  | |  | |  \\|\n");
   printf("=========================================\n");
   printf("By Aaron Chelvan\n");
   printf("\n");
   printf("Guess the word in less than 7 mistakes to win.\n");
   printf("\n");
}

int checkLowercase (char *inputString) {
   int counter = 0;
   while (counter < strlen(inputString)) {
      //If the character is not a lowercase letter, return 'false' 
      if (!('a' <= inputString[counter] && inputString[counter] <= 'z')) {
         return FALSE;
      } else {
         counter++;
      }
   }
   return TRUE;
}

void printImage (int mistakes) {
   if (mistakes == 0) {
      printf("-----------------------------\n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("-----------------------------\n");
   } else if (mistakes == 1) {
      printf("-----------------------------\n");
      printf("     |            |          \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("-----------------------------\n");
   } else if (mistakes == 2) {
      printf("-----------------------------\n");
      printf("     |            |          \n");
      printf("     |            O          \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("-----------------------------\n");
   } else if (mistakes == 3) {
      printf("-----------------------------\n");
      printf("     |            |          \n");
      printf("     |            O          \n");
      printf("     |            |          \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("-----------------------------\n");
   } else if (mistakes == 4) {
      printf("-----------------------------\n");
      printf("     |            |          \n");
      printf("     |            O          \n");
      printf("     |           -|          \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("-----------------------------\n");
   } else if (mistakes == 5) {
      printf("-----------------------------\n");
      printf("     |            |          \n");
      printf("     |            O          \n");
      printf("     |           -|-         \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("-----------------------------\n");
   } else if (mistakes == 6) {
      printf("-----------------------------\n");
      printf("     |            |          \n");
      printf("     |            O          \n");
      printf("     |           -|-         \n");
      printf("     |           /           \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("-----------------------------\n");
   } else if (mistakes == 7) {
      printf("-----------------------------\n");
      printf("     |            |          \n");
      printf("     |            O          \n");
      printf("     |           -|-         \n");
      printf("     |           / \\         \n");
      printf("     |                       \n");
      printf("     |                       \n");
      printf("-----------------------------\n");
   }
}