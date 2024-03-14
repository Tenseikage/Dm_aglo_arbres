#include "arbres_binaires.h"
#include "greffe.h"
#include "saage.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {


    if (argc < 2) {
        fprintf(stderr, "Erreur: pas assez d'arguments\n");
        return 1;

    } else if (argc > 4) {
        fprintf(stderr, "Erreur: trop d'arguments\n");
        return 1;
    }

    
    // serialisation
    if (strcmp(argv[1],"-E") == 0) {
        if (strstr(argv[2], ".saage") == NULL) {
            fprintf(stderr, "Erreur: Le fichier de sortie doit être un fichier .saage\n");
            return 0;
        }
        Arbre new = NULL;
        printf("Entrez le noeud de l'arbre. Entrez 0 pour un fils vide et 1 pour un noeud.\n");
        printf("\n");
        if (construit_arbre(&new) == 0) {
            liberer(&new);
            fprintf(stderr, "Erreur: Probleme Allocation\n");
            return 0;
        }
        if (new != NULL) {
            serialise(argv[2], new);
            liberer(&new);
        }
    }

    if (strcmp(argv[1], "-Y") == 0) {
        FILE *f;
        f = fopen(argv[2], "r");
        Arbre a;
        deserialise(f, &a, 0);
        affiche_indente(a, 0, stdout);
        liberer(&a);
        fclose(f);
    }

    // deserialisation 
    if (strcmp(argv[1],"-G") == 0) {
        FILE *f, *g;
        f = fopen(argv[2], "r");
        g = fopen(argv[3], "r");
        Arbre source = NULL;
        Arbre greffon = NULL;
        int result_source = deserialise(f, &source, 0);
        if (result_source != 1) {
            switch (result_source) {
                case -1: {
                    fprintf(stderr, "Erreur: Fichier %s vide\n", argv[2]);
                    break;
                }
                case 0: {
                    fprintf(stderr, "Erreur: Probleme Allocation %s\n", argv[2]);
                    break;
                }
            }
            if (source != NULL) {
                liberer(&source);
            }
            fclose(f);
            fclose(g);
            return 0;
        }
        
        int result_greffon = deserialise(g, &greffon, 0);
        if (result_greffon != 1) {
            switch (result_greffon) {
                case -1: {
                    fprintf(stderr, "Erreur: Fichier %s vide\n", argv[3]);
                    break;
                }
                case 0: {
                    fprintf(stderr, "Erreur: Probleme Allocation %s\n", argv[3]);
                    break;
                }
            }
            if (source != NULL) {
                liberer(&source);
            }
            if (greffon != NULL) {
                liberer(&greffon);
            }
            fclose(f);
            fclose(g);
            return 0;
        }

        if (expansion(&source, greffon) == 0) {
            fprintf(stderr, "Erreur: Probleme Allocation Expansion\n");
        } else {
            affiche_indente(source, 0, stdout);
        }

        

        liberer(&source);
        liberer(&greffon);


        fclose(f);
        fclose(g);

    } 

    
    return 0;

}