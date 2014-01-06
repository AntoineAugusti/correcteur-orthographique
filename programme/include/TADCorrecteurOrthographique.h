/**
 * \file TADCorrecteurOrthographique.h
 * \brief Partie priv�e : implantation du TAD CorrecteurOrthographique avec la SDD CorrecteurOrthographique
 * \version 1.0
 */
#ifndef __TAD_CORRECTEUR_ORTHOGRAPHIQUE__
#define __TAD_CORRECTEUR_ORTHOGRAPHIQUE__
#include "TADMot.h"
#include "TADDictionnaire.h"
#include "TADListeDeMot.h"

/**
 * \fn ListeDeMot CorrecteurOrthographique_proposerMots(Dictionnaire dictionnaire, Mot mot);
 * \brief R�cup�re des corrections pour un mot
 * \param Mot mot : Le mot � corriger
 * \return Retourne une liste de mots correspondant aux corrections trouv�es pour le param�tre
 * \author �tienne Batise
 */
ListeDeMot CorrecteurOrthographique_proposerMots(Dictionnaire dictionnaire, Mot mot);
#endif