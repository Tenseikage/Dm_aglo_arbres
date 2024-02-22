#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arbres_binaires.h"



Noeud* alloue_noeud(char *s) {
    Noeud *nouv_noeud = (Noeud*)malloc(sizeof(Noeud));
    if (nouv_noeud == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(1);
    }
    nouv_noeud->val = strdup(s); // strdup() alloue de la mémoire pour la chaîne de caractères et copie la chaîne dans cette mémoire
    nouv_noeud->fg = NULL;
    nouv_noeud->fd = NULL;
    return nouv_noeud;
}


void liberer(Arbre *a) {
    if (a != NULL) {
        liberer(&((*a)->fg));
        liberer(&((*a)->fd));
        free((*a)->val);
        free(a);
    }
}


Arbre cree_A_1(void) {
    Arbre a_1 = alloue_noeud("A");
    a_1->fg = alloue_noeud("B");
    a_1->fd = alloue_noeud("C");
    a_1->fg->fg = alloue_noeud("D");
    a_1->fg->fd = alloue_noeud("E");
    a_1->fd->fg = alloue_noeud("F");
    a_1->fd->fd = alloue_noeud("G");
    return a_1;
}


Arbre cree_A_2(void) {
    Arbre a_2 = alloue_noeud("A");
    a_2->fg = alloue_noeud("B");
    a_2->fd = alloue_noeud("C");
    a_2->fg->fg = alloue_noeud("D");
    a_2->fg->fd = alloue_noeud("E");
    a_2->fd->fg = alloue_noeud("F");
    a_2->fd->fd = alloue_noeud("G");
    a_2->fg->fg->fg = alloue_noeud("H");
    a_2->fg->fg->fd = alloue_noeud("I");
    return a_2;

}


Arbre cree_A_3(void) {
    Arbre a_3 = alloue_noeud("Bonjour");
    a_3->fg = alloue_noeud("Hatsune Miku");
    a_3->fd = alloue_noeud("C");
    return a_3;
}


void affiche_indente(Arbre a, int niveau) {
    if (a != NULL) {
        for (int i = 0; i < niveau; i++) {
            printf("  ");
        }
        printf("%s\n", a->val);
        affiche_indente(a->fg, niveau + 1);
        affiche_indente(a->fd, niveau + 1);
    }
}


int main(int argc, char const *argv[])
{
    Arbre a_1 = cree_A_1();
    affiche_indente(a_1, 0);
    return 0;
}
