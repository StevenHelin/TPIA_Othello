#include "header.h"

int main()
{
    tabDamier td;
    iniDamier(td);
    affichageDamier(td);
    int  tour=0;//0=IA,1=humain
    int partieterminee=0;//passe a 1 si la partie est finie
    int plusDeCoupPossible = 1;//passe a 0 si plus de coup possible

    while (partieterminee!=1){
        //detecter s'il y a encore des coups possible a faire sinon finir la partie directement
        if (tour==0){//tour de L'IA
            //evaluation du tableau
            // Min Max
            //detection si le coup est possible
            //jouer le coup
            tour=1;
        }
        if (tour==1){//tour du joueur humain
            //appeler la fonction saisie coordonnée
            tour=0;
        }

    }
    return 0;
}
