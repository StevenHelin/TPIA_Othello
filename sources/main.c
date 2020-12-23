#include "../header.h"

int main()
{
    int x, y, tour;
    // Correspond aux nombres de cases
    int cv, cn, cb;
    char jo;
    bool valide;
    tour = 0;
    jo = 'N';
    tabDamier td;
    iniDamier(td);
    calculCases(td, &cv, &cb, &cn);
    //printf("cv = %d, cn = %d, cb = %d\n", cv, cn, cb);
    while(cv != 0)
    {
        valide = false;
        while(!valide)
        {
            saisie(td, &x, &y, tour, cv, cb, cn);
            /*
            printf("x = %d\n", x);
            printf("y = %d\n", y);
            */
            if(detection(td, jo, x, y) == 1)
            {
                valide = true;
                priseSandwich(td, x, y, tour);
            }
            else
            {
                printf("Impossible de placer le pion, veuillez choisir d'autres coordonnees !\n");
                system("pause");
            }
        }
        calculCases(td, &cv, &cb, &cn);
        if(cv != 0)
        {
            calculCases(td, &cv, &cb, &cn);
            tour = (tour + 1) % 2;
            if(tour == 0)
            {
                jo = 'N';
            }
            else
            {
                jo = 'B';
            }
        }
        else
        {
            affichageDamier(td);
            printf("\nLa partie est terminee !\n");
            printf("\n----- SCORES -----\n");
            printf("\n Noirs = %d, Blancs = %d\n", cn, cb);
            if(cn > cb)
            {
                printf("\nVictoire des noirs !\n");
            }
            else if(cn < cb)
            {
                printf("\nVictoire des blancs !\n");
            }
            else
            {
                printf("\nEgalite !\n");
            }
        }
    }
    return 0;
}
