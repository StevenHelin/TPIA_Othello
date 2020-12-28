/**
 * HELIN Steven
 * DEWAGHE Guillaume
 * TP d'IA
 * M1TNSID
 */

#ifndef OTHELLO_HEADER_H
#define OTHELLO_HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <process.h>
#include <limits.h>

/*----- STRUCTURES -----*/

/**
 * @paragraph Structure pour les pions,
 * chaque pion possède un score et une couleur(B, N ou ' ')
 */
typedef struct
{
    int score;
    char couleur;
} Pion;

/**
 * @paragraph tadDamier représente le plateau de jeu de l'Othello,
 * il peut contenir les valeurs suivantes :
 * @var ' ', 'B', 'N'
 */
typedef Pion tabDamier[8][8];

/**
 * @paragraph Liste correspondant aux noeuds pour l'IA
 */
typedef struct _Noeud
{
    int score;
    struct _Noeud *suiv;
} Noeud;

/*----- STRUCTURES -----*/

/*----- damier.c -----*/

void iniDamier(tabDamier td);
void affichageDamier(tabDamier td);
void calculCases(tabDamier td, int *cv, int *cb, int *cn);

/*----- damier.c -----*/

/*----- deplacement.c -----*/

int convLigne(int *i);
int convCharToInt(char c);
void saisie(tabDamier td, int *x, int *y, int tour, int cv, int cb, int cn);

/*----- deplacement.c -----*/

/*----- detection.c -----*/

int detection(tabDamier td,char jo, int x, int y);

/*----- detection.c -----*/

/*----- prise.c -----*/

void priseSandwich(tabDamier td, int x, int y, int tour );

/*----- prise.c -----*/

/*----- IA.c -----*/

int evaluer(Noeud n);
bool estTerminal(Noeud n);
int maxValue(Noeud n);
int minValue(Noeud n);

/*----- IA.c -----*/

#endif //OTHELLO_HEADER_H
