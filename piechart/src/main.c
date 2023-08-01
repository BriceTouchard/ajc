#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "gd.h"
#include "gdfontt.h"
#include "gdfonts.h"
#include "gdfontmb.h"
#include "gdfontl.h"
#include "gdfontg.h"

/**
 * @brief Compte les catégories en comptant les virgules
 * @param string n
 * @return int nbrcat
 */
int compter(char *n){
    int nbrcat=0;
    for (int i = 0; i < strlen(n); i++) {
        if (n[i] == ',') {
            nbrcat++;
        }
    }
    nbrcat+=1; // nombre de virgule +1
    return nbrcat;
}

/**
 * @brief Récupère les string d'un argument et les place dans un int array
 * @param argvstr
 * @param prct
 */
void argStrgToIntArray(char* argvstr,int *prct){
    char * token = strtok(argvstr, ","); // Premier token
    int j=0;
    while( token != NULL ) {
       sscanf(token, "%d", &prct[j]);
       token = strtok(NULL, ",");
       j++;
    }
}

char** argStrgToStrgArray(char* argvstr,int nbrcat){
    char **noms = malloc(sizeof(char*) * nbrcat);
    for(int i = 0; i < nbrcat; i++) {
        noms[i] = malloc(sizeof(char) * 20);
    }
    char * tok2 = strtok(argvstr, ","); // Premier token
    int k=0;
    while( tok2 != NULL ) {
       strcpy(noms[k],tok2);
       tok2 = strtok(NULL, ",");
       k++;
    }
    return noms;
}

int main (int argc, char *argv[])
{
    int nbrcat=compter(argv[1]);
    int prct[nbrcat];
    int rvb[3] = {255,255,255}; // Fond blanc par défaut
    argStrgToIntArray(argv[1],prct);                // récupère les pourcentages et les place dans prct[]
    char **noms =argStrgToStrgArray(argv[2],nbrcat);// récupère les noms de section
    char *titre = argv[3];                          // récupère le nom de fichier
    int persp=0;                                    // Affichage en 2d par défaut

    // Arguments optionnels
    for (int i = 4; i < argc; i++) {
        if(argv[i] != NULL){
            if (strcmp(argv[i],"3d") == 0) {
                persp=1;
            }
            else{
                argStrgToIntArray(argv[i],rvb);
            }
        }
    }
    int trait = 10;         // taille des traits de légende
    int tdist = 70;         // Distance texte-camembert
    int diax = 400;         // diamètre horizontal du camembert
    int diay;               // diamètre vertical du camembert
    if (persp==1)           // Affichage 2d ou 3d
        diay=diax-100;
    else
        diay=diax;
    int imgsize = 550;      // taille image
    int epais = 50;         // épaisseur (perspective 3D)
    int black, jaune, rose, orange, fuschia, vert, bleu, marron, gris, bckgrd; // Noms des couleurs (8)

    gdImagePtr im;
    FILE *pngout;
    im = gdImageCreate(imgsize, imgsize);  //création de l'image

    bckgrd = gdImageColorAllocate(im, rvb[0], rvb[1], rvb[2]); // background
    black =   gdImageColorAllocate(im, 0, 0, 0);

    jaune =   gdImageColorAllocate(im, 245, 222, 179);
    rose =    gdImageColorAllocate(im, 221, 160, 221);
    orange =  gdImageColorAllocate(im, 255,  99,  71);
    fuschia = gdImageColorAllocate(im, 176,  48,  96);
    vert =    gdImageColorAllocate(im, 143, 188, 143);
    bleu =    gdImageColorAllocate(im, 10,   50, 255);
    marron =  gdImageColorAllocate(im, 150, 100,   0);
    gris =    gdImageColorAllocate(im, 128, 128, 128);

    int colors[8] = {jaune, rose, orange, fuschia, vert, bleu, marron, gris};

    gdFontPtr fonts[5];
    fonts[0] = gdFontGetTiny ();
    fonts[1] = gdFontGetSmall ();
    fonts[2] = gdFontGetMediumBold ();
    fonts[3] = gdFontGetLarge ();
    fonts[4] = gdFontGetGiant ();

    // Remplissage
    int angle = -90;                // Départ des portions de 12h, pas 3h (en °)
    int angle2 = prct[0]*3.6/2-90;  // Départ des traits de légende (en °)
    int x1,y1,x2,y2,x3,y3;          // Coordonnées des point finaux des lignes

    // On dessine les arc du dessous si on est en 3D
    if (persp==1) {
        for (int i = 0; i < nbrcat; i++){
            // On trace les traits de légendes
//            x1 = imgsize/2 + (diax/2+trait) * cos(angle2/180.*3.14);
//            y1 = imgsize/2 + epais + (diay/2+trait) * sin(angle2/180.*3.14);
//            gdImageLine(im, imgsize/2, imgsize/2+epais, x1, y1, black);

            // arc du dessous
            gdImageFilledArc(im,imgsize/2,imgsize/2+epais,diax,diay,angle,angle+prct[i]*3.6,colors[i],0);
            angle+=prct[i]*3.6;
            angle2=angle+prct[i+1]*3.6/2;
        }
    }

    // On stocke les coordonnées des points finaux des lignes délimitant les secions
    int x,y;
    int xcoord[nbrcat];
    int ycoord[nbrcat];
    for (int i = 0; i < nbrcat; i++) {
        x = imgsize/2 + diax/2 * cos(angle/180.*3.14);
        y = imgsize/2 + diay/2 * sin(angle/180.*3.14);
        xcoord[i]=x;
        ycoord[i]=y;
        angle+=prct[i]*3.6;
    }

    // On dessine le(s) rectangle(s)
    if (persp==1) {
        angle = -90;
        for(int i = 0; i < nbrcat ;i++){ // rectangles inférieurs
            if (ycoord[i] > imgsize/2 && xcoord[i] > imgsize/2) { //quart inf droit
                gdImageFilledRectangle(im,xcoord[i],ycoord[i],xcoord[i]-epais,ycoord[i]+epais,colors[i]);
            }
            else if (ycoord[i] > imgsize/2 && xcoord[i] < imgsize/2){ //quart inf gauche
                gdImageFilledRectangle(im,xcoord[i],ycoord[i],xcoord[i]+epais,ycoord[i]+epais,colors[i-1]);
            }
            else if(ycoord[i] < imgsize/2 && ycoord[i-1] > imgsize/2){ //cotés
                gdImageFilledRectangle(im,(imgsize-diax)/2,imgsize/2,(imgsize-diax)/2+epais,imgsize/2+epais,colors[i-1]);
            }
            angle+=prct[i]*3.6;
        }
        for(int i = 0; i < nbrcat ;i++){ // rectangles latéraux
            if(ycoord[i]-imgsize/2 > 0 && ycoord[i+1]-imgsize/2 < 0){
                gdImageFilledRectangle(im,(imgsize-diax)/2,imgsize/2,(imgsize-diax)/2+epais,imgsize/2+epais,colors[i]); // côté gauche
            }
            else if(ycoord[i]-imgsize/2 < 0 && ycoord[i+1]-imgsize/2 > 0) {
                gdImageFilledRectangle(im,(imgsize+diax)/2,imgsize/2,(imgsize+diax)/2-epais,imgsize/2+epais,colors[i]); // côté droit
            }
        }
    }

    // On dessine tout le reste (couche du dessus)
    angle2 = prct[0]*3.6/2-90;
    for (int i = 0; i < nbrcat; i++) {
        // Coordonnées traits de légendes
        x1 = imgsize/2 + (diax/2+trait) * cos(angle2/180.*3.14);
        y1 = imgsize/2 + (diay/2+trait) * sin(angle2/180.*3.14);
        // Coordonnées des textes (noms)
        x3 = imgsize/2 + (diax/2+tdist) * cos(angle2/180.*3.14);
        y3 = imgsize/2 + (diay/2+tdist) * sin(angle2/180.*3.14);

        if (persp==1 && y1 < imgsize/2){
//            gdImageLine(im, imgsize/2, imgsize/2, x1, y1, black); // trait de légende
        }
        else if (persp==0){
            gdImageLine(im, imgsize/2, imgsize/2, x1, y1, black);
        }
        gdImageFilledArc(im,imgsize/2,imgsize/2,diax,diay,angle,angle+prct[i]*3.6,colors[i],0);
        gdImageLine(im, imgsize/2, imgsize/2, xcoord[i], ycoord[i], bckgrd); // lignes délimitantes
        gdImageString (im, fonts[4], x3, y3, noms[i], black);
        angle+=prct[i]*3.6;
        angle2=angle+prct[i+1]*3.6/2;
    }
//    gdImageLine(im, imgsize/2, imgsize/2, imgsize/2, imgsize/2-diay/2, bckgrd); //Ligne de départ (12h)

    // Contour
    gdImageEllipse(im,imgsize/2,imgsize/2,diax,diay,bckgrd); //cercle noir

    strcat(titre, ".png");
    pngout = fopen(titre, "wb");
    gdImagePng(im, pngout);
    fclose(pngout);
    gdImageDestroy(im);
}
