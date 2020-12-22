//
// Created by Guill on 22/12/2020.
//

#include "../header.h"

void priseLigne(tabDamier td, char jo, int x, int yd, int yf)
{
    int j;
    // Prise vers la droite
    for(j = yd; j < yf; j++)
    {
        td[x][j].couleur = jo;
    }
    // Prise vers la gauche
    for(j = yd; j > yf; j--)
    {
        td[x][j].couleur = jo;
    }
}

void priseColonne(tabDamier td, char jo, int xd, int xf, int y)
{
    int i;
    // Prise vers le bas
    for(i = xd; i < xf; i++)
    {
        td[i][y].couleur = jo;
    }
    // Prise vers le haut
    for(i = xd; i > xf; i--)
    {
        td[i][y].couleur = jo;
    }
}

void priseDiago(tabDamier td, char jo, int xd, int xf, int yd, int yf)
{
    int i, j;
    i = xd;
    j = yd;
    // Prise diagonale bas-droite
    while(i < xf && j < yf)
    {
        td[i][j].couleur = jo;
        i++;
        j++;
    }
    // Prise diagonale bas-gauche
    while(i < xf && j > yf)
    {
        td[i][j].couleur = jo;
        i++;
        j--;
    }
    //Prise diagonale haut-droite
    while(i > xf && j < yf)
    {
        td[i][j].couleur = jo;
        i--;
        j++;
    }
    // Prise diagonale haut-gauche
    while(i > xf && j > yf)
    {
        td[i][j].couleur = jo;
        i--;
        j--;
    }
}
