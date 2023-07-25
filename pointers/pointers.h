#ifndef POINTERS_H
#define POINTERS_H

#endif // POINTERS_H


char* invTab1(char* s){
    /* première tentative qui ne marche pas sous forme de fonction,
     * probablement à cause de problèmes de syntaxes */
    char sinv[strlen(s)];
    for (int i = 0; i < strlen(s); i++) {
        sinv[strlen(s)-i] = s[i];
    }
    return sinv;
}


void invPointer(char* str)
{
    /* debut et fin désigne les adresses mémoires (similaire aux index d'un tableau),
     * tandis que *debut et *fin désigne la valeur qui est pointée (un char ici)
    */
    char *debut, *fin, tmp;
    int l = strlen(str);
    debut = str;
    fin = str + l - 1;

    for (int i = 0; i < (l-1)/2; i++) {
        tmp = *fin;
        *fin = *debut;
        *debut = tmp;

        debut++;
        fin--;
    }
}

void invTab(char *str)
{
    int i, tmp, l;
    l = strlen(str);

    for (i = 0; i < l/2; i++) {
        tmp = str[l - i - 1];
        str[l - i - 1] = str[i];
        str[i] = tmp;
    }
}

void dateJma (char *date, int *jour, int *mois, int *annee)
{
    /* On met un char dans un int on a donc un code ASCII
     * Il suffit de décaler de 48 pour obtenir le chiffre correspondat
     * (voir table ASCII)
    */
    *jour = (*date-48)*10 + *(date+1) - 48;
    *mois = (*(date+3)-48)*10 + *(date+4)-48;
    *annee = (*(date+6)-48)*1000 + (*(date+7)-48)*100 + (*(date+8)-48)*10 + *(date+9)-48;
}
