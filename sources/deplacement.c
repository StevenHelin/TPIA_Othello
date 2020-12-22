//
// Created by Guill on 05/11/2020.
//

#include "../header.h"

/**
 * Met à jour la ligne souhaitée
 * @param i, ligne voulue par l'utilisateur
 * @return
 */
int convLigne(int *i)
{
    int temp;
    temp = *i - 1;
    return temp;
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
        case 'h':
        {
            i = 7;
            break;
        }
        default:
        {
            i = 8;
        }
    }
    return i;
}

/**
 * Procédure de saisie
 * Vérifie qu'on puisse bien placer le pion sur le damier
 * @param td
 * @param jo
 */
void saisie(int *x, int *y)
{
    char yc;
    bool valide = false;
    while(!valide)
    {
        printf("Coordonnee ligne du pion a placer ? ");
        scanf("%d", x);
        printf("Coordonnee colonne du pion a placer ? ");
        scanf(" %c", &yc);
        *x = convLigne(x);
        *y = convCharToInt(yc);
        printf("Case voulue => Ligne %d, colonne %d\n", *x+1, *y+1);
        // Vérification que la case sélectionnée n'est pas en dehors du plateau
        if( (*x < 0) || (*x > 7) || (*y < 0 ) || (*y > 7) )
        {
            printf("Coordonnees en dehors du plateau, veuillez choisir d'autres coordonnees !\n");
            system("pause");
            system("cls");
        }
        else
        {
            valide = true;
        }
    }
}