#include "Total.h"

Total::Total()
{
    // Cr�e des unique_ptr vers toutes les cartes Clan et les stocke dans tas
    for (unsigned int itVal = 0; itVal != 9; itVal++) {
        for (unsigned int itCoul = 0; itCoul != 6; itCoul++) {
            tas.push_back(make_unique<CarteClan>(itVal, itCoul));
        }
    }
}