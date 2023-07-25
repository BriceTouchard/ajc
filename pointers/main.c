#include "pointers.h"
#include <stdio.h>
#include <string.h>

//#include <limits.h>
//#include <float.h>
//#include <stdbool.h>
//#include <ctype.h>


int main()
{

    {
    /* Pointers (page 16) */
    printf("\n------ 1) Initiation aux pointers ------ \n");
    char *p1="ceci est une chaine" ;

    printf ("p1 = %s\n",p1);     // Affiche la string
    printf ("%p\n",p1);          // Affiche l'adresse de *p
    printf ("p+1 = %s\n",p1+1);
    char *q1=p1;
    printf ("q = %s\n",q1);

    while (*q1!=0) { printf ("%s\n", q1) ; q1=q1+1;}
    while (*q1) printf ("%s\n", q1++) ;

    /*
    on déclare un tableau on le remplit par 1 2 4 8 16
    tableau d'entier
    on déclare un pointeur sur un entier
    initialise le pointeur sur le premier élément du tableau
    */
    printf("\n------ 2) Exercice en vrac ------ \n");
    int t[5] = {1,2,4,8,16};
    int *p=&t[0];
    int *q=t;
//    int *r=q;
    printf("%d %d %d %d %d\n",t[0],*p,*(p+1),t[1],*(p+2));


    /*
     * initialiser un tableau avec char tableau[]="Bonjour"
     * puis passer le B en minuscule
    */
    printf("\n------ 3) Passer la 1ère lettre en minuscule ------ \n");
    char tableau[]="bonjour";
    tableau[0]='B';
    printf("%s\n",tableau);

    char *p2 = &tableau[0];
    *p2 = 'B';
    printf("%s\n",p2);
    }

    {
    /*  Écrire deux fonctions qui renvoient l’inverse d’une chaîne de caractères,
     *  l’une en utilisant les tableaux, l’autre en utilisant les pointeurs.
     *  Exemple : maman => namam
    */
    printf("\n------ 4) Fonctions inverses : palindrome ------\n");
    char str1[100] = "abcdefg";
    char str2[100] = "ornithorynque";

    //Inversion avec Pointers
    invPointer(str1);
    printf("%s\n", str1);

    //Inversion avec Tableau
    invTab(str2);
    printf ("%s\n", str2);

    char str[100] = "abcdefg";

    //On print tout pour bien comprendre
//    char *debut, *fin, tmp;
//    int l = strlen(str);
//    debut = str;
//    fin = str + l - 1;

//    for (int i = 0; i < (l-1)/2; i++) {
//        printf("i = %d\n",i);
//        tmp = *fin;
//        *fin = *debut;
//        printf("fin = %c\n",*fin);
//        *debut = tmp;
//        printf("debut = %c\n-----------\n",*debut);

//        debut++;
//        printf("debut++ = %s\n",debut);
//        fin--;
//        printf("fin-- = %s\n-----------\n",fin);
//        printf ("%s\n", str);
//    }

    // On utlise le mode Debug
//    char *p= "boujour les amis !";
//    char *q= p;
////    char a = *q;
//    q+=19;
//    *q='?';
//    printf("%s\n",q);


}

    /* Écrire une fonction qui prend en premier argument une date sous la forme
     * “23/03/2014” et qui renvoie trois arguments entiers qui sont le jour, le mois et
     * l’année
     */
    printf("\n------ 5) Date en char. Sortie: 3 arg entiers, jour, mois, année  ------\n");
    char date[10] = "23/03/2014";
    int jour,mois,annee;

    dateJma(date,&jour,&mois,&annee);
    printf("Jour = %d\n",jour);
    printf("Moi = %d\n",mois);
    printf("Anne = %d\n",annee);

    return 0;
}
