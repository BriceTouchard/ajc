#include <stdio.h>

int glob1 = 5; // globale
int glob2 = 6; // globale
static int statVarGlob = 0; //statique
int tabGlob[20]; //tab global

int main()
{
    /*Écrire un programme qui indique l’adresse mémoire :
     * d’une variable locale
     * d’une variable globale
     * d’une variable statique
     * d’un tableau local
     * d’un tableau global
     * d’une constante
     * d’une procédure
     * Que remarque-t-on?
    */

    int loc1 =0;
    int loc2 =0;
    static int statVarLoc = 0;
    int tabLoc1[20];
    int tabLoc2[20];
    const int cst = 0;

    printf("variable locale =   %p %p\n",&loc1,&loc2);
    printf("variable globale =  %p %p\n",&glob1, &glob2);
    printf("variable statique = %p\n",&statVarLoc);
    printf("variable statique = %p\n",&statVarGlob);
    printf("tableau local =     %p %p\n",&tabLoc1,&tabLoc2);
    printf("tableau global =    %p\n",&tabGlob);
    printf("constante =         %p\n",&cst);
    printf("procédure =         %p\n",&printf);

    return 0;
}
