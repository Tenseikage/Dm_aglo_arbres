#ifndef __SAAGE_H__
#define __SAAGE_H__
#include "arbres_binaires.h"
#include <stdio.h>

// Permet de serialiser un arbre dans un fichier .saave
int serialise(char * nom_de_fichier, Arbre A);


// Permet de deserialiser un arbre venant d'un fichier .saave
int deserialise(char* nom_de_fichier);


#endif