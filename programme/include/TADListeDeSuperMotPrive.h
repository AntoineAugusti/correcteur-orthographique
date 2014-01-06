#ifndef __TAD_LISTE_DE_SUPER_MOT_PRIVE__
#define __TAD_LISTE_DE_SUPER_MOT_PRIVE__
#include "TADListeDeSuperMot.h"
/**
* \fn void ListeDeSuperMot_decalerADroite(ListeDeSuperMot *liste, int indice);
* \brief D�cale vers la droite tous les Mot d'une Liste de SuperMot � partir d'un indice. Attention aux d�passement de m�moire
* \param ListeDeSuperMot *liste :  la liste que l'on veut modifier
* \param int indice : l'indice � partir duquel on veut faire le d�calage
* \author �tienne Batise
*/
void ListeDeSuperMot_decalerADroite(ListeDeSuperMot *liste, unsigned int indice);

/**
* \fn void ListeDeSuperMot_decalerAGauche(ListeDeSuperMot *liste, int indice);
* \brief D�cale vers la gauche tous les Mot d'une Liste de SuperMot � partir d'un indice. Penser � liberer la m�moire
* \param ListeDeSuperMot *liste :  la liste que l'on veut modifier
* \param int indice : l'indice � partir duquel on veut faire le d�calage
* \author �tienne Batise
*/
void ListeDeSuperMot_decalerAGauche(ListeDeSuperMot *liste, unsigned int indice);

#endif