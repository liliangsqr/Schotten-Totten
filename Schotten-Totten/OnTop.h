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
	OnTop() : TasDeCartes(1000) { }
};

#endif ONTOP_H