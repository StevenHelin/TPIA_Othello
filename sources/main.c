/**
 * HELIN Steven
 * DEWAGHE Guillaume
 * TP d'IA
 * M1TNSID
 */

#include "../header.h"

int main()
{
    int x, y, tour;
    // Correspond aux nombres de cases
    int cv, cn, cb;
    Noeud* nouveau;
    Coord c;
    c.x=-1;
    c.y=-1;
    int choix=0;
    char jo;
    bool valide;
    tour = 0;
    jo = 'N';
    tabDamier td;
    CoupJouable cj;
    iniDamier(td);
    printf("entrez votre choix 1:Humain vs humain 2:humain vs IA 3:IA vs IA \n");
    scanf("%d",&choix);
    switch(choix){
        case 1 : //humain contre humain
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
                // Coup valide
                if(detection(td, jo, x, y) == 1)
                {
                    valide = true;
                    priseSandwich(td, x, y, tour);
                }
                // Coup non valide
                else
                {
                    printf("Impossible de placer le pion, veuillez choisir d'autres coordonnees !\n");
                    system("pause");
                }
            }
            calculCases(td, &cv, &cb, &cn);
            // La partie continue
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
            // Fin de la partie
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
            break;
        case 2: //humain contre ia
            calculCases(td, &cv, &cb, &cn);
            while(cv != 0)
            {
                valide = false;
                while(!valide)
                {
                    if (jo=='N') {
                        saisie(td, &x, &y, tour, cv, cb, cn);
                        /*
                        printf("x = %d\n", x);
                        printf("y = %d\n", y);
                        */
                        // Coup valide
                        if (detection(td, jo, x, y) == 1) {
                            valide = true;
                            priseSandwich(td, x, y, tour);
                            jo='B';
                        }
                            // Coup non valide
                        else {
                            printf("Impossible de placer le pion, veuillez choisir d'autres coordonnees !\n");
                            system("pause");
                        }

                    }
                    else {
                        nouveau = IA(td, cj, 'N', tour, jo, 0, -1);
                        c = meilleurCoup(nouveau);
                        if (c.x != -1) {
                            priseSandwich(td, c.x, c.y, tour);
                        }
                        jo='N';
                        valide=true;
                    }
                }


                calculCases(td, &cv, &cb, &cn);
                // La partie continue
                if(cv != 0)
                {
                    calculCases(td, &cv, &cb, &cn);
                    tour = (tour + 1) % 2;
                    /*if(tour == 0)
                    {
                        jo = 'N';
                    }
                    else
                    {
                        jo = 'B';
                    }*/
                }

                    // Fin de la partie
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
            break;
        case 3: //Ia contre ia
            calculCases(td, &cv, &cb, &cn);
            while(cv != 0)
            {
                valide = false;
                while(!valide)
                {
                    affichageDamier(td);
                    if (jo=='N') {
                        nouveau = IA(td, cj, 'B', tour, jo, 0, -1);
                        c = meilleurCoup(nouveau);
                        if (c.x != -1) {
                            priseSandwich(td, c.x, c.y, tour);
                        }
                        jo='B';
                        valide=true;

                    }
                    else {
                        nouveau = IA(td, cj, 'N', tour, jo, 0, -1);
                        c = meilleurCoup(nouveau);
                        if (c.x != -1) {
                            priseSandwich(td, c.x, c.y, tour);
                        }
                        jo='N';
                        valide=true;
                    }
                }


                calculCases(td, &cv, &cb, &cn);
                // La partie continue
                if(cv != 0)
                {
                    calculCases(td, &cv, &cb, &cn);
                    tour = (tour + 1) % 2;
                    /*if(tour == 0)
                    {
                        jo = 'N';
                    }
                    else
                    {
                        jo = 'B';
                    }*/
                }

                    // Fin de la partie
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
            break;
    }
    return 0;
}
