//
// Created by Guill on 15/10/2020.
//

#include "../header.h"

/**
 * @paragraph Initialisation des cases du jeu de l'Othello
 * @param td : Plateau de jeu
 */
void iniDamier(tabDamier td)
{
    int i, j;
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            switch(i)
            {
                //4e ligne
                case 3:
                {
                    switch(j)
                    {
                        //d
                        case 3:
                        {
                           td[i][j].couleur = 'B';
                           break;
                        }
                        //e
                        case 4:
                        {
                            td[i][j].couleur = 'N';
                            break;
                        }
                        default:
                        {
                            td[i][j].couleur = ' ';
                        }
                    }
                    break;
                }
                //5e ligne
                case 4:
                {
                    switch(j)
                    {
                        //d
                        case 3:
                        {
                            td[i][j].couleur = 'N';
                            break;
                        }
                        //e
                        case 4:
                        {
                            td[i][j].couleur = 'B';
                            break;
                        }
                        default:
                        {
                            td[i][j].couleur = ' ';
                        }
                    }
                    break;
                }
                default:
                {
                    td[i][j].couleur = ' ';
                }
            }
        }
    }
}

/**
 * @paragraph Affiche l'ensemble du damier td passé en paramètre
 * @param td : Plateau de jeu
 */
void affichageDamier(tabDamier td)
{
    int k = 1;
    for (int i = 0; i < 8; i++)
    {
        printf("   +---+---+---+---+---+---+---+---+\n");
        printf(" %d | ",k);
        k++;
        for(int j = 0; j < 8; j++)
        {
            printf("%c", td[i][j].couleur);
            printf(" | ");
        }
        printf("\n");
    }
    printf("   +---+---+---+---+---+---+---+---+\n");
    printf("     a   b   c   d   e   f   g   h\n");
}

//implementer une fonction de detection de coup possible pour voir si la partie continue
/**
 * @paragraph Fonction qui calcul le nombre de cases vides, blanches ou noires
 * @param td : Plateau de jeu
 * @param cv : Nombre de cases vides
 * @param cb : Nombre de cases blanches
 * @param cn : Nombre de cases noires
 */
void calculCases(tabDamier td, int *cv, int *cb, int *cn)
{
    int cvT = 0;
    int cbT = 0;
    int cnT = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            switch(td[i][j].couleur)
            {
                case 'B':
                {
                    cbT++;
                    break;
                }
                case 'N':
                {
                    cnT++;
                    break;
                }
                default:
                {
                    cvT++;
                }
            }
        }
    }
    *cn = cnT;
    *cb = cbT;
    *cv = cvT;
}