#include "arbres_binaires.h"
#include "greffe.h"
#include "saage.h"
#include <stdio.h>

int main(void) {
    Arbre a_1 = cree_A_3();
    Arbre g_1 = cree_G_3();
    affiche_indente(a_1, 0);
    printf("\n");
    affiche_indente(g_1, 0);
    printf("\nRéussite expansion: %d\n\n", expansion(&a_1, g_1));
    affiche_indente(a_1, 0);

    
    
    return 0;
}