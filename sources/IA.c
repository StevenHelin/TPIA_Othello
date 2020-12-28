/**
 * HELIN Steven
 * DEWAGHE Guillaume
 * TP d'IA
 * M1TNSID
 */

#include "../header.h"

Noeud Creation (tabDamier damier){
    Noeud* nouveau;
    nouveau = (Noeud*) malloc (sizeof(Noeud));
    if(nouveau){
        for (int i=0;i<=64;i++){
            for(int j=0;j<=64;j++){
                nouveau->damier[i][j]=damier[i][j];
            }
        }
    }

}

CoupJouable
/**function minimax(node, depth, maximizingPlayer) is
if depth = 0 or node is a terminal node then
return the heuristic value of node
if maximizingPlayer then
value := −∞
for each child of node do
value := max(value, minimax(child, depth − 1, FALSE))
return value
else (* minimizing player *)
value := +∞
for each child of node do
value := min(value, minimax(child, depth − 1, TRUE))
return value
(* Initial call *)
minimax(origin, depth, TRUE)
**/