#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "TADMot.h"

/*
Compilation : make TUmot
*/

int init_suite_success (void) {
	return 0;
}

int clean_suite_success (void) {
	return 0;
}

void test_mot(void) {
	Mot mot = Mot_mot();

	CU_ASSERT_TRUE(mot.longueur == 0);
	CU_ASSERT_TRUE(strcmp(mot.contenu, "") == 0);
}

void test_obtenirContenu(void) {
	Mot mot;
	mot = Mot_genererMot("Salut");

	CU_ASSERT_TRUE(strcmp(Mot_obtenirContenu(mot), "Salut") == 0);
}

void test_sontEgaux(void) {
	Mot mot1;
	mot1 = Mot_genererMot("Salut");
	Mot mot2;
	mot2 = Mot_genererMot("Salut");

	CU_ASSERT_TRUE(Mot_sontEgaux(mot1, mot2));
}

void test_longueur(void) {
	Mot mot;
	mot = Mot_genererMot("Salut");

	CU_ASSERT_TRUE(Mot_longueur(mot) == 5);
}

void test_modifierCaractere(void) {
	Mot mot;
	mot = Mot_genererMot("Salut");
	Mot_modifierCaractere(&mot, 'p', 3);

	CU_ASSERT_TRUE(strcmp(mot.contenu, "Saput") == 0);
}

void test_insererCaractere(void) {
	Mot mot;
	mot = Mot_genererMot("Salut");
	Mot_insererCaractere(&mot, 'a', 6);

	CU_ASSERT_TRUE(strcmp(mot.contenu, "Saluta") == 0);
	CU_ASSERT_TRUE(mot.longueur == 6);
}

void test_supprimerCaractere(void) {
	Mot mot;
	mot = Mot_genererMot("Salut");
	Mot_supprimerCaractere(&mot, 3);

	CU_ASSERT_TRUE(Mot_iemeCaractere(mot, 1) == 'S');
	CU_ASSERT_TRUE(Mot_iemeCaractere(mot, 2) == 'a');
	CU_ASSERT_TRUE(Mot_iemeCaractere(mot, 3) == 'u');
	CU_ASSERT_TRUE(Mot_iemeCaractere(mot, 4) == 't');
	CU_ASSERT_TRUE(Mot_longueur(mot) == 4);
}

void test_iemeCaractere(void) {
	Mot mot;
	mot = Mot_genererMot("Salut");

	CU_ASSERT_TRUE(Mot_iemeCaractere(mot, 1) == 'S');
	CU_ASSERT_TRUE(Mot_iemeCaractere(mot, 2) == 'a');
	CU_ASSERT_TRUE(Mot_iemeCaractere(mot, 3) == 'l');
	CU_ASSERT_TRUE(Mot_iemeCaractere(mot, 4) == 'u');
	CU_ASSERT_TRUE(Mot_iemeCaractere(mot, 5) == 't');
}

void test_concatener(void) {
	Mot mot;
	Mot mot1 = Mot_genererMot("Salut");
	Mot mot2 = Mot_genererMot("ations");

	mot = Mot_concatener(mot1, mot2);

	CU_ASSERT_TRUE(strcmp(mot.contenu, "Salutations") == 0);
	CU_ASSERT_TRUE(mot.longueur == 11);
}

void test_estUnMotValide(void) {
	Mot mot;
	mot = Mot_genererMot("Bl-ah");
	CU_ASSERT_TRUE(Mot_estUnMotValide(mot));
}

void test_separerMots(void) {
	Mot mot = Mot_genererMot("Salut");
	Mot mot1 = Mot_mot();
	Mot mot2 = Mot_mot();
	
	Mot_separerMots(mot, 3, &mot1, &mot2);
	CU_ASSERT_TRUE(strcmp(mot1.contenu, "Sa") == 0);
	CU_ASSERT_TRUE(strcmp(mot2.contenu, "lut") == 0);
	Mot_separerMots(mot, 2, &mot1, &mot2);
	CU_ASSERT_TRUE(strcmp(mot1.contenu, "S") == 0);
	CU_ASSERT_TRUE(strcmp(mot2.contenu, "alut") == 0);
	Mot_separerMots(mot, 5, &mot1, &mot2);
	CU_ASSERT_TRUE(strcmp(mot1.contenu, "Salu") == 0);
	CU_ASSERT_TRUE(strcmp(mot2.contenu, "t") == 0);
}

void test_sousMot(void) {
	Mot mot;
	mot = Mot_genererMot("Casse-croute");

	CU_ASSERT_TRUE(strcmp(Mot_sousMot(mot, 7, 6).contenu, "croute") == 0);
	CU_ASSERT_TRUE(strcmp(Mot_sousMot(mot, 1, 1).contenu, "C") == 0);
	CU_ASSERT_TRUE(strcmp(Mot_sousMot(mot, 1, Mot_longueur(mot)).contenu, "Casse-croute") == 0);
	CU_ASSERT_TRUE(strcmp(Mot_sousMot(mot, 1, 5).contenu, "Casse") == 0);
}

void test_estSousMot(void) {
	Mot mot1;
	mot1 = Mot_genererMot("Casse-croute");
	Mot mot2;
	mot2 = Mot_genererMot("croute");
	CU_ASSERT_TRUE(Mot_estSousMot(mot2, mot1));
}

void test_sontIdentiques(void) {
	Mot mot1;
	mot1 = Mot_genererMot("casse");
	Mot mot2;
	mot2 = Mot_genererMot("casse");	
	CU_ASSERT_FALSE(Mot_sontIdentiques(&mot1, &mot2));
	CU_ASSERT_TRUE(Mot_sontIdentiques(&mot1, &mot1));
}


int main(int argc , char** argv){
	CU_pSuite pSuite = NULL;

	/* initialisation du registre de tests*/ 
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error() ;
	
	/* ajout d'une suite de test */
	pSuite = CU_add_suite("Tests boite noire ", init_suite_success ,clean_suite_success );
		if (NULL == pSuite) {
			CU_cleanup_registry();
			return CU_get_error();
		}


	/* Ajout des tests à la suite de tests boite noire */
	if (
		(NULL == CU_add_test(pSuite, "Mot_mot", test_mot))
		|| (NULL == CU_add_test(pSuite, "Mot_obtenirContenu", test_obtenirContenu))
		|| (NULL == CU_add_test(pSuite, "Mot_sontEgaux", test_sontEgaux))
		|| (NULL == CU_add_test(pSuite, "Mot_longueur", test_longueur))
		|| (NULL == CU_add_test(pSuite, "Mot_modifierCaractere", test_modifierCaractere))
		|| (NULL == CU_add_test(pSuite, "Mot_insererCaractere", test_insererCaractere))
		|| (NULL == CU_add_test(pSuite, "Mot_supprimerCaractere", test_supprimerCaractere))
		|| (NULL == CU_add_test(pSuite, "Mot_iemeCaractere", test_iemeCaractere))
		|| (NULL == CU_add_test(pSuite, "Mot_concatener", test_concatener))
		|| (NULL == CU_add_test(pSuite, "Mot_estUnMotValide", test_estUnMotValide))
		|| (NULL == CU_add_test(pSuite, "Mot_separerMots", test_separerMots))
		|| (NULL == CU_add_test(pSuite, "Mot_sousMot", test_sousMot))
		|| (NULL == CU_add_test(pSuite, "Mot_estSousMot", test_estSousMot))
		|| (NULL == CU_add_test(pSuite, "Mot_sontIdentiques", test_sontIdentiques))
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
