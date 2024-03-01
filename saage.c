#include "saage.h"
#include "arbres_binaires.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void affiche_indente(Arbre a, int niveau, FILE *f) {
    if (a != NULL) {
        for (int i = 0; i < niveau; i++) {
            fprintf(f, "    ");
        }
       

        fprintf(f, "Valeur : %s\n", a->val); 
        for (int i = 0; i < niveau; i++) {
            fprintf(f, "    ");
        }

        if (a->fg != NULL) {
            fprintf(f, "Gauche : \n");
            affiche_indente(a->fg, niveau + 1, f);
        }
        else {
            fprintf(f, "Gauche : NULL\n");
        }
        
        for(int i = 0; i < niveau; i++) {
            fprintf(f, "    ");
        }

        if (a->fd != NULL) {
            fprintf(f, "Droite :\n");
            affiche_indente(a->fd, niveau + 1 , f);
        }
        else {
            fprintf(f, "Droite : NULL\n");
        }
        
        

        
    }
}


static void decal_val_nul(char* string) {
    int len = 0;
    while (string[len] != '\n') {
        len++;
    }
    string[len] = '\0';
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


void deserialise(FILE *f, Arbre *A, int iteration) {
    char line[LENGTH_VALUE];
    if (fgets(line, LENGTH_VALUE, f) != NULL) {
        // Cas ou fichier.saage non vide

        decal_val_nul(line);
        *A = alloue_noeud(&line[9 + iteration]);

        fgets(line, LENGTH_VALUE, f);
        if (line[10 + iteration] == '\0') {
            deserialise(f, &(*A)->fg, iteration + 4);
        }

        fgets(line, LENGTH_VALUE, f);
        if (line[10 + iteration] == '\0') {
            deserialise(f, &(*A)->fd, iteration + 4);
        }
    }
}
