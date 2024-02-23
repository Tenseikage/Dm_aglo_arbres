#ifndef __GREFFE_H__
#define __GREFFE_H__
#include "arbres_binaires.h"

/* Prototype des fonctions */


// Copie l'arbre `source` dans `dest`
// En cas d'erreur d'allocation, libere `dest`
int copie(Arbre* dest, Arbre source);

// Greffe l'arbre B a l'arbre A
int expansion(Arbre* A, Arbre B);

#endif