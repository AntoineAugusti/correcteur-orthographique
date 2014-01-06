# Installation de CUnit et Doxygen
Taper la commande suivante dans un terminal :
	sudo apt-get install libcunit1 libcunit1-dev libcunit1-doc doxygen

# Utilisation du makefile
Pour la compilation de l'exécutable, des tests et de la documentation :

	make all

Pour la compilation de l'exécutable seul :

	make exe

Pour la compilation des tests seuls :

	make tests

Pour la compilation de la documentation seule :

	make doc

Pour la compilation et l'exécution des tests unitaires :

	make exetests

Pour le nettoyage du répertoire :

	make clean

Des commandes plus spécifiques pour la compilation et les tests unitaires de chaque module existent. Voir le makefile pour avoir les commandes.

# Dictionnaire de référence
Le dictionnaire de la langue française utilisable par notre correcteur orthographique est généré à partir du fichier dictionnaires/dico-ref-ascii.txt. Un dictionnaire vide est disponible à partir du fichier dictionnaires/vide.dico.

Pour le remplir avec le dictionnaire français : ./bin/asispell -d dictionnaires/vide.dico -f dictionnaires/dico-ref-ascii.txt

# Notes sur l'encodage
Ce programme a été conçu pour être exécuté dans un terminal utilisant l'encodage Western (ISO-8859-15). Tout autre encodage peut générer un comportement non désiré.

Pour changer l'encodage du terminal sous Ubuntu, rendez-vous dans le menu "Terminal" de votre terminal puis "Choix du jeu de caractères" puis sélectionnez l'encodage ISO-8859-15.