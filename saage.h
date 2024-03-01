#ifndef __SAAGE_H__
#define __SAAGE_H__
#include "arbres_binaires.h"
#include <stdio.h>
#define LENGTH_VALUE 64

// Permet de serialiser un arbre dans un fichier .saave
int serialise(char * nom_de_fichier, Arbre A);


// Permet de deserialiser un arbre venant d'un fichier .saave
void deserialise(FILE* f, Arbre* A, int iteration);


#endif