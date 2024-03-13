CFLAGS = -std=c17 -pedantic -Wall
CC = gcc
OBJ = main.o saage.o greffe.o arbres_binaires.o
VARIANTS = saage
TARGETS = $(addprefix $(VARIANTS)_, $(VARIANTS))

arbre_greffe: saage

saage: $(OBJ)
	$(CC) -o $@ $^

main.o: main.c arbres_binaires.h greffe.h saage.h
	$(CC) $(CFLAGS) -c -o $@ $<

saage.o: saage.c saage.h arbres_binaires.h
	$(CC) $(CFLAGS) -c -o $@ $<

greffe.o: greffe.c greffe.h arbres_binaires.h 
	$(CC) $(CFLAGS) -c -o $@ $<

arbres_binaires.o: arbres_binaires.c arbres_binaires.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	$(RM) *.o $(TARGETS)