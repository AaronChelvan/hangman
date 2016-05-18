// Aaron Chelvan
// 27/04/16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void printIntro (void);
void printLines (char *input);
void printImage (int mistakes);

int main (int argc, char * argv[]) {
   char *word = "antidisestablishmentarianism";
   printLines(word);
   int solvedStatus = FALSE;
   int mistakes = 0;
   
   int solvedArray[(int)strlen(word)];
   //Fill solvedArray with zeroes
   int counter = 0;
   while(counter < strlen(word)) {
      solvedArray[counter] = 0;
      counter++;
   }

   int checkArray[(int)strlen(word)];
   //Fill checkArray with zeroes
   counter = 0;
   while(counter < strlen(word)) {
      checkArray[counter] = 0;
      counter++;
   }

   printIntro();
   
   while ((solvedStatus == FALSE) && (mistakes < 7)) {
      printf("=========================================\n");
      printf("Enter a letter: ");
      char letter = NULL;
      scanf(" %c", &letter);
      
      int unsolvedLetters = 0;
      //Check if 'letter' is in 'word'
      counter = 0;
      while (counter < strlen(word)) {
         if (word[counter] == letter) {
            checkArray[counter] = 1;
         } else {
            checkArray[counter] = 0;
            unsolvedLetters++;
         }
         counter++;
      }

      if (unsolvedLetters == strlen(word)) {
         mistakes++;
      }
      printf("Number of mistakes: %d\n", mistakes);
      printImage(mistakes);

      //solvedArray contains a number for each letter in 'word'
      //0 = that letter has not yet been guessed by the user
      //1 = that letter has been guessed by the user
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
      counter = 0;
      while(counter < strlen(word)) {
         checkArray[counter] = 0;
         counter++;
      }

      //Count how many letters have been found
      int solvedLetters = 0;
      counter = 0;
      while (counter < strlen(word)) {
         if (solvedArray[counter] == 1) {
            solvedLetters++;
         }
         counter++;
      }      

      //Check if all letters have been found
      if (solvedLetters == strlen(word)) {
         solvedStatus = TRUE;
      }

      //Print out the word
      //'_' represent letters that have not yet been guessed
      counter = 0;
      while (counter < strlen(word)) {
         if (solvedArray[counter] == 0) {
            printf("_");
         } else if (solvedArray[counter] == 1) {
            printf("%c", word[counter]);
         }
         counter++;
      }
      printf("\n");  
      printf("\n");   
   }

   if (mistakes == 7) {
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
   printf("\n");
   printf("Guess the word in less than 7 mistakes to win.\n");
   printf("\n");
}

void printLines(char *input) {
   int counter = 0;
   while (counter < strlen(input)) {
      printf("_ ");
      counter ++;
   }
   printf("\n");
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