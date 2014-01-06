/**
 * \file LMSuperMot.h
 * \brief Fonctions de la logique métier qui utilisent les SuperMot
 * \version 1.0
 */
#ifndef __LOGIQUEMETIERSUPERMOT__
#define __LOGIQUEMETIERSUPERMOT__
#include "TADListeDeSuperMot.h"
#include "TADListeDeSuperMot.h"
#include "TADDictionnaire.h"

/**
* \fn ListeDeSuperMot genererListeDeSuperMots(*char chaine, Dictionnaire dictionnaire)
* \brief génère, a partir d'une chaine de caractère (de mots) une liste de Super mot
* \param char* chaine : la chaine à corriger
* \param Dictionnaire dictionnaire : le dictionnaire
* \return une liste de super mot valide et de super mot à corriger
* \author Jean-Claude Bernard
*/
ListeDeSuperMot genererListeDeSuperMots(char* chaine, Dictionnaire dictionnaire);

/**
* \fn ListeDeSuperMot separerMots(*char chaine)
* \brief sépare les mots d'une chaine de caractère et les renvoie sous forme de super mot
* \param char* chaine : la chaine à corriger 
* \return une liste de super mot 
* \author Jean-Claude Bernard
*/
ListeDeSuperMot separerMots(char* chaine, Dictionnaire dictionnaire);

/**
* \fn void verifieValidite(*ListeDeSuperMot listeDeSuperMots, Dictionnaire dictionnaire)
* \brief vérifie si un mot est dans un dictionnaire 
* \param *ListeDeSuperMot listeDeSuperMots : liste des super mots à vérifier
* \param Dictionnaire dictionnaire : le dictionnaire
* \author Jean-Claude Bernard
*/
int verifieValidite(Mot mot, Dictionnaire dictionnaire);

#endif