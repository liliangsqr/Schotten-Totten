#include "Total.h"

Total::Total() : TasDeCartes(1000)
{
    // Crée des unique_ptr vers toutes les cartes Clan et les stocke dans tas
    for (unsigned int itVal = 1; itVal != 10; itVal++) {
        for (unsigned int itCoul = 0; itCoul != 6; itCoul++) {
            std::unique_ptr<Carte> carte = std::make_unique<CarteClan>(itVal, itCoul);
            tas.push_back(std::move(carte));
        }
    }
}