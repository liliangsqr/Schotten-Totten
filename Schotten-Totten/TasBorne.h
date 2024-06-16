#ifndef TASBORNE_H
#define TASBORNE_H

#include "TasDeCartes.h"
#include "Carte.h"
#include <vector>
#include <memory>
#include "Regles.h"

// TasDeCartes pos� � c�t� d'une borne, associ� � un joueur
class TasBorne : public TasDeCartes<Carte>
{
    // Attributs
    // vector<unique_ptr<Carte>> tas;
    // unsigned int capacite;

public:

    TasBorne() : TasDeCartes(Regles::getInstance().getCapaciteMaxTasBorne()) { }

};

#endif