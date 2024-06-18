#ifndef INTERACTION_H
#define INTERACTION_H

#include <iostream>
#include "Jeu.h"
#include "Regles.h"


// Classe statique, gère les input Joueur
class Interaction {
private :
    static unsigned int choixPlage(unsigned int min, unsigned int max);
    static bool choixTrueFalse();

public:

    // On rend la classe statique

    Interaction() = delete;
    ~Interaction() = delete;
    
    static unsigned int demanderModeJeu();
    static unsigned int choisirBorne(Jeu& jeu, const shared_ptr<Joueur>& joueur);
    static unsigned int choisirCarte(const shared_ptr<Joueur>& joueur);
    static bool joueurVeutRevendiquer();
    static unsigned int getBorneARevendiquer(Jeu& jeu);
    static bool arreterRevendication();
};

#endif // INTERACTION_H