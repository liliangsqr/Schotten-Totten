#ifndef COMBINAISON_H
#define COMBINAISON_H

#include <vector>
#include <algorithm>
#include "CarteClan.h"
#include "Carte.h"
#include "Enum.h"
#include "CombinaisonType.h"
#include "Regles.h"

using namespace std;

// Représente une combinaison de cartes et est utilisée pour être comparée à une ou plusieurs autres
class Combinaison {
private:
    std::vector<Carte> cartes;


    static bool comparerCartes(const Carte& a, const Carte& b);

    bool estSuiteDeCouleur() const;

    bool estBrelan() const;

    bool estCouleur() const;

    bool estSuite() const;




public:
    unsigned int getValSomme() const;

    CombinaisonType getMeilleureCombinaison() const;

    void ajouterCarte(const Carte& carte);

    size_t getTaille() const;
};


#endif // !COMBINAISON_H
