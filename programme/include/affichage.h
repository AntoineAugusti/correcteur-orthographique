/**
 * \file affichage.h
 * \brief Fonctions utiles pour l'affichage
 * \version 1.0
 */

#ifndef __IHM__
#define __IHM__
 
/**
* \fn void IHM_afficherAide();
* \brief Affiche l'aide du programme
* \author �tienne Batise
*/
void IHM_afficherAide();

/**
* \fn  void IHM_afficherResultat(int erreur, char* resultat);
* \brief Affiche le r�sultat du programme
* \param int erreur : le type d'erreur (0 =  aucune erreur) 
* \param char* resultat : la chaine � �crire si il n'y a aucune erreur
* \author �tienne Batise
*/
void IHM_afficherResultat(int erreur, char* resultat);

/**
* \fn void IHM_afficherCorrection(char* resultat);
* \brief Affiche la correction d'une chaine
* \param char* chaine : la chaine � afficher
* \author �tienne Batise
*/
void IHM_afficherCorrection(char* resultat);

/**
* \fn void IHM_afficherErreur(int erreur); 
* \brief Affiche le type d'erreur rencontr�e
* \param int erreur : l'erreur rencontr�e ( > 0 )
* \author �tienne Batise
*/
void IHM_afficherErreur(int erreur);

#endif