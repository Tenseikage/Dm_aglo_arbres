saage:Arbre.o Greffe.o Saage.o Main.o
	gcc -o saage Main.o Saage.o Greffe.o Arbre.o

Main.o: main.c arbres_binaires.h greffe.h saage.h
	gcc -std=c17 -pedantic -Wall -c -o Main.o main.c

Saage.o: saage.c saage.h arbres_binaires.h
	gcc -std=c17 -pedantic -Wall -c -o Saage.o saage.c

Greffe.o: greffe.c greffe.h arbres_binaires.h 
	gcc -std=c17 -pedantic -Wall -c -o Greffe.o greffe.c

Arbre.o: arbres_binaires.c arbres_binaires.h
	gcc -std=c17 -pedantic -Wall -c -o Arbre.o arbres_binaires.c