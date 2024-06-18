#ifndef APPLICATION_H
#define APPLICATION_H

#include "JeuClassique.h"
#include "JeuTactique.h"
#include "Interaction.h"

// Orchestre tout le déroulement du jeu et de l'application
// Design pattern : Façade
class Application {
private:
    void jouerTour(Jeu& jeu, shared_ptr<Joueur>& joueur);

    void demarrerJeu(Jeu& jeu);
    void jouerPartie(Jeu& jeu);
    void terminerJeu(Jeu& jeu);


public:
    void lancerApplication();


};

#endif // APPLICATION_H