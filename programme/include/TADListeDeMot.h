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
* \brief Cr�e une Liste de Mot initialis�e
* \return une ListeDeMot 
* \author �tienne Batise
*/
ListeDeMot ListeDeMot_liste();

/**
* \fn int ListeDeMot_estVide(ListeDeMot liste); 
* \brief Permet de savoir si une Liste de Mot ne contient aucun Mot
* \param ListeDeMot liste : la liste � �tudier
* \return int : vrai si elle ne contient rien, faux sinon
* \author �tienne Batise
*/
int ListeDeMot_estVide(ListeDeMot liste);

/**
* \fn int ListeDeMot_longueur(ListeDeMot liste);
* \brief Renvoi la longueur d'une Liste de Mot
* \param ListeDeMot liste : la liste � �tudier 
* \return int : La longueur de la Liste de Mot
* \author �tienne Batise
*/
unsigned int ListeDeMot_longueur(ListeDeMot liste);

/**
* \fn void ListeDeMot_ajouter(ListeDeMot *liste, Mot mot);
* \brief Ajoute un Mot � la fin d'une liste de Mot
* \param ListeDeMot *liste : le pointeur de la liste � laquelle on veut ajouter un mot
* \param Mot mot : le mot que l'on veut ajouter
* \author �tienne Batise
*/
void ListeDeMot_ajouter(ListeDeMot *liste, Mot mot);

/**
* \fn Mot ListeDeMot_obtenirMot(ListeDeMot liste, int indice);
* \brief Renvoi le Mot de la liste � un indice donn�
* \param ListeDeMot liste : la liste � fouiller
* \param int indice : l'indice auquel on souhaite r�cup�rer le mot
* \return Mot : le Mot trouv�
* \author �tienne Batise
* \warning assert(1 <= indice && indice <= ListeDeMot_longueur(liste));
*/
Mot ListeDeMot_obtenir(ListeDeMot liste, unsigned int indice);

/**
* \fn void ListeDeMot_inserer(ListeDeMot *liste, Mot mot, int i);
* \brief Inserer un Mot dans la liste � un indice donn�
* \param ListeDeMot liste : la liste que l'on veut modifier
* \param Mot mot : le mot que l'on veut ins�rer
* \param int indice : l'indice auquel on souhaite ins�rer le mot
* \author �tienne Batise
* \warning assert(1 <= indice && indice <= ListeDeMot_longueur(*liste) + 1);
*/
void ListeDeMot_inserer(ListeDeMot *liste, Mot mot, unsigned int i);

/**
* \fn void ListeDeMot_supprimer(ListeDeMot *liste, Mot mot, int i);
* \brief Supprime un Mot dans la liste � un indice donn�
* \param ListeDeMot liste : la liste que l'on veut modifier
* \param Mot mot : le mot que l'on veut ins�rer
* \param int indice : l'indice auquel on souhaite supprimer le mot
* \author �tienne Batise
* \warning assert(1 <= indice && indice <= ListeDeMot_longueur(liste));
*/
void ListeDeMot_supprimer(ListeDeMot *liste, unsigned int i);

/**
* \fn char* ListeDeMot_listeDeMotEnChaine(ListeDeMot liste);
* \brief Recup�re un chaine de caract�re remplie des mots d'une liste s�par�s par des espace
* \param ListeDeMot liste : La liste � partir de laquelle on veut r�cup�rer la chaine
* \return char* : la chaine refaite
* \warning : Le chaine est allou�e dynamiquement. Il faut donc penser � la lib�rer apr�s utilisation.
* \author �tienne Batise
*/
void ListeDeMot_listeDeMotEnChaine(ListeDeMot liste);

/**
* \fn void ListeDeMot_liberer(ListeDeMot *liste);
* \brief Lib�re la m�moire d'une liste de mots
* \param ListeDeMot liste : La liste en question
* \author �tienne Batise
*/
void ListeDeMot_liberer(ListeDeMot *liste);

/**
* \fn unsigned int ListeDeMot_estPresent(ListeDeMot liste, Mot mot);
* \brief D�termine si un mot est pr�sent dans une liste de mot
* \param ListeDeMot liste : La liste en question
* \param Mot mot : le mot en question
* \return unsigned int : 1 si le mot est pr�sent dans la liste, 0 sinon
* \author �tienne Batise
*/
unsigned int ListeDeMot_estPresent(ListeDeMot liste, Mot mot);
#endif