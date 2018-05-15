CC = gcc
CC_FLAGS = -g -pedantic -Wall -W -std=c99

FILES = main.c trie.c map.c
OUT_EXE = trie

build: $(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES) 

clean:
	rm -f *.o core *.exe *~ *.out *.stackdump

rebuild: clean build
