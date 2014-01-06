#ifndef __TAD_LISTE_DE_MOT_PRIVE__
#define __TAD_LISTE_DE_MOT_PRIVE__
#include "TADListeDeMot.h"
/**
* \fn void ListeDeMot_decalerADroite(ListeDeMot *liste, int indice);
* \brief Décale vers la droite tous les Mot d'une Liste de Mot à partir d'un indice. Attention aux dépassement de mémoire
* \param ListeDeMot *liste :  la liste que l'on veut modifier
* \param int indice : l'indice à partir duquel on veut faire le décalage
* \author Étienne Batise
*/
void ListeDeMot_decalerADroite(ListeDeMot *liste, unsigned int indice);

/**
* \fn void ListeDeMot_decalerAGauche(ListeDeMot *liste, int indice);
* \brief Décale vers la gauche tous les Mot d'une Liste de Mot à partir d'un indice. Penser à liberer la mémoire
* \param ListeDeMot *liste :  la liste que l'on veut modifier
* \param int indice : l'indice à partir duquel on veut faire le décalage
* \author Étienne Batise
*/
void ListeDeMot_decalerAGauche(ListeDeMot *liste, unsigned int indice);

#endif