//
// Created by Guill on 05/11/2020.
//

#include "header.h"


/**
 * Fonction qui convertie un caractère en entier
 * Utilisée pour les coordonnées de la colonne
 * @param c, le caractère à convertir
 * @return
 */
int convCharToInt(char c)
{
    int i;
    switch(c)
    {
        case 'a':
        {
            i = 0;
            break;
        }
        case 'b':
        {
            i = 1;
            break;
        }
        case 'c':
        {
            i = 2;
            break;
        }
        case 'd':
        {
            i = 3;
            break;
        }
        case 'e':
        {
            i = 4;
            break;
        }
        case 'f':
        {
            i = 5;
            break;
        }
        case 'g':
        {
            i = 6;
            break;
        }
        default:
        {
            i = 7;
        }
    }
    return i;
}

void saisie(tabDamier td)
{
    int x;
    char y;
    printf("Coordonnee ligne du pion a placer ?");
    scanf("%d", &x);
    printf("Coordonnee colonne du pion a placer ?");
    scanf("%c", y);

}

/**
 * Procédure permettant le déplacement d'un pion blanc ou noir
 * @param td, tableau de jeu
 * @param departx, position x (ligne) du pion
 * @param departy, position y (colonne) du pion
 * @param joueur, 0 = IA, 1 = joueur
 */
void deplacerPion(tabDamier td, int departx, int departy, bool joueur)
{
    int arriveex, arriveey, i, j, k;
    char arriveey1, typePiece;
    printf("Coordonne ligne ?");
    scanf("%d", &arriveex);
    printf("Coordonnee colonne ? ");
    scanf(" %c", arriveey1);
    /*
    if (arriveex==9&&arriveey1=='z')
    {
        typePiece=saisie(t,&departx,&departy,joueur);
    }
    */
    arriveey = convCharToInt(arriveey1);
    k=detectionDame(t,departx,departy,arriveex,arriveey,joueur);
    while (k==0){
        printf("coordonnees incorrectes , veuillez en saisir de nouvelles\n");
        printf("Veuillez saisir la colonne et la ligne de l'endroit ou vous souhaitez deplacer votre Dame\n");
        scanf(" %c",&arriveey1);
        scanf("%d",&arriveex);
        if (arriveex==9&&arriveey1=='z'){
            typePiece=saisie(t,&departx,&departy,joueur);
        }
        arriveey=conversion(arriveey1);
        arriveex =conversionChiffre(arriveex);
        k=detectionDame(t,departx,departy,arriveex,arriveey,joueur);
    }
    t[departx][departy].nomPiece='0';  /// a la sortie de la boucle remplace la precedente place du cavalier par ' ' et a la nouvelle place remplace par le cavalier
    t[departx][departy].couleur='0';
    t[arriveex][arriveey].nomPiece='D';
    t[arriveex][arriveey].couleur=joueur;
}

/**
int detectionDame(Piece **t,int departx,int departy,int arriveex,int arriveey,char joueur){
   int i,j,k,echec,*xR,*yR,*xA,*yA;
   Piece**Echiquiertest;
   i=departx;
   j=departy;
   if (arriveey==departy&&arriveex==departx){
       return 0;
   }
   if (arriveex!=departx&&arriveey==departy){
       if (arriveex>departx){
           for (k=1;i+k<arriveex;k++){
               if(t[i+k][j].couleur!='0'){
                   return 0;
               }
           }
           if (t[arriveex][arriveey].couleur!=joueur){
               Echiquiertest=copierJeu(t);
               Echiquiertest[arriveex][arriveey].nomPiece='D';
               Echiquiertest[arriveex][arriveey].couleur=joueur;
               Echiquiertest[departx][departy].nomPiece='0';
               Echiquiertest[departx][departy].couleur='0';
               echec=detectionEchec(Echiquiertest,joueur,&xR,&yR,&xA,&yA);
               if (echec==0){
                   return 1;
               }else{
                   return 0;
               }
           }
           else {
               return 0;
           }
       }
       if (arriveex<departx){
           for (k=1;i-k>arriveex;k++){
               if(t[i-k][j].couleur!='0'){
                   return 0;
               }
           }
           if (t[arriveex][arriveey].couleur!=joueur){
               Echiquiertest=copierJeu(t);
               Echiquiertest[arriveex][arriveey].nomPiece='D';
               Echiquiertest[arriveex][arriveey].couleur=joueur;
               Echiquiertest[departx][departy].nomPiece='0';
               Echiquiertest[departx][departy].couleur='0';
               echec=detectionEchec(Echiquiertest,joueur,&xR,&yR,&xA,&yA);
               if (echec==0){
                   return 1;
               }else{
                   return 0;
               }
           }
           else {
               return 0;
           }
       }
   }
   if (arriveex==departx&&arriveey!=departy){
       if (arriveey>departy){
           for(k=1;k+i<arriveey;k++){
               if (t[i][j+k].couleur!='0'){
                   return 0;
               }
           }
           if (t[arriveex][arriveey].couleur!=joueur){
               Echiquiertest=copierJeu(t);
               Echiquiertest[arriveex][arriveey].nomPiece='D';
               Echiquiertest[arriveex][arriveey].couleur=joueur;
               Echiquiertest[departx][departy].nomPiece='0';
               Echiquiertest[departx][departy].couleur='0';
               echec=detectionEchec(Echiquiertest,joueur,&xR,&yR,&xA,&yA);
               if (echec==0){
                   return 1;
               }else{
                   return 0;
               }
           }
           else{
               return 0;
           }
       }
       if (arriveey<departy){
           for(k=1;k-i>arriveey;k++){
               if(t[i][j-k].couleur!='0'){
                   return 0;
               }
           }
           if(t[arriveex][arriveey].couleur!=joueur){
               Echiquiertest=copierJeu(t);
               Echiquiertest[arriveex][arriveey].nomPiece='D';
               Echiquiertest[arriveex][arriveey].couleur=joueur;
               Echiquiertest[departx][departy].nomPiece='0';
               Echiquiertest[departx][departy].couleur='0';
               echec=detectionEchec(Echiquiertest,joueur,&xR,&yR,&xA,&yA);
               if (echec==0){
                   return 1;
               }else{
                   return 0;
               }
           }
           else{
               return 0;
           }
       }
   }
   if((arriveex<0)||(arriveex>7)||(arriveey<0)||(arriveey>7)){
       return 0;}

   if (arriveex>departx&&arriveey>departy){
       for (k=1;i+k<arriveex;k++){
           if(t[i+k][j+k].couleur!='0'){
               return 0;
           }
       }
       if (t[arriveex][arriveey].couleur!=joueur){
           Echiquiertest=copierJeu(t);
           Echiquiertest[arriveex][arriveey].nomPiece='D';
           Echiquiertest[arriveex][arriveey].couleur=joueur;
           Echiquiertest[departx][departy].nomPiece='0';
           Echiquiertest[departx][departy].couleur='0';
           echec=detectionEchec(Echiquiertest,joueur,&xR,&yR,&xA,&yA);
           if (echec==0){
               return 1;
           }else{
               return 0;
           }
       }
       else {
           return 0;
       }
   }
   if (arriveex>departx&&arriveey<departy){
       for (k=1;i+k<arriveex;k++){
           if(t[i+k][j-k].couleur!='0'){
               return 0;
           }
       }
       if (t[arriveex][arriveey].couleur!=joueur){
           Echiquiertest=copierJeu(t);
           Echiquiertest[arriveex][arriveey].nomPiece='D';
           Echiquiertest[arriveex][arriveey].couleur=joueur;
           Echiquiertest[departx][departy].nomPiece='0';
           Echiquiertest[departx][departy].couleur='0';
           echec=detectionEchec(Echiquiertest,joueur,&xR,&yR,&xA,&yA);
           if (echec==0){
               return 1;
           }else{
               return 0;
           }
       }
       else {
           return 0;
       }
   }
   if (arriveex<departx&&arriveey<departy){
       for (k=1;i-k>arriveex;k++){
           if(t[i-k][j-k].couleur!='0'){
               return 0;
           }
       }
       if (t[arriveex][arriveey].couleur!=joueur){
           Echiquiertest=copierJeu(t);
           Echiquiertest[arriveex][arriveey].nomPiece='D';
           Echiquiertest[arriveex][arriveey].couleur=joueur;
           Echiquiertest[departx][departy].nomPiece='0';
           Echiquiertest[departx][departy].couleur='0';
           echec=detectionEchec(Echiquiertest,joueur,&xR,&yR,&xA,&yA);
           if (echec==0){
               return 1;
           }else{
               return 0;
           }
       }
       else {
           return 0;
       }
   }
   if (arriveex<departx&&arriveey>departy){
       for (k=1;i-k>arriveex;k++){
           if(t[i-k][j+k].couleur!='0'){
               return 0;
           }
       }
       if (t[arriveex][arriveey].couleur!=joueur){
           Echiquiertest=copierJeu(t);
           Echiquiertest[arriveex][arriveey].nomPiece='D';
           Echiquiertest[arriveex][arriveey].couleur=joueur;
           Echiquiertest[departx][departy].nomPiece='0';
           Echiquiertest[departx][departy].couleur='0';
           echec=detectionEchec(Echiquiertest,joueur,&xR,&yR,&xA,&yA);
           if (echec==0){
               return 1;
           }else{
               return 0;
           }
       }
       else {
           return 0;
       }
   }
}

**/