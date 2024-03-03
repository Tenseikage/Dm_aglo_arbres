#ifndef __ARBRES_BINAIRES_H__
#define __ARBRES_BINAIRES_H__

typedef struct noeud {
    char *val;
    struct noeud *fg;
    struct noeud *fd;
} Noeud, *Arbre;    


/* Prototypes des fonctions*/

// Création d'un nouveau noeud
Noeud* alloue_noeud(char *s);

// libération de la mémoire utilisée par un arbre
void liberer(Arbre *a);

// Création de l'arbre A_1
Arbre cree_A_1(void);

// Création de l'arbre G_1
Arbre cree_G_1(void);

// Création de l'arbre A_2
Arbre cree_A_2(void);

// Création de l'arbre G_2
Arbre cree_G_2(void);

// Création de l'arbre A_3
Arbre cree_A_3(void);

// Création de l'arbre G_3
Arbre cree_G_3(void);

// Construction de l'arbre 
int construit_arbre(Arbre *a);



#endif