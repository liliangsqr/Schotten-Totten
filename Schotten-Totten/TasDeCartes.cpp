#include "TasDeCartes.h"
#include <algorithm>
#include <random>
void TasDeCartes::Melanger()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(tas.begin(), tas.end(), g);
}