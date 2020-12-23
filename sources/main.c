#include "../header.h"

int main()
{
    int x, y, tour, continuer = 1;
    char jo;
    bool valide;
    tour = 0;
    jo = 'N';
    tabDamier td;
    iniDamier(td);
    while(continuer == 1)
    {
        valide = false;
        while(!valide)
        {
            saisie(td, &x, &y, tour);
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
        printf("Continuer ?\n");
        scanf("%d", &continuer);
        if(continuer == 1)
        {
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
    }
    affichageDamier(td);
    return 0;
}
