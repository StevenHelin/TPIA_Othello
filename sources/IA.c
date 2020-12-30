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

void detectionPossible (tabDamier damier){
    CoupJouable cj;
    char jo= 'B';
    int possible=0;
    int k=0;
    for (int  i = 0; i<=64 ;i++ ) {
        for (int j=0;j<=64;j++){
            possible = detection(damier,jo,i,j);
            if (possible==1){
                cj[k].x=i;
                cj[k].y=j;
              }
            possible=0;
            k++;
        }
    }
}

//fonction qui permet d'instancier un fils
Fils instancier(){

}

// fonction qui permet de detecter si tour passé ou si victoire
int condition(CoupJouable cj){
int verif =0;
int cpt=0;
for(int i=0;i<=64;i++){
    if(cj[i].x==0&&cj[i].y==0){
       cpt++;
    }
}
//cas ou l ia ne peut pas jouer (passe son tour)
if (cpt==64){
    verif =1;
    return verif;
}
}

//fonction qui permet la creation d'un fils avec le coup joué
Fils creation(tabDamier damier,int tour,CoupJouable cj){
    priseSandwich(damier,cj->x,cj->y,tour);

}
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