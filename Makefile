spellcheck.o: spellcheck.c dictmod.c dictmod.h
	gcc -c -Wall --pedantic spellcheck.c
dictmod.o: dictmod.c dictmod.h
	gcc -c -Wall --pedantic dictmod.c
spellcheck: spellcheck.o dictmod.o
	gcc -o spellcheck spellcheck.o dictmod.o
all: spellcheck

clean:
	rm -f spellcheck.o dictmod.o spellcheck
tarball: spellcheck.c dictmod.c dictmod.h Makefile
	tar -c -f spellcheck.tar -v spellcheck.c dictmod.c dictmod.h Makefile
