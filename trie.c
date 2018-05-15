/**
 * A simple Trie data structure for storing words
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "models.h"
#include "map.h"

#define MAP_SIZE 50

/**
 * Create a new Node
 *
 * @param key: the character represent this Node
 * @param isEndWord: true if this key character at the end of word, false otherwise
 * */
Node *trieCreateNode(char key, bool isEndWord)
{
   Node *pNode = calloc(1, sizeof(Node));
   pNode->key = key;
   pNode->isEndWord = isEndWord;
   
   return pNode;
}

/**
 * Insert a word into Trie, create Nodes if needed
 *
 * @param ppRootNode: address of the root Node. 
 * @param word: the word to insert
 * */
void trieInsertWord(Node **ppRootNode, char *word)
{
   // create root Node if doesn't exist
   if (!*ppRootNode)
   {
      *ppRootNode = trieCreateNode(-1, false);
   }
      
   Node *pCurrentNode = *ppRootNode;
   for(size_t i = 0; i < strlen(word); i++)
   {
      char key = word[i];

      // create a hashmap that stores all the children of current Node
      if (!pCurrentNode->pChildren)
      {
         pCurrentNode->pChildren = mapCreate(MAP_SIZE);
      }
      
      // create child Node if needed  
      Node *pNode = mapGet(pCurrentNode->pChildren, key);
      if (!pNode)
      {
         bool isEndWord = i == (strlen(word) - 1);
         pNode = trieCreateNode(key, isEndWord);
         mapPut(pCurrentNode->pChildren, key, pNode);
      }         
      pCurrentNode = pNode;
   }
}

/**
 * Check whether the provided word matches a word in the Trie or not
 * 
 * @param pRootNode: pointer to the root Node of the Trie
 * @param word: the word need to be verified
 * */
bool trieFindWord(Node *pRootNode, char *word)
{
   Node *pCurrentNode = pRootNode;
   for(size_t i = 0; i < strlen(word); i++)
   {
      if (!pCurrentNode->pChildren)
      {
         break;
      }
      
      Node *pNode = mapGet(pCurrentNode->pChildren, word[i]);
      
      if (!pNode)
      {
         break;
      }

      if (i == strlen(word) - 1 && pNode->isEndWord)
      {
         return true;
      }

      pCurrentNode = pNode;
   }

   return false;
}

/**
 * Free up the memory which was allocated for the Trie
 * 
 * @param pRootNode: pointer to the root Node of the Trie
 * */
void trieFree(Node *pRootNode)
{
   if (pRootNode)
   {
      mapFree(pRootNode->pChildren);
      free(pRootNode);
   }
}
