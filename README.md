# SpellChecker


$ make
  gcc -g -pedantic -Wall -W -std=c99 -o trie main.c trie.c map.c 
$ ./trie
  SpellChecker - Please provide a word to check for spelling: 
  unlooped
  unlooped is a valid English word.
$ ./trie
  SpellChecker - Please provide a word to check for spelling: 
  daswerfxvdfdfsd
  daswerfxvdfdfsd is an invalid English word. 
