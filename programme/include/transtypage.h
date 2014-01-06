/**
 * \file transtypage.h
 * \brief Module permettant d'effectuer plusieurs types de transtypages
 * \version 1.0
 */
#ifndef __TRANSTYPAGE__
#define __TRANSTYPAGE__

/**
* \fn char* entierEnChaine(int e)
* \brief Permet de récupérer un Naturel sous la forme d'une chaine de caractère
* \param unsigned int e : l'entier que l'on veut transformer
* \return char* : la chaine de caractère correspondant à l'entier
* \warning : Le chaine est allouée dynamiquement. Il faut donc penser à la libérer après utilisation.
* \author Étienne Batise
*/
char* Transtypage_entierEnChaine(unsigned int e);
#endif