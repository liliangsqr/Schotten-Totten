#ifndef TOTAL_H
#define TOTAL_H
#include <vector>
#include <memory>
#include "CarteClan.h"
#include "Enum.h"

using namespace std;

class Total
{
protected :
	// Attributs
	vector<unique_ptr<Carte>> tas;


public :
	// Constructeurs & destructeur

	// Remplis le tas uniquement de toutes les cartes clan
	Total();
};

#endif TOTAL_H