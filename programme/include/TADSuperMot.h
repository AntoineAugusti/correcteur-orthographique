/**
 * \file TADSuperMot.h
 * \brief Implantation du TAD SuperMot avec la SDD SuperMot
 * \version 1.0
 */
#ifndef __TAD_SUPER_MOT__
#define __TAD_SUPER_MOT__
#include "TADMot.h"
#include "TADListeDeMot.h"

typedef struct {
	Mot mot;
	unsigned int position;
	ListeDeMot listeDeCorrections;
	int valide;
} SuperMot;

/**
* \fn SuperMot_superMot
* \brief initialise un superMot vide
* \return le superMot vide
* \author Faustine Demiselle
*/
SuperMot SuperMot_superMot();

/**
* \fn SuperMot_obtenirMot
* \brief obtenir le mot du superMot
* \param SuperMot superMot : le superMot dont on veut le mot
* \return le mot du superMot
* \author Faustine Demiselle
*/
Mot SuperMot_obtenirMot(SuperMot superMot);

/**
* \fn SuperMot_fixerMot
* \brief fixe mot dans superMot
* \param SuperMot superMot : le superMot à modifier
* \param Mot mot : le mot à fixer
* \return void
* \author Faustine Demiselle
*/
void SuperMot_fixerMot(SuperMot* superMot, Mot mot);

/**
* \fn SuperMot_obtenirPosition
* \brief obtenir la position affectée au superMot
* \param SuperMot superMot : le superMot dont on cherche position
* \return la position
* \author Faustine Demiselle
*/
unsigned int SuperMot_obtenirPosition(SuperMot superMot);

/**
* \fn SuperMot_fixerposition
* \brief fixe la position du superMot
* \param SuperMot superMot : le superMot à modifier
* \param unsigned int position : la position à fixer
* \return void
* \author Faustine Demiselle
*/
void SuperMot_fixerPosition(SuperMot* superMot, unsigned int position);

/**
* \fn SuperMot_obtenirListeDeCorrection
* \brief Obtenir la liste de corrections (listeDeMot) affectée à un superMot
* \param SuperMot superMot : le superMot concerné
* \return ListeDeMot
* \author Faustine Demiselle
*/
ListeDeMot SuperMot_obtenirListeDeCorrection(SuperMot superMot);

/**
* \fn SuperMot_fixerListeDeCorrections
* \brief fixe les corrections (listeDeMot) dans superMot
* \param SuperMot superMot : le superMot à modifier
* \param ListeDeMot corrections : les corrections à fixer
* \return void
* \author Faustine Demiselle
*/
void SuperMot_fixerListeDeCorrections(SuperMot* superMot, ListeDeMot corrections);

/**
* \fn SuperMot_obtenirValidite
* \brief obtien la validité du superMot
* \param SuperMot superMot : le superMot concerné
* \return int (à lire comme un booléen)
* \author Faustine Demiselle
*/
int SuperMot_obtenirValidite(SuperMot superMot);

/**
* \fn SuperMot_fixerValidite
* \brief fixe la validité du superMot
* \param SuperMot superMot : le superMot à modifier
* \param int estValide : la valeur (validité) à fixer
* \return void
* \author Faustine Demiselle
*/
void SuperMot_fixerValidite(SuperMot* superMot, int estValide);

#endif