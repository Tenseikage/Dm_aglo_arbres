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
        Arbre new;
        if (construit_arbre(&new) == 0) {
            liberer(&new);
            fprintf(stderr, "Erreur: Probleme Allocation\n");
            return 0;
        }
        serialise(argv[2], new);
        liberer(&new);
    }
    // deserialisation 
    if (strcmp(argv[1],"-G") == 0) {
        FILE *f, *g;
        f = fopen(argv[2], "r");
        g = fopen(argv[3], "r");
        Arbre source, greffon;
        int result_source = deserialise(f, &source, 0);
        if (result_source != 1) {
            switch (result_source) {
                case -1: {
                    fprintf(stderr, "Erreur: Fichier %s vide", argv[2]);
                    break;
                }
                case 0: {
                    fprintf(stderr, "Erreur: Probleme Allocation %s", argv[2]);
                    break;
                }
                liberer(&source);
                fclose(f);
                fclose(g);
                return 0;
            }
        }
        
        int result_greffon = deserialise(g, &greffon, 0);
        if (result_greffon != 1) {
            switch (result_greffon) {
                case -1: {
                    fprintf(stderr, "Erreur: Fichier %s vide", argv[3]);
                    break;
                }
                case 0: {
                    fprintf(stderr, "Erreur: Probleme Allocation %s", argv[3]);
                    break;
                }
                liberer(&source);
                liberer(&greffon);
                fclose(f);
                fclose(g);
                return 0;
            }
        }

        if (expansion(&source, greffon) == 0) {
            fprintf(stderr, "Erreur: Probleme Allocation Expansion");
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