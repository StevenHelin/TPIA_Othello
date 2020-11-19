//
// Created by Guill on 05/11/2020.
//

#ifndef OTHELLO_HEADER_H
#define OTHELLO_HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <process.h>

/**
 * tadDamier représente le plateau de jeu de l'Othello
 * Il peut contenir des espaces vides, des pièces noires ou blanches
 */

typedef struct
{
    int score;
    char couleur;
} Pion;

typedef Pion tabDamier[8][8];

void iniDamier(tabDamier td);
void affichageDamier(tabDamier td);

#endif //OTHELLO_HEADER_H
