#ifndef __SAAGE_H__
#define __SAAGE_H__
#include "arbres_binaires.h"
#include <stdio.h>

/*Cette fonction indente les données d'un arbre pour
la création d'un fichier .saage. Elle renvoie 1 si cela a réussi et 0 sinon*/
int affiche_indente(Arbre a, int niveau, FILE *f);


/* Cette fonction crée un fichier .saage contenant la description de l'arbre a. Cette fonction renvoie
1 si elle s'est bien passée et 0 sinon avec la suppresion du fichier par son nom entré en argument*/
int serialise(char * nom_de_fichier, Arbre A);


/*Cette fonction lit lee fichier .saage dont le nom est passé en argument et crée l'arbre *a.
Cette fonction renvoie 1 si c'est bien passé 0 sinon avec libération de l'arbre */
int deserialise(FILE* f, Arbre* A, int iteration);


#endif