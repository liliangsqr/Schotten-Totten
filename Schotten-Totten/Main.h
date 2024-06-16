#ifndef MAIN_H
#define MAIN_H

#include "TasDeCartes.h"
#include "Regles.h"


// TasDeCartes rep�sentant la main du joueur
class Main : public TasDeCartes<Carte>
{
	// Attributs
	// vector<unique_ptr<Carte>> tas;
	// unsigned int capacite

	
public :
	// Initialise la main avec pour capacit� celle sp�cifi�e dans les r�gles
	Main() : TasDeCartes(Regles::getInstance().getTailleMain()) { }
};

#endif