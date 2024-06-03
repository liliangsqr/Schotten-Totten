#include "Total.h"

Total::Total()
{
    for (unsigned int itVal = 0; itVal != 9; itVal++) {
        for (unsigned int itCoul = 0; itCoul != 6; itCoul++) {

            tas.push_back(move(make_unique<CarteClan>(CarteClan(itVal, itCoul))));
        }
    }
}