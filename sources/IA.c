/**
 * HELIN Steven
 * DEWAGHE Guillaume
 * TP d'IA
 * M1TNSID
 */

#include "../header.h"

/**
 * @paragraph Va vérifer les cases de score du tableau pour le meilleur coup possible
 * @param n
 * @return
 */
int evaluer(Noeud n)
{
    return 1;
}

/**
 * @paragraph Vérifie que le noeud est terminal ou non
 * @param n
 * @return true => c'est le cas
 * @return false => ce n'est pas le cas
 */
bool estTerminal(Noeud n)
{
    return false;
}

int maxValue(Noeud n)
{
    int v;
    int n2;
    if(estTerminal(n) )
    {
        return evaluer(n);
    }
    v = INT_MIN;
    for(n2 = 0; n2 < 10; n2++)
    {
        v = max(v, min)
    }
    return v;
}

int minValue(Noeud n)
{
    int v;
    return v;
}

