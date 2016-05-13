// Aaron Chelvan
// 27/04/16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void printLines(char *input);

int main (int argc, char * argv[]) {
   char *word = "antidisestablishmentarianism";
   printLines(word);
   int solvedStatus = FALSE;
   
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
   
   while (solvedStatus == FALSE) {
      printf("Enter a letter: ");
      char letter = NULL;
      scanf(" %c", &letter);
      
      //Check if 'letter' is in 'word'
      counter = 0;
      while (counter < strlen(word)) {
         if (word[counter] == letter) {
            checkArray[counter] = 1;
         } else {
            checkArray[counter] = 0;
         }
         counter++;
      }

      //solvedArray contains a number for each letter in 'word'
      //0 = that letter has not yet been guessed by the user
      //1 = that letter has been guessed by the user
      counter = 0;
      while (counter < strlen(word)) {
         if ((checkArray[counter] == 0) && (solvedArray[counter] == 0)){
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
   printf("YOU WIN!\n");
   return EXIT_SUCCESS;
}

void printLines(char *input) {
   int counter = 0;
   while (counter < strlen(input)) {
      printf("_ ");
      counter ++;
   }
   printf("\n");
}