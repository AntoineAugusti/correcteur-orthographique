/**
 * \file TADListeDeSuperMot.h
 * \brief Implantation du TAD ListeDeSuperMot avec la SDD ListeDeSuperMot
 * \version 1.0
 */
#ifndef __TAD_LISTE_DE_SUPER_MOT__
#define __TAD_LISTE_DE_SUPER_MOT__
#include "TADSuperMot.h"

typedef struct ListeDeSuperMot{
	SuperMot* tableau;
	unsigned int longueur;
} ListeDeSuperMot;

/**
* \fn ListeDeSuperMot TADListeDeSuperMot_liste();
* \brief Cr�e une Liste de SuperMot initialis�e
* \return une ListeDeSuperMot 
* \author �tienne Batise
*/
ListeDeSuperMot ListeDeSuperMot_liste();

/**
* \fn int ListeDeSuperMot_estVide(ListeDeSuperMot liste); 
* \brief Permet de savoir si une Liste de SuperMot ne contient aucun SuperMot
* \param ListeDeSuperMot liste : la liste � �tudier
* \return int : vrai si elle ne contient rien, faux sinon
* \author �tienne Batise
*/
int ListeDeSuperMot_estVide(ListeDeSuperMot liste);

/**
* \fn int ListeDeSuperMot_longueur(ListeDeSuperMot liste);
* \brief Renvoi la longueur d'une Liste de SuperMot
* \param ListeDeSuperMot liste : la liste � �tudier 
* \return int : La longueur de la Liste de SuperMot
* \author �tienne Batise
*/
unsigned int ListeDeSuperMot_longueur(ListeDeSuperMot liste);

/**
* \fn void ListeDeSuperMot_ajouter(ListeDeSuperMot *liste, SuperMot mot);
* \brief Ajoute un Mot � la fin d'une liste de SuperMot
* \param ListeDeSuperMot *liste : le pointeur de la liste � laquelle on veut ajouter un SuperMot
* \param SuperMot superMot : le SuperMot que l'on veut ajouter
* \author �tienne Batise
*/
void ListeDeSuperMot_ajouter(ListeDeSuperMot *liste, SuperMot superMot);

/**
* \fn Mot ListeDeSuperMot_obtenirMot(ListeDeSuperMot liste, int indice);
* \brief Renvoi le SuperMot de la liste � un indice donn�
* \param ListeDeSuperMot liste : la liste � fouiller
* \param int indice : l'indice auquel on souhaite r�cup�rer le SuperMot
* \return SuperMot : le SuperMot trouv�
* \author �tienne Batise
* \warning assert(1 <= indice && indice <= ListeDeSuperMot_longueur(liste));
*/
SuperMot ListeDeSuperMot_obtenir(ListeDeSuperMot liste,unsigned int indice);

/**
* \fn void ListeDeSuperMot_inserer(ListeDeSuperMot *liste, SuperMot superMot, int i);
* \brief Inserer un SuperMot dans la liste � un indice donn�
* \param ListeDeSuperMot liste : la liste que l'on veut modifier
* \param SuperMot superMot : le Supermot que l'on veut inserer
* \param int indice : l'indice auquel on souhaite inserer le Supermot
* \author �tienne Batise
* \warning assert(1 <= indice && indice <= ListeDeSuperMot_longueur(*liste) + 1);
*/
void ListeDeSuperMot_inserer(ListeDeSuperMot *liste, SuperMot superMot, unsigned int i);

/**
* \fn void ListeDeSuperMot_supprimer(ListeDeSuperMot *liste, SueprMot superMot, int i);
* \brief Supprime un SuperMot dans la liste � un indice donn�
* \param ListeDeSuperMot liste : la liste que l'on veut modifier
* \param SuperMot superMot : le SuperMot que l'on veut inserer
* \param int indice : l'indice auquel on souhaite supprimer le Supermot
* \author �tienne Batise
* \warning assert(1 <= indice && indice <= ListeDeSuperMot_longueur(liste));
*/
void ListeDeSuperMot_supprimer(ListeDeSuperMot *liste, unsigned int i);

/**
* \fn void ListeDeSuperMot_liberer(ListeDeMot *liste);
* \brief Lib�re la m�moire d'une liste de super mots
* \param ListeDeSuperMot liste : La liste en question
* \author �tienne Batise
*/
void ListeDeSuperMot_liberer(ListeDeSuperMot *liste);
#endif