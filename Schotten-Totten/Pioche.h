#ifndef PIOCHE_H
#define PIOCHE_H

#include "TasDeCartes.h"

// TasDeCartes qui donne libre accès à la carte au-dessus du tas pour être piochée
class Pioche : public TasDeCartes<Carte>
{
private:
	// vector<unique_ptr<T>> tas;
	// unsigned int capacite;
public:
	Pioche() : TasDeCartes(Regles::getInstance().getTailleMaxPioche()) { }

	unique_ptr<Carte> getOnTop();
};

#endif