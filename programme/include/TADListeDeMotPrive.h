#ifndef __TAD_LISTE_DE_MOT_PRIVE__
#define __TAD_LISTE_DE_MOT_PRIVE__
#include "TADListeDeMot.h"
/**
* \fn void ListeDeMot_decalerADroite(ListeDeMot *liste, int indice);
* \brief D�cale vers la droite tous les Mot d'une Liste de Mot � partir d'un indice. Attention aux d�passement de m�moire
* \param ListeDeMot *liste :  la liste que l'on veut modifier
* \param int indice : l'indice � partir duquel on veut faire le d�calage
* \author �tienne Batise
*/
void ListeDeMot_decalerADroite(ListeDeMot *liste, unsigned int indice);

/**
* \fn void ListeDeMot_decalerAGauche(ListeDeMot *liste, int indice);
* \brief D�cale vers la gauche tous les Mot d'une Liste de Mot � partir d'un indice. Penser � liberer la m�moire
* \param ListeDeMot *liste :  la liste que l'on veut modifier
* \param int indice : l'indice � partir duquel on veut faire le d�calage
* \author �tienne Batise
*/
void ListeDeMot_decalerAGauche(ListeDeMot *liste, unsigned int indice);

#endif