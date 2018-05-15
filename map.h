#include "models.h"

#ifndef MAP_H
#define MAP_H

Map *mapCreate(int size);
Node *mapGet(Map *pMap, char key);
void mapPut(Map *pMap, char key, Node *pNode);
void mapFree(Map *pMap);

#endif

