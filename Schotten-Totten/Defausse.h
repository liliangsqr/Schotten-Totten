#ifndef DEFAUSSE_H
#define DEFAUSSE_H

#include "TasDeCartes.h"
#include "CarteTactique.h"

// Defausse qui contient les cartes tactiques défaussées
class Defausse : public TasDeCartes<CarteTactique>
{
public:
    Defausse() : TasDeCartes(10) { }

    void defausserCarte(std::unique_ptr<CarteTactique> carte);
};

#endif // DEFAUSSE_H