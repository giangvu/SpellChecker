#ifndef TRIE_H
#define TRIE_H

Node *trieCreateNode(char key, bool isEndWord);
void trieInsertWord(Node **ppRootNode, char *word);
bool trieFindWord(Node *pRootNode, char *word);
void trieFree(Node *pRootNode);

#endif
