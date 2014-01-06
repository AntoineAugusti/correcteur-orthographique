/**
 * \file TADParametres.h
 * \brief Implantation du TAD Parametres avec la SDD Parametres
 * \version 1.0
 */
#ifndef __TAD_PARAMETRES__
#define __TAD_PARAMETRES__
typedef struct {
  char *dictionnaire;
  char *fichier;
  char *cible;
  int 	aide;
} Parametres;

/**
 * \fn Parametres Parametres_parametre();
 * \brief Crée un Parametre
 * \return retourne le Parametre créé
 * \author Faustine Demiselle
 */
Parametres Parametres_parametre();

/**
 * \fn void Parametres_fixerDictionnaire(Parametres* p, char* nomDico);
 * \brief Rempli le champ dictionnaire du paramètre p
 * \param Parametres* p : le paramètre que l'on veut modifier
 * \param  char* nomDico : le nom du dictionnaire
 * \author Faustine Demiselle 
 */
void Parametres_fixerDictionnaire(Parametres* p, char* nomDuDico);

/**
 * \fn void Parametres_fixerFichier(Parametres* p, char* nomDuFichier);
 * \brief Rempli le champ fichier du paramètre p
 * \param Parametres* p : le paramètre que l'on veut modifier
 * \param  char* nomDuFichier : le nom du fichier
 * \author Faustine Demiselle
 */
void Parametres_fixerFichier(Parametres* p, char* nomDuFichier);

/**
 * \fn void Parametres_fixerCible(Parametres* p, char* nomDeLaCible);
 * \brief Rempli le champ cible du paramètre p
 * \param Parametres* p : le paramètre que l'on veut modifier
 * \param  char* nomDeLaCible : le nom de la cible
 * \author Faustine Demiselle
 */
void Parametres_fixerCible(Parametres* p, char* nomDeLaCible);

/**
 * \fn void Parametres_fixerAide(Parametres* p, int presenceDuH);
 * \brief Permet de fixer l'aide comme paramètre si "-h" est utilisé
 * \param Parametres* p : le paramètre que l'on veut modifier
 * \param int presenceDuH : vrai(1) ou faux(0) selon que l'on est trouvé le "-h"
 * \author Faustine Demiselle
 */
void Parametres_fixerAide(Parametres* p, int presenceDuH);

/**
 * \fn char* Parametres_obtenirDictionnaire(Parametres p);
 * \brief Retourne le nom du dictionnaire
 * \param Parametres p : le paramètre dont on veut obtenir le nom du dico
 * \return le nom du dictionnaire
 * \author Faustine Demiselle
 */
char* Parametres_obtenirDictionnaire(Parametres p);

/**
 * \fn char* Parametres_obtenirFichier(Parametres p);
 * \brief Retourne le nom du fichier
 * \param Parametres p : le paramètre dont on veut obtenir le nom du fichier
 * \return le nom du fichier
 * \author Faustine Demiselle
 */
char* Parametres_obtenirFichier(Parametres p);

/**
 * \fn char* Parametres_obtenirCible(Parametres p);
 * \brief Retourne le nom de la cible
 * \param Parametres p : le paramètre dont on veut obtenir le nom de la cible
 * \return le nom du cible
 * \author Faustine Demiselle
 */
char* Parametres_obtenirCible(Parametres p);

/**
 * \fn char* Parametres_obtenirAide(Parametres p);
 * \brief Retourne la présence de l'aide
 * \param Parametres p : le paramètre dont on veut obtenir la présence de l'aide
 * \return la présence de l'aide
 * \author Faustine Demiselle
 */
int Parametres_obtenirAide(Parametres p);
#endif
