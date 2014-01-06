/**
 * \file TADMot.h
 * \brief Implantation du TAD Mot avec la SDD Mot
 * \version 1.0
 */
#ifndef __TAD_MOT__
#define __TAD_MOT__

typedef struct {
  char* contenu;
  unsigned int longueur;
} Mot;

/**
 * \fn Mot Mot_mot();
 * \brief Cr�e un Mot vide
 * \return retourne un Mot "vide"
 * \author Thibaud Dauce
 */
Mot Mot_mot();

/**
 * \fn char* Mot_obtenirContenu(Mot mot);
 * \brief Retourne le contenu (les lettres) d'un Mot
 * \param Mot mot : le mot concern�
 * \return Le contenu du mot
 * \author Thibaud Dauce
 */
char* Mot_obtenirContenu(Mot mot);

/**
 * \fn unsigned int Mot_longueur(Mot mot);
 * \brief Retourne la longueur d'un mot
 * \param Mot mot : le mot concerné
 * \return la taille du mot
 * \author Thibaud Dauce
 */
unsigned int Mot_longueur(Mot mot);

/**
 * \fn  Mot Mot_genererMot(char * chaine);
 * \brief G�n�re un mot � partir d'une chaine de caract�re
 * \param char* chaine : la chaine � partir de laquelle on veut obtenir un mot
 * \return le mot � partir de la chaine
 * \author Thibaud Dauce
 */
Mot Mot_genererMot(char* chaine);

/**
 * \fn unsigned int Mot_sontEgaux(Mot mot1, Mot mot2);
 * \brief Indique si 2 Mots sont �gaux (m�me contenu, de m�me taille)
 * \param Mot mot1 : le premier mot concern�
 * \param Mot mot2 : le deuxi�me mot concern�
 * \return vrai si les mots sont �gaux, faux sinon
 * \author Thibaud Dauce
 */
unsigned int Mot_sontEgaux(Mot mot1, Mot mot2);

/**
 * \fn void Mot_insererCaractere(Mot* mot, char c, unsigned int position);
 * \brief Ins�re un caract�re dans un Mot � la position donn�e
 * \param Mot mot : le mot concern�
 * \param char c : le caract�re concern�
 * \param unsigned int position : la position
 * \author Thibaud Dauce
 */
void Mot_insererCaractere(Mot* mot, char c, unsigned int position);


/**
 * \fn void Mot_modifierCaractere(Mot* mot, char c, unsigned int position);
 * \brief Modifie un caract�re dans un Mot � la position donn�e
 * \param Mot mot : le mot concern�
 * \param char c : le caract�re concern�
 * \param unsigned int position : la position
 * \author Thibaud Dauce
 */
void Mot_modifierCaractere(Mot* mot, char c, unsigned int position);

/**
 * \fn void Mot_supprimerCaractere(Mot* mot, unsigned int position);
 * \brief Supprime un caract�re dans un Mot � la position donn�e
 * \param Mot mot : le mot concern�
 * \param unsigned int position : la position
 * \author Thibaud Dauce
 */
void Mot_supprimerCaractere(Mot* mot, unsigned int position);

/**
 * \fn char Mot_iemeCaracte(Mot mot, unsigned int position);
 * \brief Retourne le caract�re d'un Mot � la position donn�e
 * \param Mot mot : le mot concern�
 * \param unsigned int position : la position
 * \return Le caract�re en question
 * \author Thibaud Dauce
 */
char Mot_iemeCaractere(Mot mot, unsigned int position);

/**
 * \fn Mot Mot_concatener(Mot mot1, Mot mot2);
 * \brief Concat�ne deux mots
 * \param Mot mot1 : le premier mot concern�
 * \param Mot mot2 : le deuxi�me mot concern�
 * \return Le Mot r�sultat de la concat�nation des deux mots
 * \author Thibaud Dauce
 */
Mot Mot_concatener(Mot mot1, Mot mot2);

/**
 * \fn unsigned int Mot_estUnMotValide(Mot mot);
 * \brief Indique si un Mot est bien compos� de lettres ou de tirets
 * \param Mot mot : le mot concern�
 * \return vrai si le mot est valide, faux sinon
 * \author Thibaud Dauce
 */
unsigned int Mot_estUnMotValide(Mot mot);

/**
 * \fn void Mot_separerMots(Mot mot, unsigned int position, Mot* mot1, Mot* mot2);
 * \brief S�pare en deux mots. L'indice donn� est le d�but du deuxi�me mot. separerMots(abc, 2) donne a et bc.
 * \param Mot mot : le mot concern�
 * \param unsigned int position : la position � laquelle le deuxi�me mot doit commencer
 * \param Mot mot1 : le premier sous-mot
 * \param Mot mot2 : le deuxi�me sous-mot
 * \author Thibaud Dauce
 */
void Mot_separerMots(Mot mot, unsigned int position, Mot* mot1, Mot* mot2);

/**
 * \fn Mot Mot_sousMot(Mot mot, unsigned int debut, unsigned int longueur);
 * \brief Cr�e un sous-mot � partir de l'indice 'debut' du mot et d'une longueur 'longueur'
 * \param Mot mot : le mot concern�
 * \param unsigned int position : la position � laquelle le sous-mot doit commencer
 * \param unsigned int longueur : la longueur du sous-mot � partir de l'indice de d�but
 * \return le sous-mot cr��
 * \author Thibaud Dauce
 */
Mot Mot_sousMot(Mot mot, unsigned int debut, unsigned int longueur);

/**
 * \fn Mot Mot_sousMot(Mot mot, unsigned int debut, unsigned int longueur);
 * \brief Indique si le Mot mot1 est contenu dans le Mot mot2
 * \param Mot mot1 : le mot recherch�
 * \param Mot mot2 : le mot o� l'on recherche
 * \return vrai si mot1 est un sous-mot de mot2, faux sinon
 * \author Thibaud Dauce
 */
unsigned int Mot_estSousMot(Mot mot1, Mot mot2);

/**
 * \fn unsigned int Mot_sontIdentiques(Mot* mot1, Mot* mot2);
 * \brief Indique si le Mot mot1 � la m�me adresse que le Mot mot2
 * \param Mot mot1 : le premier mot
 * \param Mot mot2 : le deuxi�me mot
 * \return vrai si mot1 � la m�me adresse que mot2, faux sinon
 * \author Thibaud Dauce
 */
unsigned int Mot_sontIdentiques(Mot* mot1, Mot* mot2);

#endif
