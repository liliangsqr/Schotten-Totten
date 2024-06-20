#ifndef ONTOP_H
#define ONTOP_H

#include "TasDeCartes.h"
#include "ModeCombat.h"

// TasDeCartes n'accueillant que des cartes tactiques de type ModeCombat et se pla�ant sur une borne
class OnTop : public TasDeCartes<ModeCombat>
{
	// ATTRIBUTS
	// vector<unique_ptr<ModeCombat>> tas;
	// unsigned int capacite;

public :
	OnTop() : TasDeCartes(Regles::getInstance().getTailleMaxOnTop()) { }
};

#endif ONTOP_H