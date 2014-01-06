#ifndef __TAD_LISTE_DE_SUPER_MOT_PRIVE__
#define __TAD_LISTE_DE_SUPER_MOT_PRIVE__
#include "TADListeDeSuperMot.h"
/**
* \fn void ListeDeSuperMot_decalerADroite(ListeDeSuperMot *liste, int indice);
* \brief Décale vers la droite tous les Mot d'une Liste de SuperMot à partir d'un indice. Attention aux dépassement de mémoire
* \param ListeDeSuperMot *liste :  la liste que l'on veut modifier
* \param int indice : l'indice à partir duquel on veut faire le décalage
* \author Étienne Batise
*/
void ListeDeSuperMot_decalerADroite(ListeDeSuperMot *liste, unsigned int indice);

/**
* \fn void ListeDeSuperMot_decalerAGauche(ListeDeSuperMot *liste, int indice);
* \brief Décale vers la gauche tous les Mot d'une Liste de SuperMot à partir d'un indice. Penser à liberer la mémoire
* \param ListeDeSuperMot *liste :  la liste que l'on veut modifier
* \param int indice : l'indice à partir duquel on veut faire le décalage
* \author Étienne Batise
*/
void ListeDeSuperMot_decalerAGauche(ListeDeSuperMot *liste, unsigned int indice);

#endif