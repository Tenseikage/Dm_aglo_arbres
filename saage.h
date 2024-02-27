#ifndef __SAAGE_H__
#define __SAAGE_H__
#include "arbres_binaires.h"
#include <stdio.h>

int serialise(char * nom_de_fichier, Arbre A);
void affiche_indente(Arbre a, int niveau, FILE *f);


#endif