/**
 * HELIN Steven
 * DEWAGHE Guillaume
 * TP d'IA
 * M1TNSID
 */

#include "../header.h"

/**
 * @paragraph Fonction qui permet de vérifier qu'on puisse bien placer un pion sur le damier en détectant dans toutes les directions
 * @param td : Plateau de jeu
 * @param jo : Couleur du joueur actuel
 * @param x : Coordonnée ligne du pion qu'on veut placer
 * @param y : Coordonnée colonne du pion qu'on veut placer
 * @return coupValide : Variable permettant de savoir si la prise est possible ou non
 */
int detection(tabDamier td, char jo, int x, int y)
{
    int coupValide=0;
    int i=1;
    //verifie sur la ligne de droite
    while (td[x+i][y].couleur!=jo && td[x+i][y].couleur!=' ' && x+i+1<8)
    {
        i++;
    }
    if (x+i<8 && i!=1)
    {
        if (td[x+i][y].couleur==jo)
        {
            coupValide=1;
        }
    }
    //verifie sur la ligne de gauche
    i=1;
    while (td[x-i][y].couleur!=jo && td[x-i][y].couleur!=' ' && x-i-1>=0)
    {
        i++;
    }
    if (x-i>=0 && i!=1)
    {
        if (td[x-i][y].couleur==jo)
        {
            coupValide=1;
        }
    }
    //verifie en haut
    i=1;
    while (td[x][y-i].couleur!=jo && td[x][y-i].couleur!=' '&& y-i-1>=0)
    {
        i++;
    }
    if (y-i>=0 && i!=1)
    {
        if (td[x][y-i].couleur==jo)
        {
            coupValide=1;
        }
    }
    //verifie en bas
    i=1;
    while (td[x][y+i].couleur!=jo &&td[x][y+i].couleur!=' ' &&y+i+1<8)
    {
        i++;
    }
    if (y+i<8 && i!=1)
    {
        if (td[x][y+i].couleur==jo)
        {
           coupValide=1;
        }
    }
    //verifie diagonale droite/bas
    i=1;
    while (td[x+i][y+i].couleur!=jo && td[x+i][y+i].couleur!=' ' && y+i+1<8 && x+i+1<8)
    {
        i++;
    }
    if (y+i<8 && x+i<8 && i!=1)
    {
        if (td[x+i][y+i].couleur==jo)
        {
            coupValide=1;
        }
    }
    //verifie diagonale gauche/bas
    i=1;
    while (td[x-i][y+i].couleur!=jo && td[x-i][y+i].couleur!=' ' && y+i+1<8 && x-i-1>=0)
    {
        i++;
    }
    if (y+i<8 && x-i>=0 && i!=1)
    {
        if (td[x-i][y+i].couleur == jo)
        {
            coupValide=1;
        }
    }
    //verifie diagonale gauche/haut
    i=1;
    while (td[x-i][y-i].couleur!=jo &&td[x-i][y-i].couleur!=' ' && y-i-1>=0 && x-i-1>=0)
    {
        i++;
    }
    if (y-i>=0 && x-i>=0 && i!=1)
    {
        if (td[x-i][y-i].couleur==jo)
        {
            coupValide=1;
        }
    }
    //verifie diagonale droite/haut
    i=1;
    while (td[x+i][y-i].couleur!=jo && td[x+1][y-1].couleur!=' ' && y-i-1>=0 && x+i+1<8)
    {
        i++;
    }
    if (y-i>=0 && x+i<8 && i!=1)
    {
        if (td[x+i][y-i].couleur == jo)
        {
           coupValide=1;
        }
    }
    return coupValide;
}

