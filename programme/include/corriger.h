/**
 * \file corriger.h
 * \brief Fonctions de haut-niveau utiles pour la correction
 * \version 1.0
 */
#ifndef __CORRIGER__
#define __CORRIGER__
#include "TADDictionnaire.h"
#include "TADListeDeSuperMot.h"

/**
* \fn char* corriger(char* chaine, Dictionnaire dictionnaire);
* \brief Affiche une correction pour une chaine de caractères selon un dictionnaire 
* \param char* chaine : la chaine à corriger
* \param Dictionnaire dictionnaire : le dictionnaire
* \author
*/
void corriger(char* chaine, Dictionnaire dictionnaire);

/**
* \fn void evaluerSaisie(unsigned int* estValide, int* erreur, char* chaine);
* \brief Etudie une chaine de caractères selon plusieurs critères
* \param unsigned int* estValide : la validité de la chaine de caractères
* \param int* erreur : le type d'erreur. N'a pas de sens si estValide vaut 1
* \param char* chaine :la chaine de caractère à étudier
*/
void evaluerSaisie(unsigned int* estValide, unsigned int* erreur, char* chaine);
/**
* \fn char* lireChaine()
* \brief Lit une chaîne de caractères rentrée dans l'entrée standard. Celle-ci DOIT se terminer par un '.'
* \author Antoine Augusti
* \warning L'allocation est faites dans la fonction. La désallocation est À FAIRE
*/
char* lireChaine();

/**
* \fn void corrigerListeDeSuperMots(ListeDeSuperMot listeDeSuperMots, Dictionnaire dictionnaire);
* \brief Corrige une liste de SuperMot selon un dictionnaire
* \param ListeDeSuperMot* listeDeSuperMots : la liste de SupeMot à corriger
* \param Dictionnaire dictionnaire : le dictionnaire
*/
void corrigerListeDeSuperMots(ListeDeSuperMot* listeDeSuperMots, Dictionnaire dictionnaire);

/**
* \fn void afficherCorrection(ListeDeSuperMot listeDeSuperMots);
* \brief Crée une chaine de caractères qui sera affichée 
* \param ListeDeSuperMot listeDeSuperMots : la liste de SuperMot qui permet de construire une correction
*/
void afficherCorrection(ListeDeSuperMot listeDeSuperMots);

#endif