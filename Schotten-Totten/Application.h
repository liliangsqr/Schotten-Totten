#ifndef APPLICATION_H
#define APPLICATION_H

#include "JeuClassique.h"
#include "JeuTactique.h"
#include "Interaction.h"
#include "JeuClassiqueExperts.h"

// Orchestre tout le d�roulement du jeu et de l'application
// Design pattern : Fa�ade
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