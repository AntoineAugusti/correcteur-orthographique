#ifndef __CORRECTEUR_ORTHOGRAPHIQUE_PRIVE__
#define __CORRECTEUR_ORTHOGRAPHIQUE_PRIVE__
#include "TADMot.h"
#include "TADDictionnaire.h"
#include "TADListeDeMot.h"

/**
* \fn ListeDeMot CorrecteurOrthographique_possibiltesMot(Mot mot);
* \brief R�cup�re des mots pouvant �tre construit � partir d'un mot
* \param Mot mot : le mot en question
* \return ListeDeMot
* \author �tienne Batise
*/
ListeDeMot CorrecteurOrthographique_possibilitesMots(Mot mot);
/**
* \fn ListeDeMot CorrecteurOrthographique_genererMotsParSuprresion(Mot mot);
* \brief R�cup�re des mots pouvant �tre construit � partir d'un mot en enlevant une lettre
* \param Mot mot : le mot en question
* \return ListeDeMot
* \author �tienne Batise
*/
ListeDeMot CorrecteurOrthographique_genererMotsParSuppression(Mot mot);

/**
* \fn ListeDeMot CorrecteurOrthographique_genererMotsParSuprresion(Mot mot);
* \brief R�cup�re des mots pouvant �tre construit � partir d'un mot en rempla�ant une lettre
* \param Mot mot : le mot en question
* \return ListeDeMot
* \author �tienne Batise
*/
ListeDeMot CorrecteurOrthographique_genererMotsParRemplacement(Mot mot);

/**
* \fn ListeDeMot CorrecteurOrthographique_genererMotsParSuprresion(Mot mot);
* \brief R�cup�re des mots pouvant �tre construit � partir d'un mot en ins�rant une lettre
* \param Mot mot : le mot en question
* \return ListeDeMot
* \author �tienne Batise
*/
ListeDeMot CorrecteurOrthographique_genererMotsParInsertion(Mot mot);

/**
* \fn ListeDeMot CorrecteurOrthographique_genererMotsParInversion(Mot mot);
* \brief R�cup�re des mots pouvant �tre construit � partir d'un mot en inversant des lettres du mot
* \param Mot mot : le mot en question
* \return ListeDeMot
* \author Antoine Augusti
*/
ListeDeMot CorrecteurOrthographique_genererMotsParInversion(Mot mot);

/**
* \fn ListeDeMot CorrecteurOrthographique_motsExacts(ListeDeMot listeDeMots, Dictionnaire dictionnaire);* \brief Filtre les mots d'une liste selon leur existance dans un dictionnaire 
* \param ListeDeMot listeDeMots : la liste de Mot � filtrer
* \param Dictionnaire dictionnaire : le dictionnaire qui sert de r�f�rence
* \author �tienne Batise
*/
ListeDeMot CorrecteurOrthographique_motsExacts(ListeDeMot listeDeMots, Dictionnaire dictionnaire);

#endif