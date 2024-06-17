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

    // Tests
    try {
        JeuClassique::getInstance();
        shared_ptr<Joueur> J1 = JeuClassique::getInstance().getJoueurs()[0];
        shared_ptr<Joueur> J2 = JeuClassique::getInstance().getJoueurs()[1];
        JeuClassique::getInstance().poserCarte(0, 0, J1);
        JeuClassique::getInstance().poserCarte(0, 0, J2);
        JeuClassique::getInstance().poserCarte(0, 0, J1);
        JeuClassique::getInstance().poserCarte(0, 0, J2);
        JeuClassique::getInstance().poserCarte(0, 0, J1);
        JeuClassique::getInstance().poserCarte(0, 0, J2);
        cout << JeuClassique::getInstance().borneEstRevendicableParJoueur(0, J1) << endl;
        JeuClassique::getInstance().revendiquerBorne(0, J1);
        
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

}
