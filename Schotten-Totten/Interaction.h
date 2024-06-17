#ifndef INTERACTION_H
#define INTERACTION_H

#include <iostream>
#include "Jeu.h"
#include "Regles.h"


// Classe statique, gère les input Joueur
class Interaction {
public:

    // On rend la classe statique

    Interaction() = delete;
    ~Interaction() = delete;
    
    static unsigned int demanderModeJeu();
};

#endif // INTERACTION_H