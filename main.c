#include "arbres_binaires.h"
#include "greffe.h"
#include "saage.h"
#include <stdio.h>

int main(void) {
    Arbre a_1 = cree_A_3();
    Arbre g_1 = cree_G_3();
    printf("\n");
    printf("\nRéussite expansion: %d\n\n", expansion(&a_1, g_1));
    serialise("test.saage", g_1);
    Arbre a_2 = NULL;
    //deserialise("test.saage", &a_2);
    serialise("test2.saage", a_2);

    
    
    return 0;
}