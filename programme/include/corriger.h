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
* \brief Affiche une correction pour une chaine de caract�res selon un dictionnaire 
* \param char* chaine : la chaine � corriger
* \param Dictionnaire dictionnaire : le dictionnaire
* \author
*/
void corriger(char* chaine, Dictionnaire dictionnaire);

/**
* \fn void evaluerSaisie(unsigned int* estValide, int* erreur, char* chaine);
* \brief Etudie une chaine de caract�res selon plusieurs crit�res
* \param unsigned int* estValide : la validit� de la chaine de caract�res
* \param int* erreur : le type d'erreur. N'a pas de sens si estValide vaut 1
* \param char* chaine :la chaine de caract�re � �tudier
*/
void evaluerSaisie(unsigned int* estValide, unsigned int* erreur, char* chaine);
/**
* \fn char* lireChaine()
* \brief Lit une cha�ne de caract�res rentr�e dans l'entr�e standard. Celle-ci DOIT se terminer par un '.'
* \author Antoine Augusti
* \warning L'allocation est faites dans la fonction. La d�sallocation est � FAIRE
*/
char* lireChaine();

/**
* \fn void corrigerListeDeSuperMots(ListeDeSuperMot listeDeSuperMots, Dictionnaire dictionnaire);
* \brief Corrige une liste de SuperMot selon un dictionnaire
* \param ListeDeSuperMot* listeDeSuperMots : la liste de SupeMot � corriger
* \param Dictionnaire dictionnaire : le dictionnaire
*/
void corrigerListeDeSuperMots(ListeDeSuperMot* listeDeSuperMots, Dictionnaire dictionnaire);

/**
* \fn void afficherCorrection(ListeDeSuperMot listeDeSuperMots);
* \brief Cr�e une chaine de caract�res qui sera affich�e 
* \param ListeDeSuperMot listeDeSuperMots : la liste de SuperMot qui permet de construire une correction
*/
void afficherCorrection(ListeDeSuperMot listeDeSuperMots);

#endif