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
* \brief Crée une Liste de SuperMot initialisée
* \return une ListeDeSuperMot 
* \author Étienne Batise
*/
ListeDeSuperMot ListeDeSuperMot_liste();

/**
* \fn int ListeDeSuperMot_estVide(ListeDeSuperMot liste); 
* \brief Permet de savoir si une Liste de SuperMot ne contient aucun SuperMot
* \param ListeDeSuperMot liste : la liste à étudier
* \return int : vrai si elle ne contient rien, faux sinon
* \author Étienne Batise
*/
int ListeDeSuperMot_estVide(ListeDeSuperMot liste);

/**
* \fn int ListeDeSuperMot_longueur(ListeDeSuperMot liste);
* \brief Renvoi la longueur d'une Liste de SuperMot
* \param ListeDeSuperMot liste : la liste à étudier 
* \return int : La longueur de la Liste de SuperMot
* \author Étienne Batise
*/
unsigned int ListeDeSuperMot_longueur(ListeDeSuperMot liste);

/**
* \fn void ListeDeSuperMot_ajouter(ListeDeSuperMot *liste, SuperMot mot);
* \brief Ajoute un Mot à la fin d'une liste de SuperMot
* \param ListeDeSuperMot *liste : le pointeur de la liste à laquelle on veut ajouter un SuperMot
* \param SuperMot superMot : le SuperMot que l'on veut ajouter
* \author Étienne Batise
*/
void ListeDeSuperMot_ajouter(ListeDeSuperMot *liste, SuperMot superMot);

/**
* \fn Mot ListeDeSuperMot_obtenirMot(ListeDeSuperMot liste, int indice);
* \brief Renvoi le SuperMot de la liste à un indice donné
* \param ListeDeSuperMot liste : la liste à fouiller
* \param int indice : l'indice auquel on souhaite récupérer le SuperMot
* \return SuperMot : le SuperMot trouvé
* \author Étienne Batise
* \warning assert(1 <= indice && indice <= ListeDeSuperMot_longueur(liste));
*/
SuperMot ListeDeSuperMot_obtenir(ListeDeSuperMot liste,unsigned int indice);

/**
* \fn void ListeDeSuperMot_inserer(ListeDeSuperMot *liste, SuperMot superMot, int i);
* \brief Inserer un SuperMot dans la liste à un indice donné
* \param ListeDeSuperMot liste : la liste que l'on veut modifier
* \param SuperMot superMot : le Supermot que l'on veut inserer
* \param int indice : l'indice auquel on souhaite inserer le Supermot
* \author Étienne Batise
* \warning assert(1 <= indice && indice <= ListeDeSuperMot_longueur(*liste) + 1);
*/
void ListeDeSuperMot_inserer(ListeDeSuperMot *liste, SuperMot superMot, unsigned int i);

/**
* \fn void ListeDeSuperMot_supprimer(ListeDeSuperMot *liste, SueprMot superMot, int i);
* \brief Supprime un SuperMot dans la liste à un indice donné
* \param ListeDeSuperMot liste : la liste que l'on veut modifier
* \param SuperMot superMot : le SuperMot que l'on veut inserer
* \param int indice : l'indice auquel on souhaite supprimer le Supermot
* \author Étienne Batise
* \warning assert(1 <= indice && indice <= ListeDeSuperMot_longueur(liste));
*/
void ListeDeSuperMot_supprimer(ListeDeSuperMot *liste, unsigned int i);

/**
* \fn void ListeDeSuperMot_liberer(ListeDeMot *liste);
* \brief Libère la mémoire d'une liste de super mots
* \param ListeDeSuperMot liste : La liste en question
* \author Étienne Batise
*/
void ListeDeSuperMot_liberer(ListeDeSuperMot *liste);
#endif