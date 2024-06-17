#ifndef TOTAL_H
#define TOTAL_H
#include <vector>
#include <memory>
#include "CarteClan.h"
#include "Enum.h"
#include "TasDeCartes.h"

using namespace std;

// Sert de base aux totaux sp�cialis�s, le type stock� dans le vector est Carte, la restriction du type de cartes se fait dans les types des m�thodes
class Total : public TasDeCartes<Carte>
{
	// Attributs
	// vector<unique_ptr<T>> tas;
	// unsigned int capacite


public :
	// Constructeurs & destructeur

	// Remplis le tas uniquement de toutes les cartes clan
	Total();

	// M�thodes

    bool estVide() { return tas.empty(); }
	unsigned int getTaille() { return (unsigned int)tas.size(); }
};

#endif TOTAL_H