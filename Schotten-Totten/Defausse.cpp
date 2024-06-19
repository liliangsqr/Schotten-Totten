#include "Defausse.h"

void Defausse::defausserCarte(std::unique_ptr<CarteTactique> carte)
{
    if (tas.size() >= capacite) throw std::runtime_error("La defausse est pleine");
    tas.push_back(std::move(carte));
}