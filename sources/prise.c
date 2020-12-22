//
// Created by Guill on 22/12/2020.
//

#include "../header.h"


void changerCouleur(tabDamier td, int x, int y, int tour ){
   char couleur;
    int prise=0; //si il peut prendre ou non
    int i=1;

    if(tour%2==0){
        couleur = 'n';
    }
    else{
        couleur = 'b';
    }

    td[x][y].couleur=couleur; //on pose le pion

    //droite
    while (td[x+i][y].couleur!=couleur && x+i+1<8){
        i++;
    }
    if (x+i<8 && i!=1){
        if (td[x+i][y].couleur==couleur){
            prise=1;
        }
    }
    if(prise == 1){
        i=1;
        while (td[x+i][y].couleur!=couleur){
            td[x+i][y].couleur= couleur;
            i++;
        }
    }
   prise = 0;

    //gauche
    i=1;
    while (td[x-i][y].couleur!=couleur && x-i-1>=0){
        i++;
    }
    if (x-i>=0 && i!=1){
        if (td[x-i][y].couleur==couleur){
           prise=1;
        }
    }
    if(prise == 1){
        i=1;
        while (td[x-i][y].couleur!=couleur){
           td[x-i][y].couleur = couleur;
            i++;
        }
    }
   prise = 0;

    // haut
    i=1;
    while (td[x][y-i].couleur!=couleur && y-i-1>=0){
        i++;
    }
    if (y-i>=0 && i!=1){
        if (td[x][y-i].couleur==couleur){
            prise = 1;
        }
    }
    if(prise == 1){
        i=1;
        while (td[x][y-i].couleur!=couleur){
            td[x][y-i].couleur = couleur;
            i++;
        }
    }
   prise = 0;

    // bas
    i=1;
    while (td[x][y+i].couleur!=couleur && y+i+1<8){
        i++;
    }
    if (y+i<8 && i!=1){
        if (td[x][y+i].couleur==couleur){
            prise=1;
        }
    }
    if(prise=1){
        i=1;
        while (td[x][y+i].couleur!=couleur){
            td[x][y+i].couleur = couleur;
            i++;
        }
    }
    prise = 0;

    //diago droite/bas
    i=1;
    while (td[x+i][y+i].couleur!=couleur && y+i+1<8 && x+i+1<8){
        i++;
    }
    if (y+i<8 && x+i<8 && i!=1){
        if (td[x+i][y+i].couleur==couleur){
           prise = 1;
        }
    }
    if(prise = 1){
        i=1;
        while (td[x+i][y+i].couleur!=couleur){
            td[x+i][y+i].couleur = couleur;
            i++;
        }
    }
    prise=0;

    //diago gauche/bas
    i=1;
    while (td[x-i][y+i].couleur!=couleur && y+i+1<8 && x-i-1>=0){
        i++;
    }
    if (y+i<8 && x-i>=0 && i!=1){
        if (td[x-i][y+i].couleur==couleur){
           prise =1;
        }
    }
    if(prise=1){
        i=1;
        while (td[x-i][y+i].couleur!=couleur){
            td[x-i][y+i].couleur = couleur;
            i++;
        }
    }
    prise = 0;

    //diago gauche/haut
    i=1;
    while (td[x-i][y-i].couleur!=couleur && y-i-1>=0 && x-i-1>=0){
        i++;
    }
    if (y-i>=0 && x-i>=0 && i!=1){
        if (td[x-i][y-i].couleur==couleur){
            prise = 1;
        }
    }
    if(prise=1){
        i=1;
        while (td[x-i][y-i].couleur!=couleur){
            td[x-i][y-i].couleur = couleur;
            i++;
        }
    }
    prise = 0;

    //diago droite/haut
    i=1;
    while (td[x+i][y-i].couleur!=couleur && y-i-1>=0 && x+i+1<8){
        i++;
    }
    if (y-i>=0 && x+i<8 && i!=1){
        if (td[x+i][y-i].couleur==couleur){
           prise =1;
        }
    }
    if(prise=1){
        i=1;
        while (td[x+i][y-i].couleur!=couleur){
            td[x+i][y-i].couleur = couleur;
            i++;
        }
    }


}