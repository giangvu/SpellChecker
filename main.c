/**
 * A simple spell check console application
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "models.h"
#include "trie.h"

#define MAX_WORD_LENGTH 50
#define WORD_FILE "words.txt"

void removeNewLineCharacter(char *word);

int main(void)
{
   FILE *file = fopen(WORD_FILE, "r");
     
   if (file)
   {
      Node *pRootNode = NULL;
      char word[MAX_WORD_LENGTH];
      
      // read all words from file an store them in the Trie 
      while (fgets (word, sizeof(word), file) != NULL)
      {
         removeNewLineCharacter(word);
         trieInsertWord(&pRootNode, word);
      }
      
      // get user's input
      printf("SpellChecker - Please provide a word to check for spelling: \n");
      
      char userInput[MAX_WORD_LENGTH];
      fgets(userInput, sizeof(userInput), stdin);

      removeNewLineCharacter(userInput);

      // validating and printing result
      if (trieFindWord(pRootNode, userInput))
      {
         printf("%s is a valid English word.\n", userInput);
      }
      else
      {
         printf("%s is an invalid English word.\n", userInput);
      }
     
      // clean up
      trieFree(pRootNode);
      fclose(file);
   }
   else
   {
      fprintf(stderr, "Can not open file: %s", WORD_FILE);
      return EXIT_FAILURE;
   }
   
   return EXIT_SUCCESS;
}

/* 
 * remove new line character at the end of a word
 * @param word: the word that needs to eliminate the new line character
**/
void removeNewLineCharacter(char *word)
{
   if (word[strlen(word) - 1] == '\n')
   {
      word[strlen(word) - 1] = '\0';  
   }
}
