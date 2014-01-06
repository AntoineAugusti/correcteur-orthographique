/**
 * \file TADDictionnaire.h
 * \brief Implantation du TAD Dictionnaire avec la SDD Dictionnaire
 * \version 1.0
 */
#ifndef __TAD_DICTIONNAIRE__
#define __TAD_DICTIONNAIRE__
#include "TADElementDictionnairePrive.h"
#include "TADMot.h"
#include "TADFichierTexte.h"

typedef struct {
	unsigned int longueur;
	ElementDictionnaire racines[NB_LETTRES]; 
} Dictionnaire;

/**
 * \fn Dictionnaire Dictionnaire_dictionnaire();
 * \author Jean-Claude Bernard
 * \brief Crée un Dictionnaire
 * \return retourne un dictionnaire vide
 */
Dictionnaire Dictionnaire_dictionnaire();

/**
 * \fn unsigned int Dictionnaire_estVide(Dictionnaire dictionnaire);
 * \author Antoine Augusti
 * \brief Vérifie si un dictionnaire est vide
 * \param Dictionnaire dictionnaire : le dictionnaire que l'on veut tester
 * \return retourne un booléen (unsigned int), 1 si il est vide, 0 sinon
 */
unsigned int Dictionnaire_estVide(Dictionnaire dictionnaire);

/**
 * \fn void Dictionnaire_insererMot(Dictionnaire* dictionnaire, Mot mot);
 * \author Jean-Claude Bernard	
 * \brief Insère un mot dans un dictionnaire
 * \param Dictionnaire* dictionnaire : le dictionnaire auquel on veut insérer le mot
 * \param Mot mot : le mot que l'on veut ajouter
 */
void Dictionnaire_insererMot(Dictionnaire* dictionnaire, Mot mot);

/**
 * \fn void Dictionnaire_insererFichier(Dictionnaire* dictionnaire, char* nomFichier);
 * \author Jean-Claude Bernard
 * \brief Rempli le dictionnaire à partir d'un fichier contenant des mots
 * \param Dictionnaire* dictionnaire : le dictionnaire que l'on veut remplir
 * \param char* nomFichier : le nom du fichier à insérer
 */
void Dictionnaire_insererFichier(Dictionnaire* dictionnaire, char* nomFichier);

/**
 * \fn unsigned int Dictionnaire_estPresent(Dictionnaire dictionnaire, Mot mot);
 * \author Antoine Augusti
 * \brief Vérifier la présence d'un mot dans un dictionnaire
 * \param Dictionnaire dictionnaire : le dictionnaire que l'on veut vérifier
 * \param Mot mot : le mot à trouver
 * \return retourne un booléen
 */
unsigned int Dictionnaire_estPresent(Dictionnaire dictionnaire, Mot mot);

/**
 * \fn Dictionnaire Dictionnaire_charger(char* emplacement);
 * \author Antoine Augusti
 * \brief Charger un dictionnaire depuis un fichier texte où le dictionnaire est sérialisé
 * \param char* emplacement : le nom du fichier contenant le dictionnaire
 * \return retourne un dictionnaire
 */
Dictionnaire Dictionnaire_charger(char* emplacement);

/**
 * \fn Fichier Dictionnaire_sauvegarder(Dictionnaire dictionnaire, char* emplacement);
 * \author Jean-Claude Bernard
 * \brief Sauvegarder un dictionnaire 
 * \param Dictionnaire dictionnaire : le dictionnaire à sauvegarder
 * \param char* emplacement : le nom du fichier dans lequel on veut sauver le dictionnaire
 * \return retourne un fichier
 */
Fichier Dictionnaire_sauvegarder(Dictionnaire dictionnaire, char* emplacement);

#endif