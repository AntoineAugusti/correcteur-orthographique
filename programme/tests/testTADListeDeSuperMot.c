#include <stdio.h>
#include <CUnit/Basic.h>
#include "TADListeDeSuperMot.h"
#include "TADMot.h"
#include "TADSuperMot.h"

/*
Compilation : make TUliste
*/

int init_suite_success (void) {
	return 0;
}

int clean_suite_success (void) {
	return 0;
}

void test_estVide(void) {
	CU_ASSERT_TRUE(ListeDeSuperMot_estVide(ListeDeSuperMot_liste()));
}

void test_ajoutPuisSuppressionAvecUnElement(void) {
	ListeDeSuperMot liste;
	Mot mot;
	SuperMot supermot;

	liste = ListeDeSuperMot_liste();
	mot = Mot_mot();
	SuperMot_fixerMot(&supermot, mot);
	ListeDeSuperMot_ajouter(&liste, supermot);

	CU_ASSERT_TRUE(ListeDeSuperMot_longueur(liste) == 1);
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 1)), mot));

	/* On supprime l'élément */
	ListeDeSuperMot_supprimer(&liste, 1);
	CU_ASSERT_TRUE(ListeDeSuperMot_estVide(ListeDeSuperMot_liste()));
}

void test_multipleInsertionsEtSuppressions(void) {
	ListeDeSuperMot liste;
	Mot mot1;
	Mot mot2;
	Mot mot3;
	SuperMot supermot1;
	SuperMot supermot2;
	SuperMot supermot3;

	liste = ListeDeSuperMot_liste();

	mot1 = Mot_mot();
	Mot_insererCaractere(&mot1, 'a', 1);
	mot2 = Mot_mot();
	Mot_insererCaractere(&mot2, 'b', 1);
	mot3 = Mot_mot();
	Mot_insererCaractere(&mot3, 'c', 1);

	supermot1 = SuperMot_superMot();
	SuperMot_fixerMot(&supermot1, mot1);
	supermot2 = SuperMot_superMot();
	SuperMot_fixerMot(&supermot2, mot2);
	supermot3 = SuperMot_superMot();
	SuperMot_fixerMot(&supermot3, mot3);

	ListeDeSuperMot_ajouter(&liste, supermot1);
	ListeDeSuperMot_ajouter(&liste, supermot2);
	ListeDeSuperMot_ajouter(&liste, supermot3);

	CU_ASSERT_TRUE(ListeDeSuperMot_longueur(liste) == 3);
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 1)), mot1));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 2)), mot2));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 3)), mot3));

	/* On supprime le premier élément */
	ListeDeSuperMot_supprimer(&liste, 1);
	CU_ASSERT_TRUE(ListeDeSuperMot_longueur(liste) == 2);
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 1)), mot2));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 2)), mot3));

	/* On remet le premier mot au début */
	ListeDeSuperMot_inserer(&liste, supermot1, 1);
	CU_ASSERT_TRUE(ListeDeSuperMot_longueur(liste) == 3);
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 1)), mot1));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 2)), mot2));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 3)), mot3));

	/* On supprime le deuxième élément */
	ListeDeSuperMot_supprimer(&liste, 2);
	CU_ASSERT_TRUE(ListeDeSuperMot_longueur(liste) == 2);
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 1)), mot1));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 2)), mot3));

	/* On remet le deuxième mot à sa place */
	ListeDeSuperMot_inserer(&liste, supermot2, 2);
	CU_ASSERT_TRUE(ListeDeSuperMot_longueur(liste) == 3);
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 1)), mot1));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 2)), mot2));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 3)), mot3));

	/* On supprime le troisième élément */
	ListeDeSuperMot_supprimer(&liste, 3);
	CU_ASSERT_TRUE(ListeDeSuperMot_longueur(liste) == 2);
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 1)), mot1));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 2)), mot2));

	/* On remet le troisème mot à sa place */
	ListeDeSuperMot_inserer(&liste, supermot3, 3);
	CU_ASSERT_TRUE(ListeDeSuperMot_longueur(liste) == 3);
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 1)), mot1));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 2)), mot2));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 3)), mot3));

	/* Suppression de tous les éléments restants */
	ListeDeSuperMot_supprimer(&liste, 1);
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 1)), mot2));
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 2)), mot3));
	ListeDeSuperMot_supprimer(&liste, 1);
	CU_ASSERT_TRUE(Mot_sontEgaux(SuperMot_obtenirMot(ListeDeSuperMot_obtenir(liste, 1)), mot3));
	ListeDeSuperMot_supprimer(&liste, 1);
	CU_ASSERT_TRUE(ListeDeSuperMot_estVide(ListeDeSuperMot_liste()));
}

int main(int argc , char** argv){
	CU_pSuite pSuite = NULL;

	/* Initialisation du registre de tests */ 
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();
	
	/* Ajout d'une suite de tests */
	pSuite = CU_add_suite("Tests boite noire ", init_suite_success ,clean_suite_success );
		if (NULL == pSuite) {
			CU_cleanup_registry();
			return CU_get_error();
		}


	/* Ajout des tests à la suite de tests boite noire */
	if (
		(NULL == CU_add_test(pSuite, "estVide sur une liste vide", test_estVide))
		|| NULL == CU_add_test(pSuite, "ajout et suppression avec un élement", test_ajoutPuisSuppressionAvecUnElement)
		|| NULL == CU_add_test(pSuite, "ajouts et suppressions avec plusieurs élements", test_multipleInsertionsEtSuppressions)) {
		CU_cleanup_registry();
	return CU_get_error();
		}

	/* Lancement des tests */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf ("\n");
	CU_basic_show_failures(CU_get_failure_list());
	printf ("\n\n");

	/* Nettoyage du registre */
	CU_cleanup_registry ();
	
	return CU_get_error ();
}