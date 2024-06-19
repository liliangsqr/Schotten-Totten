#ifndef PIOCHETACTIQUE_H
#define PIOCHETACTIQUE_H

#include "TasDeCartes.h"
#include "CarteTactique.h"

// PiocheTactique qui contient les cartes tactiques à piocher
class PiocheTactique : public TasDeCartes<CarteTactique>
{
public:
    PiocheTactique() : TasDeCartes(10) { }  // Assuming there are 10 tactical cards

    std::unique_ptr<CarteTactique> piocherCarte();
};

#endif // PIOCHETACTIQUE_H