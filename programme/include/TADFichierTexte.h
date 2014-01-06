/**
 * \file TADFichierTexte.h
 * \brief Implantation du TAD FichierTexte avec la SDD FichierTexte
 * \version 1.0
 */
#ifndef __TAD_FICHIER_TEXTE__
#define __TAD_FICHIER_TEXTE__

typedef enum {LECTURE, ECRITURE} Mode;

typedef struct Fichier {
	FILE* file;
	char* nom;
	Mode mode;
} Fichier;

/**
* \fn Fichier FichierTexte_fichierTexte(char* nomDuFichier); 
* \brief création d'un fichier texte à partir d'un fichier identifé par son nom
* \param char* nomDuFichier : le nom du fichier
* \return Ficher : le fichier
* \author Étienne Batise
*/
Fichier FichierTexte_fichierTexte(char* nomDuFichier);

/**
* \fn unsigned int FichierTexte_estOuvert(Fichier fichier);
* \brief Permet de savoir si un fichier est ouvert ou non
* \param Fichier fichier : le fichier a ouvrir
* \return unsigned int : booléen qui vaut vrai si le fichier est ouvert, faux sinon 
* \author Étienne Batise
*/
unsigned int FichierTexte_estOuvert(Fichier fichier);

/**
* \fn void FichierTexte_ouvrir(Fichier *fichier, Mode mode);
* \brief Ouvre un fichier texte en lecture ou en écriture. Si le mode est écriture et que le fichier existe, alors ce dernier est écrasé
* \param Fichier* fichier : le fichier à ouvrir
* \param Mode mode : le mode d'ouverture souhaité
* \author Étienne Batise
*/
void FichierTexte_ouvrir(Fichier *fichier, Mode mode);

/**
* \fn void FichierTexte_fermer(Fichier *fichier);
* \brief Ferme un fichier texte
* \param Fichier fichier : le fichier à fermer
* \author Étienne Batise
*/
void FichierTexte_fermer(Fichier *fichier);


/**
* \fn Mode FichierTexte_mode(Fichier fichier);
* \brief Permet de connaitre le mode d'ouverture d'un fichier
* \param Fichier fichier : le fichier que l'on étudie
* \return Le mode d'ouverture du fichier
* \author Étienne Batise
*/
Mode FichierTexte_mode(Fichier fichier);

/**
* \fn unsigned int FichierTexte_finFichier(Fichier fichier);
* \brief Permet de savoir si l'on est à la fin d'un fichier
* \param Fichier fichier : Le ficher que l'on veut étudier
* \return Un booléen qui vaut 1 si on est à la fin, 0 sinon
* \warning (fichier.mode == LECTURE) && FichierTexte_estOuvert(fichier)
* \author Étienne Batise
*/
unsigned int FichierTexte_finFichier(Fichier fichier);

/**
* \fn void FichierTexte_ecrireChaine(Fichier *fichier, char* chaine);
* \brief Écrit une chaîne suivi d'un retour à la ligne à partir de la position courante du fichier
* \param Fichier* fichier, char* chaine
* \warning FichierTexte_estOuvert(*fichier) && (FichierTexte_mode(*fichier) == ECRITURE)
* \author Étienne Batise
*/
void FichierTexte_ecrireChaine(Fichier *fichier, char* chaine);

/**
* \fn char* FichierTexte_lireChaine(Fichier fichier);
* \brief Lit une chaîne (jusqu'à un retour à la ligne ou à la fin du fichier) à partir de la position courante du fichier
* \param Fichier fichier 
* \return char*  : la chaine lue
* \warning FichierTexte_estOuvert(fichier) && (FichierTexte_mode(fichier) == LECTURE) && !FichierTexte_finFichier(fichier)
* \note : Penser à liberer l'espace mémoire alloué à la chaine de caractère
* \author Étienne Batise
*/
char* FichierTexte_lireChaine(Fichier fichier);

/**
* \fn void FichierTexte_ecrireCaractere(Fichier *fichier, char caractere);
* \brief Écrit un caractère à partir de la position courante du fichier 
* \param Fichier* fichier : le fichier dans lequel on veut écrire un caractère
* \param char caractere : le caractère que l'on veut écrire
* \warning FichierTexte_estOuvert(*fichier) && (FichierTexte_mode(*fichier) == ECRITURE)
* \author Étienne Batise
*/
void FichierTexte_ecrireCaractere(Fichier *fichier, char caractere);

/**
* \fn char FichierTexte_lireCaractere(Fichier fichier);
* \brief Lit un caractère à partir de la position courante du fichier
* \param Fichier fichier : le fichier dans lequel on veut lire le caractère
* \return char : le caractère lut
* \warning FichierTexte_estOuvert(fichier) && (FichierTexte_mode(fichier) == LECTURE) && !FichierTexte_finFichier(fichier)
* \author Étienne Batise
*/
char FichierTexte_lireCaractere(Fichier fichier);

/**
* \fn void FichierTexte_ReecrireCaractere(char caractere, Fichier *fichier);
* \brief Remet un caractère après une lecture, permet de revenir en arrière avec le pointeur de lecture du fichier
* \param char caractere : le caractère que l'on vient de lire que l'on veut remettre
* \param Fichier fichier : le fichier que l'on veut modifier
* \author Antoine Augusti
*/
void FichierTexte_deplacementCurseurMoinsUn(Fichier *fichier);

/**
* \fn unsigned int FichierTexte_existe(char* emplacement)
* \brief Détermine si un fichier existe en fonction de son emplacement
* \param char* emplacement : l'emplacement du fichier que l'on veut tester
* \return 1 si le fichier existe, 0 sinon
* \author Antoine Augusti
*/
unsigned int FichierTexte_existe(char* emplacement);

/**
* \fn unsigned int FichierTexte_nombreDeCaractere(Fichier fichier);
* \brief Renvoi le nombre de caractère d'un Fichier
* \param Fichier fichier : le fichier que l'on veut étudier
* \return unsigned int : le nombre de caractères du fichier
* \author Étienne Batise
*/
unsigned int FichierTexte_nombreDeCaractere(Fichier fichier);

/**
* \fn unsigned int FichierTexte_estUnRetourChariot(char caractere);
* \brief Permet de savoir si le caractere est une retour chariot
* \param char caractere : le caractère à étudier
* \return unsigned int : vrai si le caractère vaut \n
* \author Étienne Batise
*/
unsigned int FichierTexte_estUnRetourChariot(char caractere);
#endif
