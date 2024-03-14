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

    // deserialisation 
    if (strcmp(argv[1],"-G") == 0) {
        Arbre source = NULL;
        Arbre greffon = NULL;

        int result_source = deserialise(argv[2], &source);
        int result_greffon = 0;
    
        if (result_source != 1) {
            fprintf(stderr, "Erreur: Probleme deserialise %s\n", argv[2]);
        } else {
            result_greffon = deserialise(argv[3], &greffon);

            if (result_greffon != 1) {
                fprintf(stderr, "Erreur: Probleme deserialise %s\n", argv[3]);
            }
        }

        if (result_source == 1 && result_greffon == 1) {
            if (!expansion(&source, greffon)) {
                fprintf(stderr, "Erreur: Probleme Expansion\n");
            } else {
                affiche_indente(source, 0, stdout);
            }
        }

        if (source != NULL) {
            liberer(&source);
        }

        if (greffon != NULL) {
            liberer(&greffon);
        }

    } 

    return 0;

}