//
// Created by Guill on 05/11/2020.
//

#ifndef OTHELLO_HEADER_H
#define OTHELLO_HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <process.h>

/**
 * Structure pour les pions
 * Chaque pion possède un score et une couleur(B, N ou ' ')
 */
typedef struct
{
    int score;
    char couleur;
} Pion;

/**
 * tadDamier représente le plateau de jeu de l'Othello
 * Il peut contenir des espaces vides, des pièces noires ou blanches
 */
typedef Pion tabDamier[8][8];

/*----- damier.c -----*/

void iniDamier(tabDamier td);
void affichageDamier(tabDamier td);

/*----- damier.c -----*/

/*----- deplacement.c -----*/

int convLigne(int i);
int convCharToInt(char c);
void saisie(tabDamier td, char jo);
bool detectionLigne(tabDamier td, char jo, int x, int y);
bool detectionColonne(tabDamier td, char jo, int x, int y);

/*----- deplacement.c -----*/

#endif //OTHELLO_HEADER_H
