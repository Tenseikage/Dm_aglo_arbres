#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
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
    if (*a != NULL) {
        liberer(&((*a)->fg));
        liberer(&((*a)->fd));
        free((*a)->val);
        free(*a);
        *a = NULL;
    }
} 


Arbre cree_A_1(void) {
    Arbre a_1 = alloue_noeud("arbre");
    a_1->fg = alloue_noeud("binaire");
    a_1->fd = alloue_noeud("ternaire");
    return a_1;
}


Arbre cree_G_1(void) {
    Arbre g_1 = alloue_noeud("binaire");
    g_1->fg = alloue_noeud("lexicographique");
    g_1->fd = alloue_noeud("n-aire");
    return g_1;
}


Arbre cree_A_2(void) {
    Arbre a_2 = alloue_noeud("Anémone");
    a_2->fg = alloue_noeud("Camomille");
    a_2->fd = alloue_noeud("Camomille");
    a_2->fd->fg = alloue_noeud("Dahlia");
    a_2->fd->fg->fd = alloue_noeud("Camomille");
    a_2->fd->fg->fd->fg = alloue_noeud("Iris");
    a_2->fd->fg->fd->fd = alloue_noeud("Jasmin");
    return a_2;

}


Arbre cree_G_2(void) {
    Arbre g_2 = alloue_noeud("Camomille");
    g_2->fg = alloue_noeud("Lilas");
    g_2->fd = alloue_noeud("Rose");
    return g_2;
}


Arbre cree_A_3(void) {
    Arbre a_3 = alloue_noeud("Intel Core i9");
    a_3->fg = alloue_noeud("Apple M3 Max");
    a_3->fg->fd = alloue_noeud("AMD Ryzen 9");
    a_3->fg->fd->fg = alloue_noeud("Intel Core i9");
    a_3->fd = alloue_noeud("Intel Core i9");
    a_3->fd->fg = alloue_noeud("Intel Core i9");
    return a_3;
}


Arbre cree_G_3(void) {
    Arbre g_3 = alloue_noeud("Intel Core i9");
    g_3->fg = alloue_noeud("Intel Core i9");
    g_3->fg->fg = alloue_noeud("Apple M3 Max");
    g_3->fg->fd = alloue_noeud("AMD Ryzen 9");
    return g_3;
}





int construit_arbre(Arbre* a) {
    char *noeud = malloc(100 * sizeof(char));
    printf("entrez une chaîne de caractères : ");
    scanf("%s", noeud);
    while (1) {
        if (noeud == NULL) {
            return 0;
        }
        if (strcmp(noeud, "end") == 0) {
            break;
        }

        else if (*noeud == '0') {
            printf("noeud vide\n");
            noeud++;
        }
        else if (*noeud == ' ') {
            noeud++;
        }

        else if (*noeud == '1') {
            printf("noeud non vide\n");
            noeud++;
            *a = alloue_noeud(noeud);
        } else {
            noeud++;
        }
        construit_arbre(&((*a)->fg));
        construit_arbre(&((*a)->fd));
        
    }
    return 1;

}
    



int main(int argc, char const *argv[])
{
    Arbre a_1;
    construit_arbre(&a_1);
    return 0;
}


