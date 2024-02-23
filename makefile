CFLAGS = -std=c17 -pedantic -Wall
CC = gcc
OBJ = Main.o Saage.o Greffe.o Arbre.o
VARIANTS = saage
TARGETS = $(addprefix $(VARIANTS)_, $(VARIANTS))

arbre_greffe: saage

saage: $(OBJ)
	$(CC) -o $@ $^

Main.o: main.c arbres_binaires.h greffe.h saage.h
	$(CC) $(CFLAGS) -c -o $@ $<

Saage.o: saage.c saage.h arbres_binaires.h
	$(CC) $(CFLAGS) -c -o $@ $<

Greffe.o: greffe.c greffe.h arbres_binaires.h 
	$(CC) $(CFLAGS) -c -o $@ $<

Arbre.o: arbres_binaires.c arbres_binaires.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	$(RM) *.o $(TARGETS)