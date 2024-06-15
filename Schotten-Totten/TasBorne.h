#ifndef TASBORNE_H
#define TASBORNE_H

#include "TasDeCartes.h"
#include "Carte.h"
#include <vector>
#include <memory>

class TasBorne : public TasDeCartes<Carte> {
    // Attributs
    // vector<unique_ptr<Carte>> tas;
    // unsigned int capacite;

public:

    TasBorne() { capacite = 3; }

};

#endif