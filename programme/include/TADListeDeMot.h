/**
 * \file TADListeDeMot.h
 * \brief Implantation du TAD ListeDeMot avec la SDD ListeDeMot
 * \version 1.0
 */
#ifndef __TAD_LISTE_DE_MOT__
#define __TAD_LISTE_DE_MOT__
#include "TADMot.h"

typedef struct ListeDeMot{
	Mot* tableau;
	unsigned int longueur;
} ListeDeMot;

/**
* \fn ListeDeMot ListeDeMot_liste();
* \brief Crée une Liste de Mot initialisée
* \return une ListeDeMot 
* \author Étienne Batise
*/
ListeDeMot ListeDeMot_liste();

/**
* \fn int ListeDeMot_estVide(ListeDeMot liste); 
* \brief Permet de savoir si une Liste de Mot ne contient aucun Mot
* \param ListeDeMot liste : la liste à étudier
* \return int : vrai si elle ne contient rien, faux sinon
* \author Étienne Batise
*/
int ListeDeMot_estVide(ListeDeMot liste);

/**
* \fn int ListeDeMot_longueur(ListeDeMot liste);
* \brief Renvoi la longueur d'une Liste de Mot
* \param ListeDeMot liste : la liste à étudier 
* \return int : La longueur de la Liste de Mot
* \author Étienne Batise
*/
unsigned int ListeDeMot_longueur(ListeDeMot liste);

/**
* \fn void ListeDeMot_ajouter(ListeDeMot *liste, Mot mot);
* \brief Ajoute un Mot à la fin d'une liste de Mot
* \param ListeDeMot *liste : le pointeur de la liste à laquelle on veut ajouter un mot
* \param Mot mot : le mot que l'on veut ajouter
* \author Étienne Batise
*/
void ListeDeMot_ajouter(ListeDeMot *liste, Mot mot);

/**
* \fn Mot ListeDeMot_obtenirMot(ListeDeMot liste, int indice);
* \brief Renvoi le Mot de la liste à un indice donné
* \param ListeDeMot liste : la liste à fouiller
* \param int indice : l'indice auquel on souhaite récupérer le mot
* \return Mot : le Mot trouvé
* \author Étienne Batise
* \warning assert(1 <= indice && indice <= ListeDeMot_longueur(liste));
*/
Mot ListeDeMot_obtenir(ListeDeMot liste, unsigned int indice);

/**
* \fn void ListeDeMot_inserer(ListeDeMot *liste, Mot mot, int i);
* \brief Inserer un Mot dans la liste à un indice donné
* \param ListeDeMot liste : la liste que l'on veut modifier
* \param Mot mot : le mot que l'on veut insérer
* \param int indice : l'indice auquel on souhaite insérer le mot
* \author Étienne Batise
* \warning assert(1 <= indice && indice <= ListeDeMot_longueur(*liste) + 1);
*/
void ListeDeMot_inserer(ListeDeMot *liste, Mot mot, unsigned int i);

/**
* \fn void ListeDeMot_supprimer(ListeDeMot *liste, Mot mot, int i);
* \brief Supprime un Mot dans la liste à un indice donné
* \param ListeDeMot liste : la liste que l'on veut modifier
* \param Mot mot : le mot que l'on veut insérer
* \param int indice : l'indice auquel on souhaite supprimer le mot
* \author Étienne Batise
* \warning assert(1 <= indice && indice <= ListeDeMot_longueur(liste));
*/
void ListeDeMot_supprimer(ListeDeMot *liste, unsigned int i);

/**
* \fn char* ListeDeMot_listeDeMotEnChaine(ListeDeMot liste);
* \brief Recupère un chaine de caractère remplie des mots d'une liste séparés par des espace
* \param ListeDeMot liste : La liste à partir de laquelle on veut récupérer la chaine
* \return char* : la chaine refaite
* \warning : Le chaine est allouée dynamiquement. Il faut donc penser à la libérer après utilisation.
* \author Étienne Batise
*/
void ListeDeMot_listeDeMotEnChaine(ListeDeMot liste);

/**
* \fn void ListeDeMot_liberer(ListeDeMot *liste);
* \brief Libère la mémoire d'une liste de mots
* \param ListeDeMot liste : La liste en question
* \author Étienne Batise
*/
void ListeDeMot_liberer(ListeDeMot *liste);

/**
* \fn unsigned int ListeDeMot_estPresent(ListeDeMot liste, Mot mot);
* \brief Détermine si un mot est présent dans une liste de mot
* \param ListeDeMot liste : La liste en question
* \param Mot mot : le mot en question
* \return unsigned int : 1 si le mot est présent dans la liste, 0 sinon
* \author Étienne Batise
*/
unsigned int ListeDeMot_estPresent(ListeDeMot liste, Mot mot);
#endif