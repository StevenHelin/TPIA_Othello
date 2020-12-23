//
// Created by Guill on 05/11/2020.
//

#ifndef OTHELLO_HEADER_H
#define OTHELLO_HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <process.h>

/**
 * Structure pour les pions,
 * chaque pion possède un score et une couleur(B, N ou ' ')
 */
typedef struct
{
    int score;
    char couleur;
} Pion;

/**
 * tadDamier représente le plateau de jeu de l'Othello,
 * il peut contenir les valeurs suivantes :
 * @var ' '
 * @var 'B'
 * @var 'N'
 */
typedef Pion tabDamier[8][8];

/*----- damier.c -----*/

void iniDamier(tabDamier td);
void affichageDamier(tabDamier td);

/*----- damier.c -----*/

/*----- deplacement.c -----*/

int convLigne(int *i);
int convCharToInt(char c);
void saisie(tabDamier td, int *x, int *y, int tour);

/*----- deplacement.c -----*/

/*----- detection.c -----*/

int detection(tabDamier td,char jo, int x, int y);

/*----- detection.c -----*/

/*----- prise.c -----*/

void priseSandwich(tabDamier td, int x, int y, int tour );

/*----- prise.c -----*/

#endif //OTHELLO_HEADER_H
