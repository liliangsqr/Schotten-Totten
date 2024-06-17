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
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);

        JeuClassique::getInstance().poserCarte(1, 0, J1);
        JeuClassique::getInstance().poserCarte(1, 0, J2);
        JeuClassique::getInstance().poserCarte(1, 0, J1);
        JeuClassique::getInstance().poserCarte(1, 0, J2);
        JeuClassique::getInstance().poserCarte(1, 0, J1);
        JeuClassique::getInstance().poserCarte(1, 0, J2);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);

        JeuClassique::getInstance().poserCarte(2, 0, J1);
        JeuClassique::getInstance().poserCarte(2, 0, J2);
        JeuClassique::getInstance().poserCarte(2, 0, J1);
        JeuClassique::getInstance().poserCarte(2, 0, J2);
        JeuClassique::getInstance().poserCarte(2, 0, J1);
        JeuClassique::getInstance().poserCarte(2, 0, J2);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);

        JeuClassique::getInstance().poserCarte(3, 0, J1);
        JeuClassique::getInstance().poserCarte(3, 0, J2);
        JeuClassique::getInstance().poserCarte(3, 0, J1);
        JeuClassique::getInstance().poserCarte(3, 0, J2);
        JeuClassique::getInstance().poserCarte(3, 0, J1);
        JeuClassique::getInstance().poserCarte(3, 0, J2);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);

        JeuClassique::getInstance().poserCarte(4, 0, J1);
        JeuClassique::getInstance().poserCarte(4, 0, J2);
        JeuClassique::getInstance().poserCarte(4, 0, J1);
        JeuClassique::getInstance().poserCarte(4, 0, J2);
        JeuClassique::getInstance().poserCarte(4, 0, J1);
        JeuClassique::getInstance().poserCarte(4, 0, J2);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);

        JeuClassique::getInstance().poserCarte(5, 0, J1);
        JeuClassique::getInstance().poserCarte(5, 0, J2);
        JeuClassique::getInstance().poserCarte(5, 0, J1);
        JeuClassique::getInstance().poserCarte(5, 0, J2);
        JeuClassique::getInstance().poserCarte(5, 0, J1);
        JeuClassique::getInstance().poserCarte(5, 0, J2);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J2);

        JeuClassique::getInstance().poserCarte(6, 0, J1);
        JeuClassique::getInstance().poserCarte(6, 0, J2);
        JeuClassique::getInstance().poserCarte(6, 0, J1);
        JeuClassique::getInstance().poserCarte(6, 0, J2);
        JeuClassique::getInstance().poserCarte(6, 0, J1);
        JeuClassique::getInstance().poserCarte(6, 0, J2);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J2);
        JeuClassique::getInstance().piocher(J1);
        JeuClassique::getInstance().piocher(J2);


        JeuClassique::getInstance().poserCarte(7, 0, J1);
        JeuClassique::getInstance().poserCarte(7, 0, J2);
        JeuClassique::getInstance().poserCarte(7, 0, J1);
        JeuClassique::getInstance().poserCarte(7, 0, J2);
        JeuClassique::getInstance().poserCarte(7, 0, J1);
        JeuClassique::getInstance().poserCarte(7, 0, J2);

        JeuClassique::getInstance().poserCarte(8, 0, J1);
        JeuClassique::getInstance().poserCarte(8, 0, J2);
        JeuClassique::getInstance().poserCarte(8, 0, J1);
        JeuClassique::getInstance().poserCarte(8, 0, J2);
        JeuClassique::getInstance().poserCarte(8, 0, J1);
        JeuClassique::getInstance().poserCarte(8, 0, J2);


        for (unsigned int i = 0; i < 9; ++i) {
            if (JeuClassique::getInstance().borneEstRevendicableParJoueur(i, J1)) {
                JeuClassique::getInstance().revendiquerBorne(i, J1);
            }
            else {
                JeuClassique::getInstance().revendiquerBorne(i, J2);
            }
        }

        cout << JeuClassique::getInstance().getGagnant().get()->getNom() << endl;
        
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

}
