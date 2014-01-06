#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "TADFichierTexte.h"

/*
Compilation : make TUfichier
*/

int init_suite_success (void) {
	return 0;
}

int clean_suite_success (void) {
	return 0;
}

void test_estOuvert(void){
	CU_ASSERT_TRUE(FichierTexte_estOuvert(FichierTexte_fichierTexte("tests/testFichierTexte.txt")) == 0);
}

void test_ouvrir(void){
	Fichier f1;
	/* Test pour un fichier ouvert en écriture*/
	f1 = FichierTexte_fichierTexte("tests/testFichierTexte.txt");
	FichierTexte_ouvrir(&f1, ECRITURE);

	CU_ASSERT_TRUE(FichierTexte_estOuvert(f1));
	FichierTexte_fermer(&f1);


	/* Test pour un fichier ouvert en lecture*/
	f1 = FichierTexte_fichierTexte("tests/testFichierTexte.txt");
	FichierTexte_ouvrir(&f1, LECTURE);

	CU_ASSERT_TRUE(FichierTexte_estOuvert(f1));
	FichierTexte_fermer(&f1);
}

void test_mode(void){
	Fichier f = FichierTexte_fichierTexte("tests/testFichierTexte.txt");
	FichierTexte_ouvrir(&f, LECTURE);

	CU_ASSERT_EQUAL(FichierTexte_mode(f), LECTURE);
	FichierTexte_fermer(&f);
}

void test_finFichier(void){
	Fichier f = FichierTexte_fichierTexte("tests/testFichierTexte.txt");
	FichierTexte_ouvrir(&f, LECTURE);
	fseek(f.file, 0, SEEK_END);

	CU_ASSERT_TRUE(FichierTexte_finFichier(f));
}

void test_nonFinFichier(void){
	Fichier f = FichierTexte_fichierTexte("tests/testFichierTexte.txt");
	FichierTexte_ouvrir(&f, ECRITURE);
	FichierTexte_ecrireCaractere(&f, 'a');
	FichierTexte_fermer(&f);
	FichierTexte_ouvrir(&f, LECTURE);
	fseek(f.file, 0, SEEK_SET);

	CU_ASSERT_FALSE(FichierTexte_finFichier(f));
}

void test_lireCaractere(void){
	Fichier f;
	char c;

	f = FichierTexte_fichierTexte("tests/testFichierTexte.txt");
	FichierTexte_ouvrir(&f, ECRITURE);
	FichierTexte_ecrireCaractere(&f, 'a');
	FichierTexte_fermer(&f);
	FichierTexte_ouvrir(&f, LECTURE);
	fseek(f.file, 0, SEEK_SET);
	c = FichierTexte_lireCaractere(f);

	CU_ASSERT_EQUAL(c,'a');	
}

void test_deplacementCurseurMoinsUn(void){
	Fichier f;

	f = FichierTexte_fichierTexte("tests/testFichierTexte.txt");
	FichierTexte_ouvrir(&f, ECRITURE);
	FichierTexte_ecrireCaractere(&f, 'a');
	FichierTexte_fermer(&f);
	FichierTexte_ouvrir(&f, LECTURE);
	fseek(f.file, 1, SEEK_SET);
	FichierTexte_deplacementCurseurMoinsUn(&f);

	CU_ASSERT_EQUAL(ftell(f.file), 0);
}

void test_lireChaine(void){
	char* chaine;
	Fichier f;
	f = FichierTexte_fichierTexte("tests/testFichierTexte.txt");
	FichierTexte_ouvrir(&f, ECRITURE);
	FichierTexte_ecrireChaine(&f, "chauve");
	FichierTexte_fermer(&f);

	FichierTexte_ouvrir(&f, LECTURE);
	fseek(f.file, 0, SEEK_SET);
	chaine = FichierTexte_lireChaine(f);

	CU_ASSERT_TRUE(!strcmp(chaine, "chauve"));
}


int main(int argc , char** argv){
	CU_pSuite pSuite = NULL;
	/* initialisation du registre de tests*/ 
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error() ;
	
	/* ajout d'une suite de test */
	pSuite = CU_add_suite("Tests TAD Fichier Texte ", init_suite_success ,clean_suite_success );
		if (NULL == pSuite) {
			CU_cleanup_registry();
			return CU_get_error();
		}

	/* Ajout des tests à la suite de tests boite noire */
	if (
		(NULL == CU_add_test(pSuite, "FichierTexte_estOuvert", test_estOuvert))
		|| (NULL == CU_add_test(pSuite, "FichierTexte_ouvrir", test_ouvrir))
		|| (NULL == CU_add_test(pSuite, "FichierTexte_mode", test_mode))
		|| (NULL == CU_add_test(pSuite, "FichierTexte_finFichier", test_finFichier))
		|| (NULL == CU_add_test(pSuite, "FichierTexte_nonFinFichier", test_nonFinFichier))
		|| (NULL == CU_add_test(pSuite, "FichierTexte_lireCaractere", test_lireCaractere))
		|| (NULL == CU_add_test(pSuite, "FichierTexte_deplacementCurseurMoinsUn", test_deplacementCurseurMoinsUn))
		|| (NULL == CU_add_test(pSuite, "FichierTexte_lireChaine", test_lireChaine))
		) {
		CU_cleanup_registry() ;
	return CU_get_error() ;
		}

	/* Lancement des tests */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf ("\n");
	CU_basic_show_failures( CU_get_failure_list() ) ;
	printf ("\n\n");
	/* Nettoyage du registre */
	CU_cleanup_registry () ;
	return CU_get_error () ;
}