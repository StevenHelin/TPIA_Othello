//
// Created by Guill on 22/12/2020.
//

#include "../header.h"

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
    int j, jj;
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
                return valide;
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
                            valide = true;
                            return valide;
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
                        return valide;
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
                return valide;
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
                            valide = true;
                            return valide;
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
                        return valide;
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
                return valide;
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
                            valide = true;
                            return valide;
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
                        return valide;
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
                return valide;
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
                            valide = true;
                            return valide;
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
                        return valide;
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
                    return valide;
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
                        valide = true;
                        return valide;
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
                    return valide;
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
                        valide = true;
                        return valide;
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
            // On vérifie si la case en bas n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x+1][y].couleur == ' ' || td[x+1][y].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(i = 2; i < 8; i++)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[i][y].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[i][y].couleur != jo)
                        {
                            continue;
                        }
                            // La couleur du pion est identique à celui du joueur
                        else
                        {
                            ii = i;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(i = 1; i < ii; i++)
                            {
                                td[i][y].couleur = jo;
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
        // Ligne 2
        case 1:
        {
            // On vérifie si la case en bas n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x+1][y].couleur == ' ' || td[x+1][y].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(i = 3; i < 8; i++)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[i][y].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[i][y].couleur != jo)
                        {
                            continue;
                        }
                        // La couleur du pion est identique à celui du joueur
                        else
                        {
                            ii = i;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(i = 2; i < ii; i++)
                            {
                                td[i][y].couleur = jo;
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
        // Ligne 7
        case 6:
        {
            // On vérifie si la case en haut n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x-1][y].couleur == ' ' || td[x-1][y].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(i = 4; i > 0; i--)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[i][y].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[i][y].couleur != jo)
                        {
                            continue;
                        }
                        // La couleur du pion est identique à celui du joueur
                        else
                        {
                            ii = i;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(i = 5; i > ii; i--)
                            {
                                td[i][y].couleur = jo;
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
        // Tout en bas
        case 7:
        {
            // On vérifie si la case en haut n'est pas vide OU n'est pas un pion de la même couleur
            if(td[x-1][y].couleur == ' ' || td[x-1][y].couleur == jo)
            {
                printf("Aucune prise possible, choisir d'autres coordonnees\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(i = 5; i > 0; i--)
                {
                    // On vérifie qu'il y a bien un pion
                    if(td[i][y].couleur != ' ')
                    {
                        // On vérifie que la couleur du pion est différente du joueur actuel
                        if(td[i][y].couleur != jo)
                        {
                            continue;
                        }
                            // La couleur du pion est identique à celui du joueur
                        else
                        {
                            ii = i;
                            // On met les pions en sandwich de la même couleur que le joueur actuel
                            for(i = 6; i > ii; i--)
                            {
                                td[i][y].couleur = jo;
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
        // Lignes 3 à 6
        default:
        {
            // On regarde en haut
            for(i = x-1; i > -1; i--)
            {
                // Si la case est vide, on arrête de vérifier en haut
                if(td[i][y].couleur == ' ')
                {
                    printf("Aucune prise possible, choisir d'autres coordonnees\n");
                    system("pause");
                    system("cls");
                    break;
                }
                else
                {
                    // Si le pion n'est de la même couleur, on continue la recherche
                    if(td[i][y].couleur != jo)
                    {
                        continue;
                    }
                    // Le pion est de la même couleur, on peut manger à gauche
                    else
                    {
                        ii = i-1;
                        for(i = x-1; i > ii; i--)
                        {
                            td[i][y].couleur = jo;
                        }
                        break;
                    }
                }
            }
            // On regarde en bas
            for(i = x+1; i < 8; i++)
            {
                // Si la case est vide, on arrête de vérifier à gauche
                if(td[i][y].couleur == ' ')
                {
                    printf("Aucune prise possible, choisir d'autres coordonnees\n");
                    system("pause");
                    system("cls");
                    break;
                }
                else
                {
                    // Si le pion n'est de la même couleur, on continue la recherche
                    if(td[i][y].couleur != jo)
                    {
                        continue;
                    }
                        // Le pion est de la même couleur, on peut manger à gauche
                    else
                    {
                        ii = i;
                        for(i = x+1; i < ii; i++)
                        {
                            td[i][y].couleur = jo;
                        }
                        break;
                    }
                }
            }
        }
    }
}

/* ----- DETECTION COLONNE ----- */

/*----- DETECTION DIAGONALES -----*/

bool detectionDiagonale(tabDamier td, char jo, int x, int y)
{

}

/*----- DETECTION DIAGONALES -----*/

