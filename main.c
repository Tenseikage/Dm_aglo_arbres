#include "arbres_binaires.h"
#include "greffe.h"
#include "saage.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    Arbre a_1 = cree_A_1();
    Arbre g_1 = cree_G_3();
    printf("\n");
    printf("\nRéussite expansion: %d\n\n", expansion(&a_1, g_1));
    

    // Test: make arbre_greffe et ./saage -E test1.saage
    if (strcmp(argv[1],"-E") == 0) {
        serialise(argv[2], a_1);
    }
    liberer(&a_1);
    liberer(&g_1);
    // deserialisation 
    if (strcmp(argv[1],"-G") == 0) {
        // Deserialisation des deux arbres
        // Ajout de l'arbre g_1(argv[3]) dans a_1(argv[2])
        deserialise(argv[2]);
        
    }




    
    
    return 0;
}