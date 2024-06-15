#pragma once
#include "TasDeCartes.h"
#include "Regles.h"


class Pioche :public TasDeCartes<Carte>
{
private:
	// vector<unique_ptr<T>> tas;
	// unsigned int capacite;
public:
	Pioche() : TasDeCartes(100) { }

	unique_ptr<Carte>& getOnTop();
};

