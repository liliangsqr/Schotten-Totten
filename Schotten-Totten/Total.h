#ifndef TOTAL_H
#define TOTAL_H
#include <vector>
#include <memory>
#include "CarteClan.h"
#include "Enum.h"
#include "TasDeCartes.h"

using namespace std;

// Sert de base aux totaux spécialisés
class Total : public TasDeCartes<Carte>
{
	// Attributs
	// vector<unique_ptr<T>> tas;
	// unsigned int capacite


public :
	// Constructeurs & destructeur

	// Remplis le tas uniquement de toutes les cartes clan
	Total();
};

#endif TOTAL_H