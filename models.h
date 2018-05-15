#include <stdbool.h>

#ifndef MODELS_H
#define MODELS_H

typedef struct _node Node;
typedef struct _map Map;

struct _node
{
   char key;
   bool isEndWord;
   Map *pChildren;
};

struct _map
{
   int size;
   Node **ppFirst;
};

#endif
