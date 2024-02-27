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




/*
int construit_arbre(Arbre *a) {
    int taille;
    int cpt;
    printf("Entrez la taille de l'arbre: ");
    scanf("%d", &taille);

    if (taille < 0) {
            perror("Erreur: taille négative\n");
            return 0;
    }

    if (taille == 0) {
        *a = NULL;
        return 1;
    }

    char *mot = (char*)malloc(100 * sizeof(char));
    if (mot == NULL) {
        perror("Erreur d'allocation de mémoire\n");
        return 0;
    }

    printf("Entrez la valeur de la racine: ");
    scanf("%s", mot);
    *a = alloue_noeud(mot);
    if (*a == NULL) {
        perror("Erreur d'allocation de mémoire\n");
        return 0;
    }

    Arbre *courant = a;
    return 1;
    
}
*/



