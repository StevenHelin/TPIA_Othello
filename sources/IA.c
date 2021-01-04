/**
 * HELIN Steven
 * DEWAGHE Guillaume
 * TP d'IA
 * M1TNSID
 */

#include "../header.h"


/**
 * @paragraph Fonction qui crée un noeud
 * @param damier : Plateau de jeu
 */
Noeud* Creation (tabDamier damier){
    Noeud* nouveau;
    nouveau = (Noeud*) malloc (sizeof(Noeud));
    return nouveau;
}


/**
 * @paragraph Fonction qui detecte si un coup est possible, si ou rempli un tableau de coordonnées
 * @param damier : Plateau de jeu
 * @param cj : tableau de structure qui stock les coordonnées d'un coup jouable
 * @param jo : couleur du joueur
 */
int detectionPossible (tabDamier damier, CoupJouable cj,char jo){
    for (int i = 0; i < 64; i++) {
        cj[i].x=-1;
        cj[i].y=-1;
    }
    int possible=0;
    int k=0;
    for (int  i = 0; i<8 ;i++ ) {
        for (int j=0;j<8;j++){
            possible = detection(damier,jo,i,j);
            if (possible==1){
                cj[k].x=i;
                cj[k].y=j;
                k++;
              }
            possible=0;
        }
    }
    return k;
}


/**Fonction qui permet d'instancier un noeud fils
 */
Fils* instancier(){
   Fils* nouveau;
   nouveau = (Fils*) malloc (sizeof(Fils));
   if (nouveau) {
       nouveau->succ = NULL;
       nouveau->suiv = NULL;
   }
    return nouveau;
}

/**
 * @paragraph fonction qui permet la creation d'un fils avec le coup joué
 * @param damier : Plateau de jeu
 * @param tour : variable contenant le tour actuel
 * @param cj : tableau de structure qui stock les coordonnées d'un coup jouable
 * @param indice : donne la position dans le tableau de coup a jouer
 */
Noeud* creationf(tabDamier damier,int tour,CoupJouable cj, int indice){
    Noeud* nouveau = Creation (damier);
    for (int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            nouveau->damier[i][j].couleur=damier[i][j].couleur;
            nouveau->damier[i][j].score=damier[i][j].score;
        }
    }
    /*for (int i = 0; i < 64; i++) {
        printf("%d %d\n",cj[i],cj[i]);
    }
    printf("prise %d : %d %d\n",indice,cj[indice],cj[indice]);*/
    priseSandwich(nouveau->damier,cj[indice].x,cj[indice].y,tour);
    return nouveau;
}

/**
 * @paragraph fonction qui permet de trouver le minimum pour l'algo min max
 * @param fils : noeud actuel avec un coup joué
 */
int min(Fils* fils){
    int min=64;
    Fils* courant;
    courant =fils;
    while (courant!=NULL){
        if( courant->succ->score<min){
            min= courant->succ->score;
        }
        courant=courant->suiv;
    }
    return min;
}

/**
 * @paragraph fonction qui permet de trouver le maximum pour l'algo min max
 * @param fils : noeud actuel avec un coup joué
 */
int max(Fils* fils){
    int max=-64;
    Fils* courant;
    courant =fils;
    while (courant!=NULL){
        if( courant->succ->score>max){
           max= courant->succ->score;
        }
        courant=courant->suiv;
    }
    return max;
}

/**
 * @paragraph fonction qui gere majoritairement le fonctionnement de l'IA
 * @param damier : Plateau de jeu
 * @param tour : variable contenant le tour actuel
 * @param cj : tableau de structure qui stock les coordonnées d'un coup jouable
 * @param indice : donne la position dans le tableau de coup a jouer
 * @param profondeur : permet de regler la profondeur de L'IA
 * @param couleur : garde une couleur fixe comme repere
 */
Noeud* IA (tabDamier damier,CoupJouable cj, char jo, int tour, char couleur,int profondeur,int indice){

    Noeud* nouveau;
    Fils* courant;
    int cv,cb,cn;
    int score=0;
    int coupPossible=0;
    if (indice==-1){
        nouveau = Creation(damier);
        for (int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                nouveau->damier[i][j].couleur=damier[i][j].couleur;
                nouveau->damier[i][j].score=damier[i][j].score;
            }
        }
    }else{
        nouveau = creationf(damier,tour,cj,indice);
    }
    if(jo=='B'){//IA est blanc
        jo='N';
    }
    else{
        jo='B';
    }
    calculCases(damier,&cv,&cb,&cn);
    if(cv==0 || profondeur>=2){//on est en victoire
        //printf("feuille\n");
        if(couleur=='B'){//IA est blanc
            nouveau->score=cb-cn;
        }
        else{
            nouveau->score=cn-cb;
        }
    }
    else{
        coupPossible=detectionPossible(damier,cj,jo);
        if(coupPossible==0){//passe le tour
            if(couleur=='B'){//IA est blanc
                coupPossible=detectionPossible(damier,cj,'N');
            }
            else{
                coupPossible=detectionPossible(damier,cj,'B');
            }
            if(coupPossible==0){//aucun joueur ne peut jouer
                if(couleur=='B'){//IA est blanc
                    nouveau->score=cb-cn;
                }
                else{
                    nouveau->score=cn-cb;
                }

            }
            else{//l'autre joueur peut jouer
                nouveau->succ=instancier();
                nouveau->succ->succ=IA(nouveau->damier,cj,jo,tour+1,couleur,profondeur+1,-1);
                nouveau->score=nouveau->succ->succ->score;
             }
        }
        else{
            nouveau->succ=instancier();
            courant=nouveau->succ;
            courant->succ=IA(nouveau->damier,cj,jo,tour+1,couleur,profondeur+1,0);
            int i=1;
            while(cj[i].x!=-1){
                courant->suiv=instancier();
                courant=courant->suiv;
                courant->succ=IA(nouveau->damier,cj,jo,tour+1,couleur,profondeur+1,i);
                i++;
            }
            if (couleur==jo){
                nouveau->score=max(nouveau->succ);
            }
            else{
                nouveau->score=min(nouveau->succ);
            }
        }

    }
    return nouveau;
}


/**
 * @paragraph fonction qui selectionne le meilleur coup a jouer
 * @param n : noeud actuel
 */
Coord meilleurCoup (Noeud* n){
    Fils* courant;
    Coord nouveau;
    nouveau.x=-1;
    nouveau.y=-1;
    courant=n->succ;
    while(n->score!=courant->succ->score && courant!=NULL){
        courant=courant->suiv;
    }
    if(courant==NULL){
        printf("error\n");
    }else{
        /*affichageDamier(n->damier);
        affichageDamier(courant->succ->damier);*/
        for(int i=0;i<8;i++){
            for (int j = 0; j < 8; j++) {
                if(n->damier[i][j].couleur==' ' && n->damier[i][j].couleur!=courant->succ->damier[i][j].couleur){
                    nouveau.x=i;
                    nouveau.y=j;
                }

            }
        }
    }
    return nouveau;
}
