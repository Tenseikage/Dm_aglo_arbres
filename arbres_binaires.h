#ifndef __ARBRES_BINAIRES_H__
#define __ARBRES_BINAIRES_H__
#define LENGTH_VALUE 64

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

// Permet de remplacer le premier `\n` en `\0`
void decal_val_nul(char* string);

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

/* Cette fonction permet de créer un arbre binaire à la volée. Cette fonction renvoie 1 si cela se passe 
bien et 0 sinon avec libération de l'arbre crée*/
int construit_arbre(Arbre *a);



#endif