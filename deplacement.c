//
// Created by Guill on 05/11/2020.
//

#include "header.h"

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
void saisie(tabDamier td, char jo)
{
    int x, y;
    char yc;
    bool valide = false;
    while(!valide)
    {
        affichageDamier(td);
        printf("Couleur du joueur = %c\n", jo);
        printf("Coordonnee ligne du pion a placer ? ");
        scanf("%d", &x);
        printf("Coordonnee colonne du pion a placer ? ");
        scanf(" %c", &yc);
        x = convLigne(x);
        y = convCharToInt(yc);
        printf("Case voulue => Ligne %d, colonne %d\n", x+1, y+1);
        // Vérification que la case sélectionnée n'est pas en dehors du plateau
        if( (x < 0) || (x > 7) || (y < 0 ) || (y > 7) )
        {
            printf("Coordonnees en dehors du plateau, veuillez choisir d'autres coordonnees !\n");
            system("pause");
            system("cls");
        }
        // Vérification que la case sélectionnée n'est pas occupée
        else if(td[x][y].couleur != ' ')
        {
            printf("Case deja remplie, veuillez choisir d'autres coordonnees !\n");
            printf("Appuyez sur une touche pour continuer...");
            system("pause");
            system("cls");
        }
        // Vérification des prises pour bien valider le pion
        else if( (!detectionLigne(td, jo, x, y) ) && (!detectionColonne(td, jo, x, y) ) )
        {
            printf("Aucune prise possible, veuillez choisir d'autres coordonnees !\n");
            system("pause");
            system("cls");
        }
        else
        {
            valide = true;
            td[x][y].couleur = jo;
        }
    }
}

/* ----- DETECTION LIGNE ----- */

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
    int i, ii, j, jj;
    bool valide = false;
    switch(y)
    {
        // Extrémité gauche
        case 0:
        {
            // On vérifie si la case à droite n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x][y+1].couleur == ' ' || td[x][y+1].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(j = 2; j < 8; j++)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[x][j].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[x][j].couleur != jo)
                        {
                            continue;
                        }
                        // La couleur du pion est identique à celui du joueur
                        else
                        {
                            jj = j;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(j = 1; j < jj; j++)
                            {
                                td[x][j].couleur = jo;
                            }
                            break;
                        }
                    }
                    // Le pion est inoccupé, on ne peut pas faire de prise
                    else
                    {
                        printf("Aucune prise possible, choisir d'autres coordonnees\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
            }
            break;
        }
        // Colonne 2
        case 1:
        {
            // On vérifie si la case à droite n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x][y+1].couleur == ' ' || td[x][y+1].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(j = 3; j < 8; j++)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[x][j].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[x][j].couleur != jo)
                        {
                            continue;
                        }
                            // La couleur du pion est identique à celui du joueur
                        else
                        {
                            jj = j;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(j = 2; j < jj; j++)
                            {
                                td[x][j].couleur = jo;
                            }
                            break;
                        }
                    }
                        // Le pion est inoccupé, on ne peut pas faire de prise
                    else
                    {
                        printf("Aucune prise possible, choisir d'autres coordonnees\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
            }
            break;
        }
        // Colonne 7
        case 6:
        {
            // On vérifie si la case à gauche n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x][y-1].couleur == ' ' || td[x][y-1].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(j = 4; j > 0; j--)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[x][j].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[x][j].couleur != jo)
                        {
                            continue;
                        }
                            // La couleur du pion est identique à celui du joueur
                        else
                        {
                            jj = j;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(j = 5; j > jj; j--)
                            {
                                td[x][j].couleur = jo;
                            }
                            break;
                        }
                    }
                        // Le pion est inoccupé, on ne peut pas faire de prise
                    else
                    {
                        printf("Aucune prise possible, choisir d'autres coordonnees\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
            }
            break;
        }
        // Extrémité droite
        case 7:
        {
            // On vérifie si la case à gauche n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x][y-1].couleur == ' ' || td[x][y-1].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(j = 5; j > 0; j--)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[x][j].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[x][j].couleur != jo)
                        {
                            continue;
                        }
                        // La couleur du pion est identique à celui du joueur
                        else
                        {
                            jj = j;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(j = 6; j > jj; j--)
                            {
                                td[x][j].couleur = jo;
                            }
                            break;
                        }
                    }
                        // Le pion est inoccupé, on ne peut pas faire de prise
                    else
                    {
                        printf("Aucune prise possible, choisir d'autres coordonnees\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
            }
            break;
        }
        // Colonnes 3 à 6
        default:
        {
            // On regarde à gauche
            for(j = y-1; j > -1; j--)
            {
                // Si la case est vide, on arrête de vérifier à gauche
                if(td[x][j].couleur == ' ')
                {
                    printf("Aucune prise possible, choisir d'autres coordonnees\n");
                    system("pause");
                    system("cls");
                    break;
                }
                else
                {
                    // Si le pion n'est de la même couleur, on continue la recherche
                    if(td[x][j].couleur != jo)
                    {
                        continue;
                    }
                    // Le pion est de la même couleur, on peut manger à gauche
                    else
                    {
                        jj = j-1;
                        for(j = y-1; j > jj; j--)
                        {
                            td[x][j].couleur = jo;
                        }
                        break;
                    }
                }
            }
            // On regarde à droite
            for(j = y+1; j < 8; j++)
            {
                // Si la case est vide, on arrête de vérifier à gauche
                if(td[x][j].couleur == ' ')
                {
                    printf("Aucune prise possible, choisir d'autres coordonnees\n");
                    system("pause");
                    system("cls");
                    break;
                }
                else
                {
                    // Si le pion n'est de la même couleur, on continue la recherche
                    if(td[x][j].couleur != jo)
                    {
                        continue;
                    }
                        // Le pion est de la même couleur, on peut manger à gauche
                    else
                    {
                        jj = j;
                        for(j = y+1; j < jj; j++)
                        {
                            td[x][j].couleur = jo;
                        }
                        break;
                    }
                }
            }
        }
    }
}

/* ----- DETECTION LIGNE ----- */

/* ----- DETECTION COLONNE ----- */

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
    int i, ii;
    bool valide = false;
    switch(x)
    {
        // Tout en haut
        case 0:
        {
            // On vérifie si la case à droite n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x][y+1].couleur == ' ' || td[x][y+1].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(j = 2; j < 8; j++)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[x][j].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[x][j].couleur != jo)
                        {
                            continue;
                        }
                            // La couleur du pion est identique à celui du joueur
                        else
                        {
                            jj = j;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(j = 1; j < jj; j++)
                            {
                                td[x][j].couleur = jo;
                            }
                            break;
                        }
                    }
                        // Le pion est inoccupé, on ne peut pas faire de prise
                    else
                    {
                        printf("Aucune prise possible, choisir d'autres coordonnees\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
            }
            break;
        }
            // Colonne 2
        case 1:
        {
            // On vérifie si la case à droite n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x][y+1].couleur == ' ' || td[x][y+1].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(j = 3; j < 8; j++)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[x][j].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[x][j].couleur != jo)
                        {
                            continue;
                        }
                            // La couleur du pion est identique à celui du joueur
                        else
                        {
                            jj = j;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(j = 2; j < jj; j++)
                            {
                                td[x][j].couleur = jo;
                            }
                            break;
                        }
                    }
                        // Le pion est inoccupé, on ne peut pas faire de prise
                    else
                    {
                        printf("Aucune prise possible, choisir d'autres coordonnees\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
            }
            break;
        }
            // Colonne 7
        case 6:
        {
            // On vérifie si la case à gauche n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x][y-1].couleur == ' ' || td[x][y-1].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(j = 4; j > 0; j--)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[x][j].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[x][j].couleur != jo)
                        {
                            continue;
                        }
                            // La couleur du pion est identique à celui du joueur
                        else
                        {
                            jj = j;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(j = 5; j > jj; j--)
                            {
                                td[x][j].couleur = jo;
                            }
                            break;
                        }
                    }
                        // Le pion est inoccupé, on ne peut pas faire de prise
                    else
                    {
                        printf("Aucune prise possible, choisir d'autres coordonnees\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
            }
            break;
        }
            // Extrémité droite
        case 7:
        {
            // On vérifie si la case à gauche n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x][y-1].couleur == ' ' || td[x][y-1].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(j = 5; j > 0; j--)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[x][j].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[x][j].couleur != jo)
                        {
                            continue;
                        }
                            // La couleur du pion est identique à celui du joueur
                        else
                        {
                            jj = j;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(j = 6; j > jj; j--)
                            {
                                td[x][j].couleur = jo;
                            }
                            break;
                        }
                    }
                        // Le pion est inoccupé, on ne peut pas faire de prise
                    else
                    {
                        printf("Aucune prise possible, choisir d'autres coordonnees\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
            }
            break;
        }
            // Colonnes 3 à 6
        default:
        {
            // On regarde à gauche
            for(j = y-1; j > -1; j--)
            {
                // Si la case est vide, on arrête de vérifier à gauche
                if(td[x][j].couleur == ' ')
                {
                    printf("Aucune prise possible, choisir d'autres coordonnees\n");
                    system("pause");
                    system("cls");
                    break;
                }
                else
                {
                    // Si le pion n'est de la même couleur, on continue la recherche
                    if(td[x][j].couleur != jo)
                    {
                        continue;
                    }
                        // Le pion est de la même couleur, on peut manger à gauche
                    else
                    {
                        jj = j-1;
                        for(j = y-1; j > jj; j--)
                        {
                            td[x][j].couleur = jo;
                        }
                        break;
                    }
                }
            }
            // On regarde à droite
            for(j = y+1; j < 8; j++)
            {
                // Si la case est vide, on arrête de vérifier à gauche
                if(td[x][j].couleur == ' ')
                {
                    printf("Aucune prise possible, choisir d'autres coordonnees\n");
                    system("pause");
                    system("cls");
                    break;
                }
                else
                {
                    // Si le pion n'est de la même couleur, on continue la recherche
                    if(td[x][j].couleur != jo)
                    {
                        continue;
                    }
                        // Le pion est de la même couleur, on peut manger à gauche
                    else
                    {
                        jj = j;
                        for(j = y+1; j < jj; j++)
                        {
                            td[x][j].couleur = jo;
                        }
                        break;
                    }
                }
            }
        }
    }
}

/* ----- DETECTION COLONNE ----- */