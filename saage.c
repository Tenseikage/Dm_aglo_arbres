#include "saage.h"
#include "arbres_binaires.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int affiche_indente(Arbre a, int niveau, FILE *f) {
    
    
    if (a != NULL) {
        for (int i = 0; i < niveau; i++) {
            if (fprintf(f, "    ") < 0) {
                return 0;
            }

        }
       

        fprintf(f, "Valeur : %s\n", a->val); 
        for (int i = 0; i < niveau; i++) {
            if (fprintf(f, "    ") < 0) {
                return 0;
            }

        }

        if (a->fg != NULL) {
            if (fprintf(f, "Gauche : \n") < 0) {
                return 0;
            }

            affiche_indente(a->fg, niveau + 1, f);
        }
        else {
            if (fprintf(f, "Gauche : NULL\n") < 0) {
                return 0;
            }
        }
        
        for(int i = 0; i < niveau; i++) {
            if (fprintf(f, "    ") < 0) {
                return 0;
            }
        }

        if (a->fd != NULL) {
            if (fprintf(f, "Droite : \n") < 0) {
                return 0;
            }
            affiche_indente(a->fd, niveau + 1 , f);
        }
        else {
            if (fprintf(f, "Droite : NULL\n") < 0) {
                return 0;
            }
        }
        
    
    }

    return 1;
}


int serialise(char *nom_de_fichier,Arbre A){

  
  FILE *f;
  f=fopen(nom_de_fichier,"w");
  char commande[256];

  if (f==NULL){
    fprintf(stderr,"Erreur lors de l'ouverture du fichier");
    snprintf(commande, 256, "rm %s", nom_de_fichier);
    system(commande);
    return 0;
  } 

  if (affiche_indente(A,0,f) == 0) {
    fprintf(stderr, "Erreur lors de la création du fichier");
    snprintf(commande, 256, "rm %s", nom_de_fichier);
    system(commande);
    return 0;

  }

  fclose(f);
  return 1;
  
}


static int deserialise_aux(FILE *f, Arbre *A, int iteration) {
    
    char line[LENGTH_VALUE];
    if (fgets(line, LENGTH_VALUE, f) != NULL) {
        // Cas ou fichier.saage non vide
        fprintf(stdout, "Oui");
        decal_val_nul(line);
        *A = alloue_noeud(&line[9 + iteration]);
        if (*A == NULL) {
            return 0;
        }

        fgets(line, LENGTH_VALUE, f);
        if (line[10 + iteration] == '\0') {
            if (deserialise_aux(f, &(*A)->fg, iteration + 4) == 0) {
                return 0;
            }
        }

        fgets(line, LENGTH_VALUE, f);
        if (line[10 + iteration] == '\0') {
            if (deserialise_aux(f, &(*A)->fd, iteration + 4) == 0) {
                return 0;
            }
        }
        return 1;
    }
    return 1;
}

int deserialise(FILE *f, Arbre *A) {
   
   
    int state = deserialise_aux(f, A, 0);
    return state;
}