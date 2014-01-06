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
 * \brief Crée un Mot vide
 * \return retourne un Mot "vide"
 * \author Thibaud Dauce
 */
Mot Mot_mot();

/**
 * \fn char* Mot_obtenirContenu(Mot mot);
 * \brief Retourne le contenu (les lettres) d'un Mot
 * \param Mot mot : le mot concerné
 * \return Le contenu du mot
 * \author Thibaud Dauce
 */
char* Mot_obtenirContenu(Mot mot);

/**
 * \fn unsigned int Mot_longueur(Mot mot);
 * \brief Retourne la longueur d'un mot
 * \param Mot mot : le mot concernÃ©
 * \return la taille du mot
 * \author Thibaud Dauce
 */
unsigned int Mot_longueur(Mot mot);

/**
 * \fn  Mot Mot_genererMot(char * chaine);
 * \brief Génère un mot à partir d'une chaine de caractère
 * \param char* chaine : la chaine à partir de laquelle on veut obtenir un mot
 * \return le mot à partir de la chaine
 * \author Thibaud Dauce
 */
Mot Mot_genererMot(char* chaine);

/**
 * \fn unsigned int Mot_sontEgaux(Mot mot1, Mot mot2);
 * \brief Indique si 2 Mots sont égaux (même contenu, de même taille)
 * \param Mot mot1 : le premier mot concerné
 * \param Mot mot2 : le deuxième mot concerné
 * \return vrai si les mots sont égaux, faux sinon
 * \author Thibaud Dauce
 */
unsigned int Mot_sontEgaux(Mot mot1, Mot mot2);

/**
 * \fn void Mot_insererCaractere(Mot* mot, char c, unsigned int position);
 * \brief Insère un caractère dans un Mot à la position donnée
 * \param Mot mot : le mot concerné
 * \param char c : le caractère concerné
 * \param unsigned int position : la position
 * \author Thibaud Dauce
 */
void Mot_insererCaractere(Mot* mot, char c, unsigned int position);


/**
 * \fn void Mot_modifierCaractere(Mot* mot, char c, unsigned int position);
 * \brief Modifie un caractère dans un Mot à la position donnée
 * \param Mot mot : le mot concerné
 * \param char c : le caractère concerné
 * \param unsigned int position : la position
 * \author Thibaud Dauce
 */
void Mot_modifierCaractere(Mot* mot, char c, unsigned int position);

/**
 * \fn void Mot_supprimerCaractere(Mot* mot, unsigned int position);
 * \brief Supprime un caractère dans un Mot à la position donnée
 * \param Mot mot : le mot concerné
 * \param unsigned int position : la position
 * \author Thibaud Dauce
 */
void Mot_supprimerCaractere(Mot* mot, unsigned int position);

/**
 * \fn char Mot_iemeCaracte(Mot mot, unsigned int position);
 * \brief Retourne le caractère d'un Mot à la position donnée
 * \param Mot mot : le mot concerné
 * \param unsigned int position : la position
 * \return Le caractère en question
 * \author Thibaud Dauce
 */
char Mot_iemeCaractere(Mot mot, unsigned int position);

/**
 * \fn Mot Mot_concatener(Mot mot1, Mot mot2);
 * \brief Concatène deux mots
 * \param Mot mot1 : le premier mot concerné
 * \param Mot mot2 : le deuxième mot concerné
 * \return Le Mot résultat de la concaténation des deux mots
 * \author Thibaud Dauce
 */
Mot Mot_concatener(Mot mot1, Mot mot2);

/**
 * \fn unsigned int Mot_estUnMotValide(Mot mot);
 * \brief Indique si un Mot est bien composé de lettres ou de tirets
 * \param Mot mot : le mot concerné
 * \return vrai si le mot est valide, faux sinon
 * \author Thibaud Dauce
 */
unsigned int Mot_estUnMotValide(Mot mot);

/**
 * \fn void Mot_separerMots(Mot mot, unsigned int position, Mot* mot1, Mot* mot2);
 * \brief Sépare en deux mots. L'indice donné est le début du deuxième mot. separerMots(abc, 2) donne a et bc.
 * \param Mot mot : le mot concerné
 * \param unsigned int position : la position à laquelle le deuxième mot doit commencer
 * \param Mot mot1 : le premier sous-mot
 * \param Mot mot2 : le deuxième sous-mot
 * \author Thibaud Dauce
 */
void Mot_separerMots(Mot mot, unsigned int position, Mot* mot1, Mot* mot2);

/**
 * \fn Mot Mot_sousMot(Mot mot, unsigned int debut, unsigned int longueur);
 * \brief Crée un sous-mot à partir de l'indice 'debut' du mot et d'une longueur 'longueur'
 * \param Mot mot : le mot concerné
 * \param unsigned int position : la position à laquelle le sous-mot doit commencer
 * \param unsigned int longueur : la longueur du sous-mot à partir de l'indice de début
 * \return le sous-mot créé
 * \author Thibaud Dauce
 */
Mot Mot_sousMot(Mot mot, unsigned int debut, unsigned int longueur);

/**
 * \fn Mot Mot_sousMot(Mot mot, unsigned int debut, unsigned int longueur);
 * \brief Indique si le Mot mot1 est contenu dans le Mot mot2
 * \param Mot mot1 : le mot recherché
 * \param Mot mot2 : le mot où l'on recherche
 * \return vrai si mot1 est un sous-mot de mot2, faux sinon
 * \author Thibaud Dauce
 */
unsigned int Mot_estSousMot(Mot mot1, Mot mot2);

/**
 * \fn unsigned int Mot_sontIdentiques(Mot* mot1, Mot* mot2);
 * \brief Indique si le Mot mot1 à la même adresse que le Mot mot2
 * \param Mot mot1 : le premier mot
 * \param Mot mot2 : le deuxième mot
 * \return vrai si mot1 à la même adresse que mot2, faux sinon
 * \author Thibaud Dauce
 */
unsigned int Mot_sontIdentiques(Mot* mot1, Mot* mot2);

#endif
