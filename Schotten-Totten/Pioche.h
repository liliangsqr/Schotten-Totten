#ifndef PIOCHE_H
#define PIOCHE_H

#include "TasDeCartes.h"
#include "Regles.h"

// TasDeCartes qui donne libre accès à la carte au-dessus du tas pour être piochée
class Pioche : public TasDeCartes<Carte>
{
private:
	// vector<unique_ptr<T>> tas;
	// unsigned int capacite;
public:
	Pioche() : TasDeCartes(100) { }

	unique_ptr<Carte> getOnTop();
};

#endif