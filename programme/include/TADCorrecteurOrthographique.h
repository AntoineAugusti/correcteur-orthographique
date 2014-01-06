/**
 * \file TADCorrecteurOrthographique.h
 * \brief Partie privée : implantation du TAD CorrecteurOrthographique avec la SDD CorrecteurOrthographique
 * \version 1.0
 */
#ifndef __TAD_CORRECTEUR_ORTHOGRAPHIQUE__
#define __TAD_CORRECTEUR_ORTHOGRAPHIQUE__
#include "TADMot.h"
#include "TADDictionnaire.h"
#include "TADListeDeMot.h"

/**
 * \fn ListeDeMot CorrecteurOrthographique_proposerMots(Dictionnaire dictionnaire, Mot mot);
 * \brief Récupère des corrections pour un mot
 * \param Mot mot : Le mot à corriger
 * \return Retourne une liste de mots correspondant aux corrections trouvées pour le paramètre
 * \author Étienne Batise
 */
ListeDeMot CorrecteurOrthographique_proposerMots(Dictionnaire dictionnaire, Mot mot);
#endif