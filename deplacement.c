//
// Created by Guill on 05/11/2020.
//

#include "header.h"

bool detectionLigne(tabDamier td, char jo, int x, int y);
bool detectionColonne(tabDamier td, char jo, int x, int y);

/**
 * Met à jour la ligne souhaitée
 * @param i, ligne voulue par l'utilisateur
 * @return
 */
int convLigne(int i)
{
    return i - 1;
}

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

void saisie(tabDamier td, char jo)
{
    int x, y;
    char yc;
    bool valide = false;
    while(!valide)
    {
        printf("Coordonnee ligne du pion a placer ? ");
        scanf("%d", &x);
        printf("Coordonnee colonne du pion a placer ? ");
        scanf("%c", yc);
        x = convLigne(x);
        y = convCharToInt(yc);
        printf("Case voulue => Ligne %d, colonne %d", x, y);
        // Vérification que la case sélectionnée n'est pas en dehors du plateau
        if( (x < 0) || (x > 8) || (y < 0 ) || (y > 8) )
        {
            printf("Coordonnees en dehors du plateau, veuillez choisir d'autres coordonnees !\n");
            printf("Appuyez sur une touche pour continuer...");
            system("pause");
            system("clear");
        }
        // Vérification que la case sélectionnée n'est pas occupée
        else if(td[x][y].couleur != ' ')
        {
            printf("Case déjà remplie, veuillez choisir d'autres coordonnees !\n");
            printf("Appuyez sur une touche pour continuer...");
            system("pause");
            system("clear");
        }
        // Vérification des prises pour bien valider le pion
        else if( (!detectionLigne(td, jo, x, y) ) && (!detectionColonne(td, jo, x, y) ) )
        {
            printf("Aucune prise possible, veuillez choisir d'autres coordonnees !\n");
            printf("Appuyez sur une touche pour continuer...");
            system("pause");
            system("clear");
        }
        else
        {
            valide = true;
        }

    }
}

/* ----- DETECTION LIGNE ----- */

/**
 * Regarde à gauche si on peut prendre sur cette ligne
 * @param td
 * @param jo
 * @param x
 * @param y
 * @return
 */
bool detectionLigneG(tabDamier td, char jo, int x, int y)
{
    int j = y;
    if(j < 0)
    {
        return false;
    }
    for(; j > 0; j--)
    {
        if(td[x][j].couleur == ' ')
        {
            return false;
        }
        else if(td[x][j].couleur != jo)
        {
            continue;
        }
        else
        {
            return true;
        }
    }
}

/**
 * Regarde à droite si on peut prendre sur cette ligne
 * @param td
 * @param jo
 * @param x
 * @param y
 * @return
 */
bool detectionLigneD(tabDamier td, char jo, int x, int y)
{
    int j = y;
    if(j > 7)
    {
        return false;
    }
    for(; j < 8; j++)
    {
        if(td[x][j].couleur == ' ')
        {
            return false;
        }
        if(td[x][j].couleur != jo)
        {
            continue;
        }
        else
        {
            return true;
        }
    }
}

/**
 * Détecte si il y a une possibilité de prendre sur la ligne
 * @param td
 * @param jo
 * @param x
 * @param y
 * @return
 */
bool detectionLigne(tabDamier td, char jo, int x, int y)
{
    // Vérifier à droite et à gauche s'il n'y a pas d'espace vide OU si le pion à côté n'est pas de la même couleur
    switch(y)
    {
        // Extrémité gauche
        case 0:
        {
            if( (td[x][y + 1].couleur == ' ') || (td[x][y + 1].couleur == jo) || (!detectionLigneD(td, jo, x, y + 2) ) )
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        // Extrémité droite
        case 7:
        {
            if( (td[x][y - 1].couleur == ' ') || (td[x][y - 1].couleur == jo) || (!detectionLigneG(td, jo, x, y - 2) ) )
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        // Entre 1 et 6
        default:
        {
            if( ( ( (td[x][y + 1].couleur == ' ') || (td[x][y + 1].couleur == jo) ) && ( (td[x][y - 1].couleur == ' ') || (td[x][y - 1].couleur == jo) ) )
            || ( (!detectionLigneD(td, jo, x, y + 2) ) || (!detectionLigneG(td, jo, x, y - 2) ) ) )
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}

/* ----- DETECTION LIGNE ----- */

/* ----- DETECTION COLONNE ----- */

/**
 * Détecte s'il y a possibilité de prendre en haut
 * @param td
 * @param jo
 * @param x
 * @param y
 * @return
 */
bool detectionColonneH(tabDamier td, char jo, int x, int y)
{
    int i = x;
    if(i < 0)
    {
        return false;
    }
    for(; i > 0; i--)
    {
        if(td[i][y].couleur == ' ')
        {
            return false;
        }
        else if(td[i][y].couleur != jo)
        {
            continue;
        }
        else
        {
            return true;
        }
    }
}

/**
 * Détecte s'il y a possibilité de prendre en bas
 * @param td
 * @param jo
 * @param x
 * @param y
 * @return
 */
bool detectionColonneB(tabDamier td, char jo, int x, int y)
{
    int i = x;
    if(i > 8)
    {
        return false;
    }
    for(; i < 8; i++)
    {
        if(td[i][y].couleur == ' ')
        {
            return false;
        }
        else if(td[i][y].couleur != jo)
        {
            continue;
        }
        else
        {
            return true;
        }
    }
}

/**
 * Détecte si il y a une possibilité de prendre sur la colonne
 * @param td
 * @param jo
 * @param x
 * @param y
 * @return
 */
bool detectionColonne(tabDamier td, char jo, int x, int y)
{
    // Vérifier en haut et en bas s'il n'y a pas d'espace vide OU si le pion n'est pas de la même couleur
    switch(y)
    {
        // Extrémité haut
        case 0:
        {
            if( (td[x + 1][y].couleur == ' ') || (td[x + 1][y].couleur == jo) || (!detectionColonneB(td, jo, x + 2, y) ) )
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        // Extrémité bas
        case 7:
        {
            if( (td[x - 1][y].couleur == ' ') || (td[x - 1][y].couleur == jo) || (!detectionColonneH(td, jo, x - 2, y) ) )
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        // Entre 1 et 6
        default:
        {
            if( ( ( (td[x + 1][y].couleur == ' ') || (td[x + 1][y].couleur == jo) ) && ( (td[x][y - 1].couleur == ' ') || (td[x][y - 1].couleur == jo) ) )
                || ( (!detectionColonneB(td, jo, x + 2, y) ) || (!detectionColonneH(td, jo, x - 2, y) ) ) )
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}

/* ----- DETECTION COLONNE ----- */