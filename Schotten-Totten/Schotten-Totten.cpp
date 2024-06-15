#include <iostream>
#include "CarteClan.h"
#include "CarteTactique.h"
#include "vector"
#include "Total.h"
#include "TotalClassique.h"
#include "TotalTactique.h"
#include "Affichage.h"
#include "JeuClassique.h"
using namespace std;

int main()
{
    // Test de création d'un jeu complet du mode classique
    TotalClassique totCla = TotalClassique();

    // Test de création d'un jeu complet du mode tactique
    TotalTactique totTac = TotalTactique();

    // Test de l'initialisation du jeu
    try {
        JeuClassique::getInstance();
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

}
