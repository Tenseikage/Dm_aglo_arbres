#include "saage.h"
#include "arbres_binaires.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void affiche_indente(Arbre a, int niveau, FILE *f) {
    if (a != NULL) {
        for (int i = 0; i < niveau; i++) {
            fprintf(f, "   ");
        }
       

        fprintf(f, "Valeur: %s\n", a->val); 
        for (int i = 0; i < niveau; i++) {
            fprintf(f, "   ");
        }

        if (a->fg != NULL) {
            fprintf(f, "Gauche: \n");
            affiche_indente(a->fg, niveau + 1, f);
        }
        else {
            fprintf(f, "Gauche: NULL\n");
        }
        
        for(int i = 0; i < niveau; i++) {
            fprintf(f, "   ");
        }

        if (a->fd != NULL) {
            fprintf(f, "Droite:\n");
            affiche_indente(a->fd, niveau + 1 , f);
        }
        else {
            fprintf(f, "Droite: NULL\n");
        }
        
        

        
    }
}




int serialise(char *nom_de_fichier,Arbre A){
  FILE *f;
  f=fopen(nom_de_fichier,"w");
  char commande[256];

  if(f==NULL){
    printf("Erreur lors de l'ouverture du fichier\n");
    snprintf(commande, 256, "rm %s", nom_de_fichier);
    system(commande);
    return 0;
  }

  int niveau=0;
  affiche_indente(A,niveau,f);


  fclose(f);
  return 1;
  
}

