//
// Created by Guill on 05/11/2020.
//

#include "../header.h"

/**
 * @paragraph Met à jour la ligne souhaitée
 * @param i : Ligne voulue par l'utilisateur
 * @return temp : Nouvelle ligne
 */
int convLigne(int *i)
{
    int temp;
    temp = *i - 1;
    return temp;
}

/**
 * @paragraph Fonction qui convertie un caractère en entier,
 * utilisée pour les coordonnées de la colonne
 * @param c : Caractère à convertir
 * @return i : Entier correspondant à la colonne en fonction de c
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
 * @paragraph Procédure de saisie,
 * vérifie également qu'on puisse bien placer le pion sur le damier
 * @param td : Plateau de jeu
 * @param *x : Coordonnée ligne du pion
 * @param *y : Coordonnée colonne du pion
 * @param tour : Tour du jeu
 * @param cv : Nombre de cases vides
 * @param cb : Nombre de cases blanches
 * @param cn : Nombre de cases noires
 */
void saisie(tabDamier td, int *x, int *y, int tour, int cv, int cb, int cn)
{
    char yc;
    bool valide = false;
    while(!valide)
    {
        affichageDamier(td);
        if(tour % 2 == 0)
        {
            printf("\nTour des noirs !\n\n");
        }
        else
        {
            printf("\nTour des blancs !\n\n");
        }
        // Affiche le nombre de cases
        printf("Noirs = %d, Blancs = %d\n\n", cn, cb);
        printf("Il reste %d emplacement(s) de libre !\n\n", cv);
        // Saisie des coordonnées
        printf("Coordonnee ligne du pion a placer ?\n");
        scanf(" %d", x);
        printf("Coordonnee colonne du pion a placer ?\n");
        scanf(" %c", &yc);
        *x = convLigne(x);
        *y = convCharToInt(yc);
        // printf("Case voulue => Ligne %d, colonne %d\n", *x+1, *y+1);
        // Vérification que la case sélectionnée n'est pas en dehors du plateau
        if( (*x < 0) || (*x > 7) || (*y < 0 ) || (*y > 7) )
        {
            printf("Coordonnees en dehors du plateau, veuillez choisir d'autres coordonnees !\n");
            system("pause");
        }
        else
        {
            valide = true;
        }
    }
}