# SpellChecker


$ make </br>
gcc -g -pedantic -Wall -W -std=c99 -o trie main.c trie.c map.c </br>
$ ./trie </br>
SpellChecker - Please provide a word to check for spelling: </br>
unlooped </br>
unlooped is a valid English word. </br>
$ ./trie </br>
SpellChecker - Please provide a word to check for spelling: </br>
daswerfxvdfdfsd </br>
daswerfxvdfdfsd is an invalid English word. </br>
