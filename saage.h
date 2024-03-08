#ifndef __SAAGE_H__
#define __SAAGE_H__
#include "arbres_binaires.h"
#include <stdio.h>

// PErmet d'afficher l'arbre indenter façon .saage
void affiche_indente(Arbre a, int niveau, FILE *f);


// Permet de serialiser un arbre dans un fichier .saave
int serialise(char * nom_de_fichier, Arbre A);


// Permet de deserialiser un arbre venant d'un fichier .saave
int deserialise(FILE* f, Arbre* A, int iteration);


#endif