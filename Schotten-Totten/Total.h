#pragma once
#include <vector>
#include "Carte.h"
#include <memory>
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

