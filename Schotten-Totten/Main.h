#ifndef MAIN_H
#define MAIN_H

#include "TasDeCartes.h"
#include "Regles.h"


// TasDeCartes repésentant la main du joueur
class Main : public TasDeCartes<Carte>
{
	// Attributs
	// vector<unique_ptr<Carte>> tas;
	// unsigned int capacite

	
public :
	// Initialise la main avec pour capacité celle spécifiée dans les règles
	Main() : TasDeCartes(Regles::getInstance().getTailleMain()) { }
};

#endif