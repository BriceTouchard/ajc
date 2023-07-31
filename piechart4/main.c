#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gd.h"
#include "gdfontt.h"
#include "gdfonts.h"
#include "gdfontmb.h"
#include "gdfontl.h"
#include "gdfontg.h"

int main ()
{
    gdImagePtr im;
    FILE *pngout;

    // On met en dur les args pour l'instant (en pourcents)
    int prct[5] = {65, 20, 5, 5, 5};
    char *noms[20] = {"USA","UK","Canada","Other","Australia"};
    char titre[30] = "piechart";

    // Dimensions, couleurs, mise en forme
    int trait = 10;         // taille des traits de légende
    int tdist = 50;         // Distance texte-camembert
    int dia = 400;          // diamètre du camembert
    int imgsize = 550;      // taille image
    int black, white, jaune, rose, orange, fuschia, vert; // Noms des couleurs

    im = gdImageCreate(imgsize, imgsize);  //création de l'image

    white =   gdImageColorAllocate(im, 255, 255, 255); // background
    black =   gdImageColorAllocate(im, 0, 0, 0);
    jaune =   gdImageColorAllocate(im,245, 222, 179);
    rose =    gdImageColorAllocate(im,221, 160, 221);
    orange =  gdImageColorAllocate(im,255, 99, 71);
    fuschia = gdImageColorAllocate(im,176, 48, 96);
    vert =    gdImageColorAllocate(im,143, 188, 143);

    int colors[5] = {jaune, rose, orange, fuschia, vert};

    gdFontPtr fonts[5];
    fonts[0] = gdFontGetTiny ();
    fonts[1] = gdFontGetSmall ();
    fonts[2] = gdFontGetMediumBold ();
    fonts[3] = gdFontGetLarge ();
    fonts[4] = gdFontGetGiant ();

    // Remplissage
    int angle = -90;                // Départ des portions de 12h, pas 3h (en °)
    int angle2 = prct[0]*3.6/2-90;  // Départ des traits de légende (en °)
    int x1,y1,x2,y2,x3,y3;          // Coordonnées des point finaux des lignes et du texte

    /* ce sont des coordonnées absolues, le point de départ est au centre,
     * le point final est le centre auquel on ajoute le cosinus en abcisse
     * et le sinus en ordonnée (on projette).*/

    for (int i = 0; i < 5; i++) {
        // Coordonnées traits de légendes
        x1 = imgsize/2 + (dia/2+trait) * cos(angle2/180.*3.14);
        y1 = imgsize/2 + (dia/2+trait) * sin(angle2/180.*3.14);
        // Coordonnées des lignes séparatrices
        x2 = imgsize/2 + dia/2 * cos(angle/180.*3.14);
        y2 = imgsize/2 + dia/2 * sin(angle/180.*3.14);
        // Coordonnées des textes (noms)
        x3 = imgsize/2 + (dia/2+tdist) * cos(angle2/180.*3.14);
        y3 = imgsize/2 + (dia/2+tdist) * sin(angle2/180.*3.14);

        gdImageLine(im, imgsize/2, imgsize/2, x1, y1, black);
        gdImageFilledArc(im,imgsize/2,imgsize/2,dia,dia,angle,angle+prct[i]*3.6,colors[i],0);
        gdImageLine(im, imgsize/2, imgsize/2, x2, y2, black);
        gdImageString (im, fonts[4], x3, y3, noms[i], black);
        angle+=prct[i]*3.6;
        angle2=angle+prct[i+1]*3.6/2;
    }
    gdImageLine(im, imgsize/2, imgsize/2, imgsize/2, imgsize/2-(dia/2+trait), black); //Ligne de départ (12h)

    // Contour
    gdImageEllipse(im,imgsize/2,imgsize/2,dia,dia,black);  //cercle noir

    strcat(titre, ".png");
    pngout = fopen(titre, "wb");
    gdImagePng(im, pngout);
    fclose(pngout);
    gdImageDestroy(im);
}
