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
* \param SuperMot superMot : le superMot � modifier
* \param Mot mot : le mot � fixer
* \return void
* \author Faustine Demiselle
*/
void SuperMot_fixerMot(SuperMot* superMot, Mot mot);

/**
* \fn SuperMot_obtenirPosition
* \brief obtenir la position affect�e au superMot
* \param SuperMot superMot : le superMot dont on cherche position
* \return la position
* \author Faustine Demiselle
*/
unsigned int SuperMot_obtenirPosition(SuperMot superMot);

/**
* \fn SuperMot_fixerposition
* \brief fixe la position du superMot
* \param SuperMot superMot : le superMot � modifier
* \param unsigned int position : la position � fixer
* \return void
* \author Faustine Demiselle
*/
void SuperMot_fixerPosition(SuperMot* superMot, unsigned int position);

/**
* \fn SuperMot_obtenirListeDeCorrection
* \brief Obtenir la liste de corrections (listeDeMot) affect�e � un superMot
* \param SuperMot superMot : le superMot concern�
* \return ListeDeMot
* \author Faustine Demiselle
*/
ListeDeMot SuperMot_obtenirListeDeCorrection(SuperMot superMot);

/**
* \fn SuperMot_fixerListeDeCorrections
* \brief fixe les corrections (listeDeMot) dans superMot
* \param SuperMot superMot : le superMot � modifier
* \param ListeDeMot corrections : les corrections � fixer
* \return void
* \author Faustine Demiselle
*/
void SuperMot_fixerListeDeCorrections(SuperMot* superMot, ListeDeMot corrections);

/**
* \fn SuperMot_obtenirValidite
* \brief obtien la validit� du superMot
* \param SuperMot superMot : le superMot concern�
* \return int (� lire comme un bool�en)
* \author Faustine Demiselle
*/
int SuperMot_obtenirValidite(SuperMot superMot);

/**
* \fn SuperMot_fixerValidite
* \brief fixe la validit� du superMot
* \param SuperMot superMot : le superMot � modifier
* \param int estValide : la valeur (validit�) � fixer
* \return void
* \author Faustine Demiselle
*/
void SuperMot_fixerValidite(SuperMot* superMot, int estValide);

#endif