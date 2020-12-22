#include "../header.h"

int main()
{
    int x, y;
    char jo;
    jo = 'N';
    tabDamier td;
    iniDamier(td);
    saisie(&x, &y);
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    //affichageDamier(td);
    return 0;
}
