//
// Created by Guill on 15/10/2020.
//

#include "header.h"

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
 * Affiche l'ensemble du damier td passé en paramètre
 * @param td, plateau de jeu
 */
void affichageDamier(tabDamier td)
{
    /// on va afficher le tableau de type piece dans cette procedure on appellera la fonction précedente
    int i, j, k;
    k = 1;
    system("cls");
    for (i = 0; i < 8; i++)
    {
        printf("   +---+---+---+---+---+---+---+---+\n");
        printf(" %d | ",k);
        k++;
        for(j = 0; j < 8; j++)
        {
            printf("%c", td[i][j].couleur);
            printf(" | ");
        }
        printf("\n");
    }
    printf("   +---+---+---+---+---+---+---+---+\n");
    printf("     a   b   c   d   e   f   g   h\n");
}
