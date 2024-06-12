#ifndef ONTOP_H
#define ONTOP_H

#include "TasDeCartes.h"
#include "ModeCombat.h"
class OnTop : public TasDeCartes<ModeCombat>
{
	// ATTRIBUTS
	// vector<unique_ptr<ModeCombat>> tas;
	// unsigned int capacite;

public :
	OnTop() { /*capacite = nombre de cartes ModeCombat, jsp quoi faire donc pour l'instant je mets 100*/
		capacite = 100; 
	};
};

#endif ONTOP_H