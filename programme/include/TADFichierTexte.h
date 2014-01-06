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
* \brief cr�ation d'un fichier texte � partir d'un fichier identif� par son nom
* \param char* nomDuFichier : le nom du fichier
* \return Ficher : le fichier
* \author �tienne Batise
*/
Fichier FichierTexte_fichierTexte(char* nomDuFichier);

/**
* \fn unsigned int FichierTexte_estOuvert(Fichier fichier);
* \brief Permet de savoir si un fichier est ouvert ou non
* \param Fichier fichier : le fichier a ouvrir
* \return unsigned int : bool�en qui vaut vrai si le fichier est ouvert, faux sinon 
* \author �tienne Batise
*/
unsigned int FichierTexte_estOuvert(Fichier fichier);

/**
* \fn void FichierTexte_ouvrir(Fichier *fichier, Mode mode);
* \brief Ouvre un fichier texte en lecture ou en �criture. Si le mode est �criture et que le fichier existe, alors ce dernier est �cras�
* \param Fichier* fichier : le fichier � ouvrir
* \param Mode mode : le mode d'ouverture souhait�
* \author �tienne Batise
*/
void FichierTexte_ouvrir(Fichier *fichier, Mode mode);

/**
* \fn void FichierTexte_fermer(Fichier *fichier);
* \brief Ferme un fichier texte
* \param Fichier fichier : le fichier � fermer
* \author �tienne Batise
*/
void FichierTexte_fermer(Fichier *fichier);


/**
* \fn Mode FichierTexte_mode(Fichier fichier);
* \brief Permet de connaitre le mode d'ouverture d'un fichier
* \param Fichier fichier : le fichier que l'on �tudie
* \return Le mode d'ouverture du fichier
* \author �tienne Batise
*/
Mode FichierTexte_mode(Fichier fichier);

/**
* \fn unsigned int FichierTexte_finFichier(Fichier fichier);
* \brief Permet de savoir si l'on est � la fin d'un fichier
* \param Fichier fichier : Le ficher que l'on veut �tudier
* \return Un bool�en qui vaut 1 si on est � la fin, 0 sinon
* \warning (fichier.mode == LECTURE) && FichierTexte_estOuvert(fichier)
* \author �tienne Batise
*/
unsigned int FichierTexte_finFichier(Fichier fichier);

/**
* \fn void FichierTexte_ecrireChaine(Fichier *fichier, char* chaine);
* \brief �crit une cha�ne suivi d'un retour � la ligne � partir de la position courante du fichier
* \param Fichier* fichier, char* chaine
* \warning FichierTexte_estOuvert(*fichier) && (FichierTexte_mode(*fichier) == ECRITURE)
* \author �tienne Batise
*/
void FichierTexte_ecrireChaine(Fichier *fichier, char* chaine);

/**
* \fn char* FichierTexte_lireChaine(Fichier fichier);
* \brief Lit une cha�ne (jusqu'� un retour � la ligne ou � la fin du fichier) � partir de la position courante du fichier
* \param Fichier fichier 
* \return char*  : la chaine lue
* \warning FichierTexte_estOuvert(fichier) && (FichierTexte_mode(fichier) == LECTURE) && !FichierTexte_finFichier(fichier)
* \note : Penser � liberer l'espace m�moire allou� � la chaine de caract�re
* \author �tienne Batise
*/
char* FichierTexte_lireChaine(Fichier fichier);

/**
* \fn void FichierTexte_ecrireCaractere(Fichier *fichier, char caractere);
* \brief �crit un caract�re � partir de la position courante du fichier 
* \param Fichier* fichier : le fichier dans lequel on veut �crire un caract�re
* \param char caractere : le caract�re que l'on veut �crire
* \warning FichierTexte_estOuvert(*fichier) && (FichierTexte_mode(*fichier) == ECRITURE)
* \author �tienne Batise
*/
void FichierTexte_ecrireCaractere(Fichier *fichier, char caractere);

/**
* \fn char FichierTexte_lireCaractere(Fichier fichier);
* \brief Lit un caract�re � partir de la position courante du fichier
* \param Fichier fichier : le fichier dans lequel on veut lire le caract�re
* \return char : le caract�re lut
* \warning FichierTexte_estOuvert(fichier) && (FichierTexte_mode(fichier) == LECTURE) && !FichierTexte_finFichier(fichier)
* \author �tienne Batise
*/
char FichierTexte_lireCaractere(Fichier fichier);

/**
* \fn void FichierTexte_ReecrireCaractere(char caractere, Fichier *fichier);
* \brief Remet un caract�re apr�s une lecture, permet de revenir en arri�re avec le pointeur de lecture du fichier
* \param char caractere : le caract�re que l'on vient de lire que l'on veut remettre
* \param Fichier fichier : le fichier que l'on veut modifier
* \author Antoine Augusti
*/
void FichierTexte_deplacementCurseurMoinsUn(Fichier *fichier);

/**
* \fn unsigned int FichierTexte_existe(char* emplacement)
* \brief D�termine si un fichier existe en fonction de son emplacement
* \param char* emplacement : l'emplacement du fichier que l'on veut tester
* \return 1 si le fichier existe, 0 sinon
* \author Antoine Augusti
*/
unsigned int FichierTexte_existe(char* emplacement);

/**
* \fn unsigned int FichierTexte_nombreDeCaractere(Fichier fichier);
* \brief Renvoi le nombre de caract�re d'un Fichier
* \param Fichier fichier : le fichier que l'on veut �tudier
* \return unsigned int : le nombre de caract�res du fichier
* \author �tienne Batise
*/
unsigned int FichierTexte_nombreDeCaractere(Fichier fichier);

/**
* \fn unsigned int FichierTexte_estUnRetourChariot(char caractere);
* \brief Permet de savoir si le caractere est une retour chariot
* \param char caractere : le caract�re � �tudier
* \return unsigned int : vrai si le caract�re vaut \n
* \author �tienne Batise
*/
unsigned int FichierTexte_estUnRetourChariot(char caractere);
#endif
