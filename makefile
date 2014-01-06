RAP=rapport

all : compilRapport
compilRapport : $(RAP)/rapport.pdf

$(RAP)/rapport.pdf : rapport/rapport.tex
	sh ISOtoUTF8.sh
	cd rapport && pdflatex -shell-escape rapport.tex && pdflatex -shell-escape rapport.tex && cd ..
	sh UTF8toISO.sh
clean : 
	rm $(RAP)/rapport.aux $(RAP)/rapport.log $(RAP)/rapport.maf $(RAP)/rapport.mtc* $(RAP)/rapport.out $(RAP)/rapport.toc $(RAP)/rapport.tex.* $(RAP)/rapport.pyg $(RAP)/rapport.pdf

