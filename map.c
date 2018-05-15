/**
 * A simple HashTable using double hashing
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "models.h"


/**
 * Hash function 1
 *
 * @param pMap: pointer to the Map
 * @param key: the key that needs to be hashed
 */
static int mapHash1(Map *pMap, char key)
{
   return key % pMap->size;
}

/**
 * Hash function 2
 *
 * @param key: the key that needs to be hashed
 **/
static int mapHash2(char key)
{
   return key % 7 + 1;
}

/**
 * Create a new Map
 *
 * @param size: size of the Map
 * */
Map *mapCreate(int size)
{
   Map *pMap = calloc(1, sizeof(Map));
   pMap->size = size;
   pMap->ppFirst = calloc(size, sizeof(Node*));
   return pMap;
}

/**
 * Put a key/value pair to the Map
 *
 * @param pMap: pointer to the Map
 * @param key: the key
 * @param pNode: the value associated with the key above
 * */
void mapPut(Map *pMap, char key, Node *pNode)
{
   int hashedIndex = mapHash1(pMap, key);
   int step = mapHash2(key);

   while (pMap->ppFirst[hashedIndex] != NULL)
   {
      hashedIndex += step;
      hashedIndex %= pMap->size;
   }

   pMap->ppFirst[hashedIndex] = pNode;
}

/**
 * Get the value associated with a key
 *
 * @param pMap: pointer to the Map
 * @param key: the key
 * */
Node *mapGet(Map *pMap, char key)
{
   Node *pNode = NULL;
   int hashedIndex = mapHash1(pMap, key);
   int step = mapHash2(key);

   while (pMap->ppFirst[hashedIndex] != NULL)
   {
      if (pMap->ppFirst[hashedIndex]->key == key)
      {
         pNode = pMap->ppFirst[hashedIndex];
         break; 
      }
      hashedIndex += step;
      hashedIndex %= pMap->size;
   }

   return pNode;
}

/**
 * Free up the memory which was used for the Map
 *
 * @param pMap: pointer to the Map
 * */
void mapFree(Map *pMap)
{
   for (int i = 0; i < pMap->size; i++)
   {
      if (pMap->ppFirst[i])
      {
         if (pMap->ppFirst[i]->pChildren)
         {
            mapFree(pMap->ppFirst[i]->pChildren);
         }
         
         free(pMap->ppFirst[i]);
      }
   }
   
   free(pMap);
}
