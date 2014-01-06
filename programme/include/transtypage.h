/**
 * \file transtypage.h
 * \brief Module permettant d'effectuer plusieurs types de transtypages
 * \version 1.0
 */
#ifndef __TRANSTYPAGE__
#define __TRANSTYPAGE__

/**
* \fn char* entierEnChaine(int e)
* \brief Permet de r�cup�rer un Naturel sous la forme d'une chaine de caract�re
* \param unsigned int e : l'entier que l'on veut transformer
* \return char* : la chaine de caract�re correspondant � l'entier
* \warning : Le chaine est allou�e dynamiquement. Il faut donc penser � la lib�rer apr�s utilisation.
* \author �tienne Batise
*/
char* Transtypage_entierEnChaine(unsigned int e);
#endif