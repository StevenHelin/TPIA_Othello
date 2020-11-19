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
                           td[i][j] = 'B';
                           break;
                        }
                        //e
                        case 4:
                        {
                            td[i][j] = 'N';
                            break;
                        }
                        default:
                        {
                            td[i][j] = ' ';
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
                            td[i][j] = 'N';
                            break;
                        }
                        //e
                        case 4:
                        {
                            td[i][j] = 'B';
                            break;
                        }
                        default:
                        {
                            td[i][j] = ' ';
                        }
                    }
                    break;
                }
                default:
                {
                    td[i][j] = ' ';
                }
            }
        }
    }
}

/**
 * Affiche l'ensemble du damier td passé en paramètre
 * @param td, plateau de jeu
 */
void affichageDamier(tabDamier td) //rajouter un argument -> tableau/matrice
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
            //Afficher pion à rajouter
            printf("%c", td[i][j]);
            printf(" | ");
        }
        printf("\n");
    }
    printf("   +---+---+---+---+---+---+---+---+\n");
    printf("     a   b   c   d   e   f   g   h\n");
}

//implementer une fonction de detection de coup possible pour voir si la partie continue