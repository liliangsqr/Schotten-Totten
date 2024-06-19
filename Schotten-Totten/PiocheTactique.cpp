#include "PiocheTactique.h"

std::unique_ptr<CarteTactique> PiocheTactique::piocherCarte()
{
    if (tas.empty()) throw std::runtime_error("La pioche tactique est vide");

    std::unique_ptr<CarteTactique> hautPioche = std::move(tas.back());
    tas.pop_back();
    return hautPioche;
}