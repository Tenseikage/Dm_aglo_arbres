#ifndef __GREFFE_H__
#define __GREFFE_H__
#include "arbres_binaires.h"

/* Prototype des fonctions */


/*Cette fonction copie l'arbre souce dans un arbre dest. Elle renvoie 1 si cela se passe
bien 0 sinon avec libération de l'arbre dest*/
int copie(Arbre* dest, Arbre source);

/*Cette fonction modifie l'arbre afin qu'elle puisse obtenir une nouvelle greffe. Elle renvoie 1 si tout se
passe bien, 0 sinon avec libération de l'arbre *a et b*/
int expansion(Arbre* A, Arbre B);

#endif