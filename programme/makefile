SRCDIR=src
TESTSDIR=tests
TESTSOUTPUT=testsOutput
LIBDIR=lib
DOCDIR=doc
BINDIR=bin
INCLUDEDIR=include
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=c99 -I$(INCLUDEDIR)  
TESTSFLAGS=-lcunit -Wall -pedantic 
LDFLAGS=-L$(LIBDIR) -lcorrecteurorthographique -lm
EXEC=asispell

all :   exe tests doc
exe :   $(BINDIR)/$(EXEC)
tests : $(TESTSOUTPUT)/TUelementDico $(TESTSOUTPUT)/TUlistemot $(TESTSOUTPUT)/TUlsm $(TESTSOUTPUT)/TUmot $(TESTSOUTPUT)/TUdico $(TESTSOUTPUT)/TUfichier $(TESTSOUTPUT)/TUsupermot $(TESTSOUTPUT)/TUparametres
exetests : 
	make clean; make tests;./testsOutput/TUelementDico;./testsOutput/TUdico;./testsOutput/TUfichier;./testsOutput/TUlistemot;./testsOutput/TUlsm;./testsOutput/TUmot;./testsOutput/TUparametres;./testsOutput/TUsupermot

asispell : $(SRCDIR)/main.o affichage corriger dico lsm listemot parametre fichier LMsm;
affichage : $(SRCDIR)/affichage.o 
corriger : $(SRCDIR)/corriger.o $(SRCDIR)/TADDictionnaire.o $(SRCDIR)/TADCorrecteurOrthographique.o $(SRCDIR)/TADMot.o $(SRCDIR)/TADSuperMot.o $(SRCDIR)/TADListeDeSuperMot.o $(SRCDIR)/transtypage.o
correcteur :  $(SRCDIR)/TADCorrecteurOrthographique.o
dico :  $(SRCDIR)/TADDictionnaire.o
fichier :   $(SRCDIR)/TADFichierTexte.o
listemot :  $(SRCDIR)/TADListeDeMot.o
listesupermot :  $(SRCDIR)/TADListeDeSuperMot.o
lsm :  $(SRCDIR)/TADListeDeSuperMot.o
LMsm : $(SRCDIR)/LMSuperMot.o
mot :  $(SRCDIR)/TADMot.o
supermot :  $(SRCDIR)/TADSuperMot.o
parametre : $(SRCDIR)/TADParametres.o
doc : $(DOCDIR)/html/index.html
TUlistemot : $(TESTSOUTPUT)/TUlistemot
TUlsm : $(TESTSOUTPUT)/TUlsm
TUmot : $(TESTSOUTPUT)/TUmot
TUelementDico : $(TESTSOUTPUT)/TUelementDico 
TUdico : $(TESTSOUTPUT)/TUdico 
TUfichier : $(TESTSOUTPUT)/TUfichier
TUsupermot : $(TESTSOUTPUT)/TUsupermot
TUparametres : $(TESTSOUTPUT)/TUparametres

$(TESTSOUTPUT)/TUmot : $(TESTSDIR)/testTADMot.o $(SRCDIR)/TADMot.o
	$(CC) -o $@ $^ $(TESTSFLAGS)

$(TESTSOUTPUT)/TUelementDico : $(TESTSDIR)/testTADElementDictionnaire.o $(SRCDIR)/TADDictionnaire.o $(SRCDIR)/TADFichierTexte.o $(SRCDIR)/TADMot.o 
	$(CC) -o $@ $^ $(TESTSFLAGS)

$(TESTSOUTPUT)/TUdico : $(TESTSDIR)/testTADDictionnaire.o $(SRCDIR)/TADFichierTexte.o $(SRCDIR)/TADDictionnaire.o $(SRCDIR)/TADMot.o
	$(CC) -o $@ $^ $(TESTSFLAGS)

$(TESTSOUTPUT)/TUfichier : $(TESTSDIR)/testTADFichierTexte.o $(SRCDIR)/TADFichierTexte.o $(SRCDIR)/TADMot.o
	$(CC) -o $@ $^ $(TESTSFLAGS)

$(TESTSOUTPUT)/TUlistemot : $(TESTSDIR)/testTADListeDeMot.o $(SRCDIR)/TADListeDeMot.o $(SRCDIR)/TADMot.o
	$(CC) -o $@ $^ $(TESTSFLAGS)

$(TESTSOUTPUT)/TUlsm : $(TESTSDIR)/testTADListeDeSuperMot.o $(SRCDIR)/TADListeDeSuperMot.o $(SRCDIR)/TADListeDeMot.o $(SRCDIR)/TADSuperMot.o $(SRCDIR)/TADMot.o
	$(CC) -o $@ $^ $(TESTSFLAGS)

$(TESTSOUTPUT)/TUsupermot : $(TESTSDIR)/testTADSuperMot.o $(SRCDIR)/TADSuperMot.o $(SRCDIR)/TADListeDeMot.o $(SRCDIR)/TADMot.o
	$(CC) -o $@ $^ $(TESTSFLAGS)

$(TESTSOUTPUT)/TUparametres : $(TESTSDIR)/testTADParametres.o $(SRCDIR)/TADParametres.o
	$(CC) -o $@ $^ $(TESTSFLAGS)

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBDIR)/libcorrecteurorthographique.a $(SRCDIR)/TADParametres.o $(SRCDIR)/affichage.o $(SRCDIR)/corriger.o $(SRCDIR)/transtypage.o $(SRCDIR)/LMSuperMot.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(SRCDIR)/main.o : 
	$(CC) -o src/main.o -c src/main.c -Wall -pedantic -g -Iinclude -std=c99 -D_GNU_SOURCE

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(TESTSDIR)/%.o : $(TESTSDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(DOCDIR)/html/index.html :
	cd doc && doxygen Doxyfile
	
$(LIBDIR)/libcorrecteurorthographique.a : $(SRCDIR)/TADDictionnaire.o $(SRCDIR)/TADFichierTexte.o $(SRCDIR)/TADListeDeMot.o $(SRCDIR)/TADListeDeSuperMot.o $(SRCDIR)/TADMot.o $(SRCDIR)/TADSuperMot.o $(SRCDIR)/TADCorrecteurOrthographique.o
	$(AR) -r $@ $^

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(TESTSOUTPUT)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTSDIR)/*.o
	rm -rf $(DOCDIR)/html