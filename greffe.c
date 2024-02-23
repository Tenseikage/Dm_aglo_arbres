#include "greffe.h"
#include "arbres_binaires.h"
#include <stdio.h>
#include <string.h>


static int copie_rec(Arbre* dest, Arbre source) {
    if (source == NULL) {
        return 1;
    }
    Noeud* cp_noeud = alloue_noeud(source->val);
    if (cp_noeud == NULL) {
        return 0;
    }
    *dest = cp_noeud;
    return (copie(&(*dest)->fg, source->fg) + copie(&(*dest)->fd, source->fd)) / 2;
}


static int copie_greffon_rec(Arbre* dest, Arbre source, Arbre A) {
    int valeur_cp_fg = 1;
    int valeur_cp_fd = 1;
    if (source == NULL) {
        return 1;
    }
    Noeud* cp_noeud = alloue_noeud(source->val);
    if (cp_noeud == NULL) {
        return 0;
    }
    *dest = cp_noeud;
    if (source->fg == NULL && A->fg != NULL) {
        valeur_cp_fg = copie(&(*dest)->fg, A->fg);
    }
    if (source->fd == NULL && A->fd != NULL) {
        valeur_cp_fd = copie(&(*dest)->fd, A->fd);
    }
    // Verifie que la copie s'est bien deroulee
    if (valeur_cp_fg == 0 || valeur_cp_fd == 0) {
        return 0;
    }
    int valeur_fg = copie_greffon_rec(&(*dest)->fg, source->fg, A);
    int valeur_fd = copie_greffon_rec(&(*dest)->fd, source->fd, A);
    return (valeur_fg + valeur_fd) / 2;
}

// Duplique `source` dans `dest` en completant les feuilles avec les sous-arbres de `A`
static int copie_greffon(Arbre* dest, Arbre source, Arbre A) {
    if (copie_greffon_rec(dest, source, A) == 0) {
        liberer(dest);
        return 0;
    }
    return 1;
}


int copie(Arbre* dest, Arbre source) {
    if (copie_rec(dest, source) == 0) {
        liberer(dest);
        return 0;
    }
    return 1;
}


int expansion(Arbre* A, Arbre B) {
    if (*A == NULL) {
        return 1;
    }
    int valeur_fg = expansion(&(*A)->fg, B);
    int valeur_fd = expansion(&(*A)->fd, B);
    if (strcmp((*A)->val, B->val) == 0) {
        Arbre new_greffon;
        if (copie_greffon(&new_greffon, B, *A) == 0) {
            return 0;
        }
        liberer(A);
        *A = new_greffon;
    }
    return (valeur_fg + valeur_fd) / 2;
}