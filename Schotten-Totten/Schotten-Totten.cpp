#include <iostream>
#include "CarteClan.h"
#include "CarteTactique.h"
#include "vector"
#include "Total.h"
#include "TotalClassique.h"
#include "TotalTactique.h"
#include "Affichage.h"
using namespace std;

int main()
{
    //// Test de création d'un jeu complet du mode classique
    //TotalClassique totCla = TotalClassique();

    //// Test de création d'un jeu complet du mode tactique
    //TotalTactique totTac = TotalTactique();

    CarteClan clan(4, 5);
    Affichage::carteClan(clan);

}
